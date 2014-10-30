/*
 * Copyright (C) 2004, 2006, 2007 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include "config.h"
#include "RenderHTMLCanvas.h"

#include "CanvasRenderingContext.h"
#include "Document.h"
#include "Frame.h"
#include "FrameView.h"
#include "GraphicsContext.h"
#include "HTMLCanvasElement.h"
#include "HTMLNames.h"
#include "Page.h"
#include "PaintInfo.h"
#include "RenderView.h"

namespace WebCore {

using namespace HTMLNames;

RenderHTMLCanvas::RenderHTMLCanvas(HTMLCanvasElement& element, PassRef<RenderStyle> style)
    : RenderReplaced(element, WTF::move(style), element.size())
{
    // Actual size is not known yet, report the default intrinsic size.
    view().frameView().incrementVisuallyNonEmptyPixelCount(roundedIntSize(intrinsicSize()));
}

HTMLCanvasElement& RenderHTMLCanvas::canvasElement() const
{
    return toHTMLCanvasElement(nodeForNonAnonymous());
}

bool RenderHTMLCanvas::requiresLayer() const
{
    if (RenderReplaced::requiresLayer())
        return true;

    if (CanvasRenderingContext* context = canvasElement().renderingContext())
        return context->isAccelerated();

    return false;
}

void RenderHTMLCanvas::paintReplaced(PaintInfo& paintInfo, const LayoutPoint& paintOffset)
{
    GraphicsContext* context = paintInfo.context;

    LayoutRect contentRect = contentBoxRect();
    contentRect.moveBy(paintOffset);
    LayoutRect paintRect = replacedContentRect(intrinsicSize());
    paintRect.moveBy(paintOffset);

    // Not allowed to overflow the content box.
    bool clip = !contentRect.contains(paintRect);
    GraphicsContextStateSaver stateSaver(*paintInfo.context, clip);
    if (clip)
        paintInfo.context->clip(pixelSnappedIntRect(contentRect));

    if (Page* page = frame().page()) {
        if (paintInfo.phase == PaintPhaseForeground)
            page->addRelevantRepaintedObject(this, intersection(paintRect, contentRect));
    }

    bool useLowQualityScale = style().imageRendering() == ImageRenderingCrispEdges || style().imageRendering() == ImageRenderingOptimizeSpeed;
    canvasElement().paint(context, paintRect, useLowQualityScale);
}

void RenderHTMLCanvas::canvasSizeChanged()
{
    IntSize canvasSize = canvasElement().size();
    LayoutSize zoomedSize(canvasSize.width() * style().effectiveZoom(), canvasSize.height() * style().effectiveZoom());

    if (zoomedSize == intrinsicSize())
        return;

    setIntrinsicSize(zoomedSize);

    if (!parent())
        return;

    if (!preferredLogicalWidthsDirty())
        setPreferredLogicalWidthsDirty(true);

    LayoutSize oldSize = size();
    updateLogicalWidth();
    updateLogicalHeight();
    if (oldSize == size())
        return;

    if (!selfNeedsLayout())
        setNeedsLayout();
}

} // namespace WebCore
