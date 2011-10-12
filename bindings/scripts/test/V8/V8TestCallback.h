/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

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
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#if ENABLE(DATABASE)

#ifndef V8TestCallback_h
#define V8TestCallback_h

#include "ActiveDOMCallback.h"
#include "TestCallback.h"
#include "WorldContextHandle.h"
#include <v8.h>
#include <wtf/Forward.h>

namespace WebCore {

class ScriptExecutionContext;

class V8TestCallback : public TestCallback, public ActiveDOMCallback {
public:
    static PassRefPtr<V8TestCallback> create(v8::Local<v8::Value> value, ScriptExecutionContext* context)
    {
        ASSERT(value->IsObject());
        ASSERT(context);
        return adoptRef(new V8TestCallback(value->ToObject(), context));
    }

    virtual ~V8TestCallback();

    // Functions
    virtual bool callbackWithNoParam();
    virtual bool callbackWithClass1Param(Class1* class1Param);
    virtual bool callbackWithClass2Param(Class2* class2Param, const String& strArg);
    COMPILE_ASSERT(false)    virtual int callbackWithNonBoolReturnType(Class3* class3Param);
    virtual int customCallback(Class5* class5Param, Class6* class6Param);
    virtual bool callbackWithStringList(PassRefPtr<DOMStringList> listParam);

private:
    V8TestCallback(v8::Local<v8::Object>, ScriptExecutionContext*);

    v8::Persistent<v8::Object> m_callback;
    WorldContextHandle m_worldContext;
};

}

#endif // V8TestCallback_h

#endif // ENABLE(DATABASE)
