/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DeviceOrientation_h
#define DeviceOrientation_h

#include <wtf/PassRefPtr.h>
#include <wtf/RefCounted.h>

namespace WebCore {

class DeviceOrientation : public RefCounted<DeviceOrientation> {
public:
    static PassRefPtr<DeviceOrientation> create();
    static PassRefPtr<DeviceOrientation> create(bool canProvideAlpha, double alpha, bool canProvideBeta, double beta, bool canProvideGamma, double gamma, bool canProvideCompassHeading, double compassHeading, bool canProvideCompassAccuracy, double compassAccuracy);

    double alpha() const;
    double beta() const;
    double gamma() const;
    bool absolute() const;
    bool canProvideAlpha() const;
    bool canProvideBeta() const;
    bool canProvideGamma() const;
    bool canProvideAbsolute() const;

    double compassHeading() const;
    double compassAccuracy() const;
    bool canProvideCompassHeading() const;
    bool canProvideCompassAccuracy() const;

private:
    DeviceOrientation();
    DeviceOrientation(bool canProvideAlpha, double alpha, bool canProvideBeta, double beta, bool canProvideGamma, double gamma, bool canProvideCompassHeading, double compassHeading, bool canProvideCompassAccuracy, double compassAccuracy);

    bool m_canProvideAlpha;
    bool m_canProvideBeta;
    bool m_canProvideGamma;
    double m_alpha;
    double m_beta;
    double m_gamma;

    bool m_canProvideCompassHeading;
    bool m_canProvideCompassAccuracy;
    double m_compassHeading;
    double m_compassAccuracy;
};

} // namespace WebCore

#endif // DeviceOrientation_h
