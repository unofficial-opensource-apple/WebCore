/*
 * This file is part of the DOM implementation for KDE.
 *
 * (C) 1999-2003 Lars Knoll (knoll@kde.org)
 * (C) 2002-2003 Dirk Mueller (mueller@kde.org)
 * Copyright (C) 2002, 2006 Apple Computer, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef CSSFontFaceRule_H
#define CSSFontFaceRule_H

#include "CSSRule.h"
#include <wtf/RefPtr.h>

namespace WebCore {

class CSSMutableStyleDeclaration;

class CSSFontFaceRule : public CSSRule
{
public:
    CSSFontFaceRule(StyleBase* parent);
    virtual ~CSSFontFaceRule();

    CSSMutableStyleDeclaration* style() const { return m_style.get(); }

    virtual bool isFontFaceRule() { return true; }

protected:
    RefPtr<CSSMutableStyleDeclaration> m_style;
};

} // namespace

#endif
