/*
 * Copyright (C) 2008, Apple Inc. All rights reserved.
 *
 * Permission is granted by Apple to use this file to the extent
 * necessary to relink with LGPL WebKit files.
 *
 * No license or rights are granted by Apple expressly or by
 * implication, estoppel, or otherwise, to Apple patents and
 * trademarks. For the sake of clarity, no license or rights are
 * granted by Apple expressly or by implication, estoppel, or otherwise,
 * under any Apple patents, copyrights and trademarks to underlying
 * implementations of any application programming interfaces (APIs)
 * or to any functionality that is invoked by calling any API.
 */

#ifndef JSTouchListConstructor_h
#define JSTouchListConstructor_h


#include "JSDOMBinding.h"
#include "JSDocument.h"

namespace WebCore {

class JSTouchListConstructor : public DOMConstructorWithDocument {
public:
    typedef DOMConstructorWithDocument Base;

    static JSTouchListConstructor* create(JSC::ExecState* exec, JSC::Structure* structure, JSDOMGlobalObject* globalObject)
    {
        JSTouchListConstructor* constructor = new (JSC::allocateCell<JSTouchListConstructor>(*exec->heap())) JSTouchListConstructor(structure, globalObject);
        constructor->finishCreation(exec, globalObject);
        return constructor;
    }

    static JSC::Structure* createStructure(JSC::JSGlobalData& globalData, JSC::JSGlobalObject* globalObject, JSC::JSValue prototype)
    {
        return JSC::Structure::create(globalData, globalObject, prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags), &s_info);
    }

    static const JSC::ClassInfo s_info;

private:
    JSTouchListConstructor(JSC::Structure*, JSDOMGlobalObject*);
    void finishCreation(JSC::ExecState*, JSDOMGlobalObject*);
    static JSC::ConstructType getConstructData(JSC::JSCell*, JSC::ConstructData&);
};

}


#endif // JSTouchListConstructor_h