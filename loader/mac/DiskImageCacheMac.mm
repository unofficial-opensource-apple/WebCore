/*
 * Copyright (C) 2010 Apple Inc. All rights reserved.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "DiskImageCache.h"

#if ENABLE(DISK_IMAGE_CACHE)

#include "FileSystem.h"
#include "PlatformString.h"

// FIXME: Move this to a generic place, like FileSystem.h and FileSystemIPhone.mm?
// These would probably need to be made more robust. However, then they could be
// used elsewhere, such as QuickLook code where this was pulled from.

namespace WebCore {

String DiskImageCache::temporaryDirectory()
{
    NSString *tempDiskCacheDirectory = createTemporaryDirectory(@"DiskImageCache");
    if (!tempDiskCacheDirectory)
        LOG_ERROR("DiskImageCache: Could not create a temporary directory.");

    return tempDiskCacheDirectory;
}

String DiskImageCache::temporaryFile()
{
    NSString *tempFile = createTemporaryFile(m_cacheDirectory, @"tmp");
    if (!tempFile)
        LOG_ERROR("DiskImageCache: Could not create a temporary file.");

    return tempFile;
}

} // namespace WebCore

#endif // DISK_IMAGE_CACHE
