/*
    Copyright (C) 1998 Lars Knoll (knoll@mpi-hd.mpg.de)
    Copyright (C) 2001 Dirk Mueller <mueller@kde.org>
    Copyright (C) 2006 Samuel Weinig (sam.weinig@gmail.com)
    Copyright (C) 2004, 2005, 2006, 2007 Apple Inc. All rights reserved.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef CachedImage_h
#define CachedImage_h

#include "CachedResource.h"
#include "ImageObserver.h"
#include "IntRect.h"
#include "Timer.h"
#include <wtf/Vector.h>

namespace WebCore {

class DocLoader;
class Cache;

class CachedImage : public CachedResource, public ImageObserver {
    friend class Cache;

public:
    CachedImage(const String& url);
    CachedImage(Image*);
    virtual ~CachedImage();
    
    virtual void load(DocLoader* docLoader);

    Image* image() const;

    bool canRender(float multiplier) const { return !errorOccurred() && !imageSize(multiplier).isEmpty(); }

    // These are only used for SVGImage right now
    void setImageContainerSize(const IntSize&);
    bool usesImageContainerSize() const;
    bool imageHasRelativeWidth() const;
    bool imageHasRelativeHeight() const;
    
    // Both of these methods take a zoom multiplier that can be used to increase the natural size of the image by the
    // zoom.
    IntSize imageSize(float multiplier) const;  // returns the size of the complete image.
    IntRect imageRect(float multiplier) const;  // The size of the currently decoded portion of the image.

    virtual void didAddClient(CachedResourceClient*);
    
    virtual void allClientsRemoved();
    virtual void destroyDecodedData();

    virtual void data(PassRefPtr<SharedBuffer> data, bool allDataReceived);
    virtual void error(CachedResource::Status);
    
    virtual void httpStatusCodeError() { m_httpStatusCodeErrorOccurred = true; }
    bool httpStatusCodeErrorOccurred() const { return m_httpStatusCodeErrorOccurred; }
    
    virtual bool schedule() const { return true; }

    void checkNotify();
    
    virtual bool isImage() const { return true; }
    virtual bool isManual() const { return false; }

    void clear();
    
    bool stillNeedsLoad() const { return !errorOccurred() && status() == Unknown && !isLoading(); }
    void load();

    // ImageObserver
    virtual void decodedSizeChanged(const Image* image, int delta);
    virtual void didDraw(const Image*);

    virtual bool shouldPauseAnimation(const Image*);
    virtual void animationAdvanced(const Image*);
    virtual void changedInRect(const Image*, const IntRect&);

    virtual bool shouldDecodeFrame(const Image* image, const IntSize& frameSize);

#if ENABLE(DISK_IMAGE_CACHE)
    virtual bool canUseDiskImageCache() const;
    virtual void useDiskImageCache();
#endif

private:
    void createImage();
    size_t maximumDecodedImageSize();
    // If not null, changeRect is the changed part of the image.
    void notifyObservers(const IntRect* changeRect = 0);
    void decodedDataDeletionTimerFired(Timer<CachedImage>*);
    virtual PurgePriority purgePriority() const { return PurgeFirst; }

    RefPtr<Image> m_image;
    Timer<CachedImage> m_decodedDataDeletionTimer;
    bool m_httpStatusCodeErrorOccurred;

private:
    bool checkOutOfMemory();
};

class CachedImageManual : public CachedImage
{
public:
    CachedImageManual(const String&, Image*);
    virtual ~CachedImageManual();
    void addFakeClient() { addClient(m_fakeClient); }
    void removeFakeClient() { removeClient(m_fakeClient); }
    virtual bool isManual() const { return true; }

private:
    CachedResourceClient* m_fakeClient;
};

}

#endif
