/*
 * Copyright (C) 2004, 2005, 2006 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include "config.h"
#include "BitmapImage.h"

#if USE(CG)

#include "AffineTransform.h"
#include "FloatConversion.h"
#include "FloatRect.h"
#include "GraphicsContextCG.h"
#include "ImageObserver.h"
#include "PDFDocumentImage.h"
#include "PlatformString.h"
#include <CoreGraphics/CoreGraphics.h>
#include <CoreFoundation/CFArray.h>
#include <wtf/RetainPtr.h>

#if PLATFORM(MAC) || PLATFORM(CHROMIUM)
#include "WebCoreSystemInterface.h"
#endif

#if PLATFORM(WIN)
#include <WebKitSystemInterface/WebKitSystemInterface.h>
#endif

namespace WebCore {

bool FrameData::clear(bool clearMetadata)
{
    if (clearMetadata)
        m_haveMetadata = false;

    m_orientation = DefaultImageOrientation;

    m_bytes = 0;
    m_scale = 1.0f;
    m_haveInfo = false;

    if (m_frame) {
        CGImageRelease(m_frame);
        m_frame = 0;
        return true;
    }
    return false;
}

// ================================================
// Image Class
// ================================================

BitmapImage::BitmapImage(CGImageRef cgImage, ImageObserver* observer)
    : Image(observer)
    , m_currentFrame(0)
    , m_frames(0)
    , m_frameTimer(0)
    , m_repetitionCount(cAnimationNone)
    , m_repetitionCountStatus(Unknown)
    , m_repetitionsComplete(0)
    , m_decodedSize(0)
    , m_frameCount(1)
    , m_isSolidColor(false)
    , m_checkedForSolidColor(false)
    , m_animationFinished(true)
    , m_allDataReceived(true)
    , m_haveSize(true)
    , m_sizeAvailable(true)
    , m_haveFrameCount(true)
{
    initPlatformData();
    
    CGFloat width = CGImageGetWidth(cgImage);
    CGFloat height = CGImageGetHeight(cgImage);
    m_decodedSize = width * height * 4;
    m_size = IntSize(width, height);

    // Since we don't have a decoder, we can't figure out the image orientation.
    // Set m_sizeRespectingOrientation to be the same as m_size so it's not 0x0.
    m_sizeRespectingOrientation = IntSize(width, height);

    m_originalSize = IntSize(width, height);
    m_originalSizeRespectingOrientation = IntSize(width, height);

    m_frames.grow(1);
    m_frames[0].m_frame = cgImage;
    m_frames[0].m_hasAlpha = true;
    m_frames[0].m_haveMetadata = true;
    m_frames[0].m_scale = 1.0f;

    checkForSolidColor();
}

// Drawing Routines

void BitmapImage::checkForSolidColor()
{
    m_checkedForSolidColor = true;
    if (frameCount() > 1) {
        m_isSolidColor = false;
        return;
    }

    // checkForSolidColor() may be called from frameAtIndex(). On iOS frameAtIndex() gets passed a scaleHint
    // argument which it uses to tell CG to create a scaled down image. Since we don't know the scaleHint
    // here, if we call frameAtIndex() again, we would pass it the default scale of 1 and would end up
    // recreating the image. So we do a quick check and call frameAtIndex(0) only if we haven't yet created an
    // image.
    CGImageRef image = 0;
    if (m_frames.size())
        image = m_frames[0].m_frame;

    if (!image)
        image = frameAtIndex(0);
    
    // Currently we only check for solid color in the important special case of a 1x1 image.
    if (image && CGImageGetWidth(image) == 1 && CGImageGetHeight(image) == 1) {
        // <rdar://problem/5106514> Floating-point contexts are not supported on iPhone
        unsigned char pixel[4] = {0, 0, 0, 0}; // RGBA
        RetainPtr<CGContextRef> bmap(AdoptCF, CGBitmapContextCreate(pixel, 1, 1, 8, sizeof(pixel), deviceRGBColorSpaceRef(),
            kCGImageAlphaPremultipliedLast));
        if (!bmap)
            return;
        GraphicsContext(bmap.get()).setCompositeOperation(CompositeCopy);
        CGRect dst = { {0, 0}, {1, 1} };
        CGContextDrawImage(bmap.get(), dst, image);
        if (pixel[3] == 0)
            m_solidColor = Color(0, 0, 0, 0);
        else
            m_solidColor = Color((int)pixel[0], (int)pixel[1], (int)pixel[2], (int)pixel[3]);
        m_isSolidColor = true;
    }
}

RetainPtr<CGImageRef> Image::imageWithColorSpace(CGImageRef originalImage, ColorSpace colorSpace)
{
    CGColorSpaceRef originalColorSpace = CGImageGetColorSpace(originalImage);

    // If the image already has a (non-device) color space, we don't want to
    // override it, so return.
    if (!originalColorSpace || !CFEqual(originalColorSpace, deviceRGBColorSpaceRef()))
        return originalImage;

    switch (colorSpace) {
    case ColorSpaceDeviceRGB:
        return originalImage;
    case ColorSpaceSRGB:
        return RetainPtr<CGImageRef>(AdoptCF, CGImageCreateCopyWithColorSpace(originalImage, sRGBColorSpaceRef()));
    case ColorSpaceLinearRGB:
        return RetainPtr<CGImageRef>(AdoptCF, CGImageCreateCopyWithColorSpace(originalImage, linearRGBColorSpaceRef()));
    }

    ASSERT_NOT_REACHED();
    return originalImage;
}

CGImageRef BitmapImage::getCGImageRef()
{
    return frameAtIndex(0);
}

CGImageRef BitmapImage::getFirstCGImageRefOfSize(const IntSize& size)
{
    size_t count = frameCount();
    for (size_t i = 0; i < count; ++i) {
        CGImageRef cgImage = frameAtIndex(i);
        if (cgImage && IntSize(CGImageGetWidth(cgImage), CGImageGetHeight(cgImage)) == size)
            return cgImage;
    }

    // Fallback to the default CGImageRef if we can't find the right size
    return getCGImageRef();
}

RetainPtr<CFArrayRef> BitmapImage::getCGImageArray()
{
    size_t count = frameCount();
    if (!count)
        return 0;
    
    CFMutableArrayRef array = CFArrayCreateMutable(NULL, count, &kCFTypeArrayCallBacks);
    for (size_t i = 0; i < count; ++i) {
        if (CGImageRef currFrame = frameAtIndex(i))
            CFArrayAppendValue(array, currFrame);
    }
    return RetainPtr<CFArrayRef>(AdoptCF, array);
}

void BitmapImage::draw(GraphicsContext* ctx, const FloatRect& dstRect, const FloatRect& srcRect, ColorSpace styleColorSpace, CompositeOperator op)
{
    draw(ctx, dstRect, srcRect, styleColorSpace, op, DoNotRespectImageOrientation);
}

void BitmapImage::draw(GraphicsContext* ctxt, const FloatRect& destRect, const FloatRect& srcRect, ColorSpace styleColorSpace, CompositeOperator compositeOp, RespectImageOrientationEnum shouldRespectImageOrientation)
{
    startAnimation(false);
    
    CGRect transformedDstRect = CGRectApplyAffineTransform(destRect, CGContextGetCTM(ctxt->platformContext()));
    RetainPtr<CGImageRef> image;
    // Never use subsampled images for drawing into PDF contexts.
    if (CGContextGetType(ctxt->platformContext()) == kCGContextTypePDF)
        image.adoptCF(copyUnscaledFrameAtIndex(m_currentFrame));
    else
        image = frameAtIndex(m_currentFrame, std::min<float>(1.0f, std::max(transformedDstRect.size.width  / srcRect.width(), transformedDstRect.size.height / srcRect.height())));
    if (!image) // If it's too early we won't have an image yet.
        return;
    
    if (mayFillWithSolidColor()) {
        fillWithSolidColor(ctxt, destRect, solidColor(), styleColorSpace, compositeOp);
        return;
    }

    float scale = m_frames[m_currentFrame].m_scale;
    FloatSize selfSize = currentFrameSize();
    ImageOrientation orientation = DefaultImageOrientation;

    if (shouldRespectImageOrientation == RespectImageOrientation)
        orientation = frameOrientationAtIndex(m_currentFrame);

    ctxt->drawNativeImage(image.get(), selfSize, styleColorSpace, destRect, srcRect,
        scale,
        compositeOp, orientation
        );

    if (imageObserver())
        imageObserver()->didDraw(this);
}

static void drawPatternCallback(void* info, CGContextRef context)
{
    CGImageRef image = (CGImageRef)info;
    CGFloat h = CGImageGetHeight(image);
    CGContextScaleCTM (context, 1, -1);
    CGContextTranslateCTM (context, 0, -h);
    CGContextDrawImage(context, GraphicsContext(context).roundToDevicePixels(FloatRect(0, 0, CGImageGetWidth(image), h)), image);
}

void Image::drawPattern(GraphicsContext* ctxt, const FloatRect& tileRect, const AffineTransform& patternTransform,
                        const FloatPoint& phase, ColorSpace styleColorSpace, CompositeOperator op, const FloatRect& destRect)
{
    if (!nativeImageForCurrentFrame())
        return;

    ASSERT(patternTransform.isInvertible());
    if (!patternTransform.isInvertible())
        // Avoid a hang under CGContextDrawTiledImage on release builds.
        return;

    CGContextRef context = ctxt->platformContext();
    GraphicsContextStateSaver stateSaver(*ctxt);
    CGContextClipToRect(context, destRect);
    ctxt->setCompositeOperation(op);
    CGContextTranslateCTM(context, destRect.x(), destRect.y() + destRect.height());
    CGContextScaleCTM(context, 1, -1);
    
    // Compute the scaled tile size.
    float scaledTileHeight = tileRect.height() * narrowPrecisionToFloat(patternTransform.d());
    
    // We have to adjust the phase to deal with the fact we're in Cartesian space now (with the bottom left corner of destRect being
    // the origin).
    float adjustedX = phase.x() - destRect.x() + tileRect.x() * narrowPrecisionToFloat(patternTransform.a()); // We translated the context so that destRect.x() is the origin, so subtract it out.
    float adjustedY = destRect.height() - (phase.y() - destRect.y() + tileRect.y() * narrowPrecisionToFloat(patternTransform.d()) + scaledTileHeight);

    CGImageRef tileImage = nativeImageForCurrentFrame();
    float h = CGImageGetHeight(tileImage);

    RetainPtr<CGImageRef> subImage;
    if (tileRect.size() == size())
        subImage = tileImage;
    else {
        // Copying a sub-image out of a partially-decoded image stops the decoding of the original image. It should never happen
        // because sub-images are only used for border-image, which only renders when the image is fully decoded.
        ASSERT(h == height());
        subImage.adoptCF(CGImageCreateWithImageInRect(tileImage, tileRect));
    }

    // Adjust the color space.
    subImage = Image::imageWithColorSpace(subImage.get(), styleColorSpace);
    
    // Leopard has an optimized call for the tiling of image patterns, but we can only use it if the image has been decoded enough that
    // its buffer is the same size as the overall image.  Because a partially decoded CGImageRef with a smaller width or height than the
    // overall image buffer needs to tile with "gaps", we can't use the optimized tiling call in that case.
    // FIXME: We cannot use CGContextDrawTiledImage with scaled tiles on Leopard, because it suffers from rounding errors.  Snow Leopard is ok.
    float scaledTileWidth = tileRect.width() * narrowPrecisionToFloat(patternTransform.a());
    float w = CGImageGetWidth(tileImage);
#ifdef BUILDING_ON_LEOPARD
    if (w == size().width() && h == size().height() && scaledTileWidth == tileRect.width() && scaledTileHeight == tileRect.height())
#else
    if (w == size().width() && h == size().height())
#endif
        CGContextDrawTiledImage(context, FloatRect(adjustedX, adjustedY, scaledTileWidth, scaledTileHeight), subImage.get());
    else {

    // On Leopard and newer, this code now only runs for partially decoded images whose buffers do not yet match the overall size of the image.
    static const CGPatternCallbacks patternCallbacks = { 0, drawPatternCallback, NULL };
    CGAffineTransform matrix = CGAffineTransformMake(narrowPrecisionToCGFloat(patternTransform.a()), 0, 0, narrowPrecisionToCGFloat(patternTransform.d()), adjustedX, adjustedY);
    matrix = CGAffineTransformConcat(matrix, CGContextGetCTM(context));
    // The top of a partially-decoded image is drawn at the bottom of the tile. Map it to the top.
    matrix = CGAffineTransformTranslate(matrix, 0, size().height() - h);
    matrix = CGAffineTransformScale(matrix, 1, -1);
    matrix = CGAffineTransformTranslate(matrix, 0, -h);
    RetainPtr<CGPatternRef> pattern(AdoptCF, CGPatternCreate(subImage.get(), CGRectMake(0, 0, tileRect.width(), tileRect.height()),
                                             matrix, tileRect.width(), tileRect.height(), 
                                             kCGPatternTilingConstantSpacing, true, &patternCallbacks));
    if (!pattern)
        return;

    RetainPtr<CGColorSpaceRef> patternSpace(AdoptCF, CGColorSpaceCreatePattern(0));
    
    CGFloat alpha = 1;
    RetainPtr<CGColorRef> color(AdoptCF, CGColorCreateWithPattern(patternSpace.get(), pattern.get(), &alpha));
    CGContextSetFillColorSpace(context, patternSpace.get());

    // FIXME: Really want a public API for this.  It is just CGContextSetBaseCTM(context, CGAffineTransformIdentiy).
    wkSetBaseCTM(context, CGAffineTransformIdentity);
    CGContextSetPatternPhase(context, CGSizeZero);

    CGContextSetFillColorWithColor(context, color.get());
    CGContextFillRect(context, CGContextGetClipBoundingBox(context));

    }

    stateSaver.restore();

    if (imageObserver())
        imageObserver()->didDraw(this);
}

NativeImagePtr BitmapImage::copyUnscaledFrameAtIndex(size_t index)
{
    if (index >= frameCount())
        return 0;

    if (index >= m_frames.size() || !m_frames[index].m_frame)
        cacheFrame(index, 1);

    if (m_frames[index].m_scale == 1 && !m_source.isSubsampled())
        return CGImageRetain(m_frames[index].m_frame);

    float ignoredScale;
    ssize_t ignoredBytes;
    return m_source.createFrameAtIndex(index, std::numeric_limits<float>::infinity(), &ignoredScale, &ignoredBytes);
}

}

#endif // USE(CG)
