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
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef JSTestSerializedScriptValueInterface_h
#define JSTestSerializedScriptValueInterface_h

#if ENABLE(Condition1) || ENABLE(Condition2)

#include "JSDOMWrapper.h"
#include "TestSerializedScriptValueInterface.h"

namespace WebCore {

class JSTestSerializedScriptValueInterface : public JSDOMWrapper {
public:
    typedef JSDOMWrapper Base;
    static JSTestSerializedScriptValueInterface* create(JSC::Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<TestSerializedScriptValueInterface> impl)
    {
        JSTestSerializedScriptValueInterface* ptr = new (NotNull, JSC::allocateCell<JSTestSerializedScriptValueInterface>(globalObject->vm().heap)) JSTestSerializedScriptValueInterface(structure, globalObject, impl);
        ptr->finishCreation(globalObject->vm());
        return ptr;
    }

    static JSC::JSObject* createPrototype(JSC::VM&, JSC::JSGlobalObject*);
    static JSC::JSObject* getPrototype(JSC::VM&, JSC::JSGlobalObject*);
    static void destroy(JSC::JSCell*);
    ~JSTestSerializedScriptValueInterface();

    DECLARE_INFO;

    static JSC::Structure* createStructure(JSC::VM& vm, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(vm, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), info());
    }

    static JSC::JSValue getConstructor(JSC::VM&, JSC::JSGlobalObject*);
    JSC::WriteBarrier<JSC::Unknown> m_cachedValue;
    JSC::WriteBarrier<JSC::Unknown> m_cachedReadonlyValue;
    static void visitChildren(JSCell*, JSC::SlotVisitor&);

    TestSerializedScriptValueInterface& impl() const { return *m_impl; }
    void releaseImpl() { m_impl->deref(); m_impl = 0; }

    void releaseImplIfNotNull()
    {
        if (m_impl) {
            m_impl->deref();
            m_impl = 0;
        }
    }

private:
    TestSerializedScriptValueInterface* m_impl;
protected:
    JSTestSerializedScriptValueInterface(JSC::Structure*, JSDOMGlobalObject*, PassRefPtr<TestSerializedScriptValueInterface>);

    void finishCreation(JSC::VM& vm)
    {
        Base::finishCreation(vm);
        ASSERT(inherits(info()));
    }

    static const unsigned StructureFlags = JSC::OverridesVisitChildren | Base::StructureFlags;
};

class JSTestSerializedScriptValueInterfaceOwner : public JSC::WeakHandleOwner {
public:
    virtual bool isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown>, void* context, JSC::SlotVisitor&);
    virtual void finalize(JSC::Handle<JSC::Unknown>, void* context);
};

inline JSC::WeakHandleOwner* wrapperOwner(DOMWrapperWorld&, TestSerializedScriptValueInterface*)
{
    DEPRECATED_DEFINE_STATIC_LOCAL(JSTestSerializedScriptValueInterfaceOwner, jsTestSerializedScriptValueInterfaceOwner, ());
    return &jsTestSerializedScriptValueInterfaceOwner;
}

inline void* wrapperContext(DOMWrapperWorld& world, TestSerializedScriptValueInterface*)
{
    return &world;
}

JSC::JSValue toJS(JSC::ExecState*, JSDOMGlobalObject*, TestSerializedScriptValueInterface*);
TestSerializedScriptValueInterface* toTestSerializedScriptValueInterface(JSC::JSValue);


} // namespace WebCore

#endif // ENABLE(Condition1) || ENABLE(Condition2)

#endif
