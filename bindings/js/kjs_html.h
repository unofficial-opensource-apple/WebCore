// -*- c-basic-offset: 2 -*-
/*
 *  This file is part of the KDE libraries
 *  Copyright (C) 1999 Harri Porten (porten@kde.org)
 *  Copyright (C) 2004, 2006 Apple Computer, Inc.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef KJS_HTML_H_
#define KJS_HTML_H_

#include "JSDocument.h"
#include "JSElement.h"
#include "JSHTMLElement.h"

namespace WebCore {
    class HTMLCollection;
    class HTMLDocument;
    class HTMLElement;
    class HTMLOptionsCollection;
    class HTMLSelectElement;
    class HTMLTableCaptionElement;
    class HTMLTableSectionElement;
}

namespace KJS {

  class JSAbstractEventListener;

  KJS_DEFINE_PROTOTYPE_WITH_PROTOTYPE(JSHTMLDocumentProto, WebCore::JSDocumentProto)

  class JSHTMLDocument : public WebCore::JSDocument {
  public:
    JSHTMLDocument(ExecState*, WebCore::HTMLDocument*);
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual void put(ExecState*, const Identifier& propertyName, JSValue*, int attr = None);
    void putValueProperty(ExecState*, int token, JSValue*, int /*attr*/);
    virtual const ClassInfo* classInfo() const { return &info; }
    static const ClassInfo info;
    enum { Title, Referrer, Domain, URL, Body, Location, Cookie,
           Images, Applets, Embeds, Links, Forms, Anchors, Scripts, All, Clear, Open, Close,
           Write, WriteLn, GetElementsByName, CaptureEvents, ReleaseEvents,
           BgColor, FgColor, AlinkColor, LinkColor, VlinkColor, LastModified, Height, Width, Dir, DesignMode };
  private:
    static JSValue* namedItemGetter(ExecState*, JSObject*, const Identifier&, const PropertySlot&);
  };

  // The inheritance chain for JSHTMLElement is a bit different from other
  // classes that are "half-autogenerated". Because we return different ClassInfo structs
  // depending on the type of element, we inherit JSHTMLElement from WebCore::JSHTMLElement
  // instead of the other way around. 
  KJS_DEFINE_PROTOTYPE_WITH_PROTOTYPE(JSHTMLElementProto, WebCore::JSHTMLElementProto)

  class JSHTMLElement : public WebCore::JSHTMLElement {
  public:
    JSHTMLElement(ExecState*, WebCore::HTMLElement*);
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    JSValue* getValueProperty(ExecState*, int token) const;
    virtual void put(ExecState*, const Identifier& propertyName, JSValue*, int attr = None);
    void putValueProperty(ExecState*, int token, JSValue*, int);
    virtual UString toString(ExecState*) const;
    virtual void pushEventHandlerScope(ExecState*, ScopeChain &scope) const;
    virtual JSValue* callAsFunction(ExecState*, JSObject* thisObj, const List& args);
    virtual bool implementsCall() const;
    virtual const ClassInfo* classInfo() const;
    static const ClassInfo info;

    static const ClassInfo
      select_info, object_info, 
      embed_info, table_info, caption_info, col_info, tablesection_info, tr_info,
      tablecell_info, frameSet_info, frame_info, iFrame_info, marquee_info;

    // FIXME: Might make sense to combine this with ClassInfo some day.
    typedef JSValue* (JSHTMLElement::*GetterFunction)(ExecState*, int token) const;
    typedef void (JSHTMLElement::*SetterFunction)(ExecState*, int token, JSValue*, const WebCore::String&);
    struct Accessors { GetterFunction m_getter; SetterFunction m_setter; };
    const Accessors* accessors() const;
    static const Accessors
      select_accessors, object_accessors, embed_accessors, table_accessors,
      caption_accessors, col_accessors, tablesection_accessors, tr_accessors,
      tablecell_accessors, frameSet_accessors, frame_accessors, iFrame_accessors, marquee_accessors;

    JSValue* selectGetter(ExecState* exec, int token) const;
    void  selectSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* objectGetter(ExecState* exec, int token) const;
    void  objectSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* embedGetter(ExecState*, int token) const;
    void  embedSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* tableGetter(ExecState* exec, int token) const;
    void  tableSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* tableCaptionGetter(ExecState* exec, int token) const;
    void  tableCaptionSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* tableColGetter(ExecState* exec, int token) const;
    void  tableColSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* tableSectionGetter(ExecState* exec, int token) const;
    void  tableSectionSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* tableRowGetter(ExecState* exec, int token) const;
    void  tableRowSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* tableCellGetter(ExecState* exec, int token) const;
    void  tableCellSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* frameSetGetter(ExecState* exec, int token) const;
    void  frameSetSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* frameGetter(ExecState* exec, int token) const;
    void  frameSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* iFrameGetter(ExecState* exec, int token) const;
    void  iFrameSetter(ExecState*, int token, JSValue*, const WebCore::String&);
    JSValue* marqueeGetter(ExecState* exec, int token) const;
    void  marqueeSetter(ExecState*, int token, JSValue*, const WebCore::String&);

    enum {
           SelectAdd,
           SelectTabIndex, SelectValue, SelectSelectedIndex, SelectLength,
           SelectRemove, SelectForm, SelectBlur, SelectType, SelectOptions,
           SelectDisabled, SelectMultiple, SelectName, SelectNamedItem, SelectSize, SelectFocus,
           ObjectHspace, ObjectHeight, ObjectAlign,
           ObjectBorder, ObjectCode, ObjectType, ObjectVspace, ObjectArchive,
           ObjectDeclare, ObjectForm, ObjectCodeBase, ObjectCodeType, ObjectData,
           ObjectName, ObjectStandby, ObjectTabIndex, ObjectUseMap, ObjectWidth, ObjectContentDocument,
           EmbedAlign, EmbedHeight, EmbedName, EmbedSrc, EmbedType, EmbedWidth,
           TableSummary, TableTBodies, TableTHead, TableCellPadding,
           TableDeleteCaption, TableCreateCaption, TableCaption, TableWidth,
           TableCreateTFoot, TableAlign, TableTFoot, TableDeleteRow,
           TableCellSpacing, TableRows, TableBgColor, TableBorder, TableFrame,
           TableRules, TableCreateTHead, TableDeleteTHead, TableDeleteTFoot,
           TableInsertRow, TableCaptionAlign, TableColCh, TableColChOff,
           TableColAlign, TableColSpan, TableColVAlign, TableColWidth,
           TableSectionCh, TableSectionDeleteRow, TableSectionChOff,
           TableSectionRows, TableSectionAlign, TableSectionVAlign,
           TableSectionInsertRow, TableRowSectionRowIndex, TableRowRowIndex,
           TableRowChOff, TableRowCells, TableRowVAlign, TableRowCh,
           TableRowAlign, TableRowBgColor, TableRowDeleteCell, TableRowInsertCell,
           TableCellColSpan, TableCellNoWrap, TableCellAbbr, TableCellHeight,
           TableCellWidth, TableCellCellIndex, TableCellChOff, TableCellBgColor,
           TableCellCh, TableCellVAlign, TableCellRowSpan, TableCellHeaders,
           TableCellAlign, TableCellAxis, TableCellScope, FrameSetCols,
           FrameSetRows, FrameSrc, FrameLocation, FrameFrameBorder, FrameScrolling,
           FrameMarginWidth, FrameLongDesc, FrameMarginHeight, FrameName, FrameContentDocument, FrameContentWindow, 
           FrameNoResize, FrameWidth, FrameHeight, IFrameLongDesc, IFrameDocument, IFrameAlign,
           IFrameFrameBorder, IFrameSrc, IFrameName, IFrameHeight,
           IFrameMarginHeight, IFrameMarginWidth, IFrameScrolling, IFrameWidth, IFrameContentDocument, IFrameContentWindow,
           MarqueeStart, MarqueeStop,
           GetContext,
           ElementInnerHTML, ElementId, ElementDir, ElementLang,
           ElementClassName, ElementInnerText, ElementDocument, ElementChildren, ElementContentEditable,
           ElementIsContentEditable, ElementOuterHTML, ElementOuterText
  };
  private:
    static JSValue* selectIndexGetter(ExecState*, JSObject*, const Identifier&, const PropertySlot&);
    static JSValue* framesetNameGetter(ExecState*, JSObject*, const Identifier&, const PropertySlot&);
    static JSValue* frameWindowPropertyGetter(ExecState*, JSObject*, const Identifier&, const PropertySlot&);
    static JSValue* runtimeObjectGetter(ExecState*, JSObject*, const Identifier&, const PropertySlot&);
    static JSValue* runtimeObjectPropertyGetter(ExecState*, JSObject*, const Identifier&, const PropertySlot&);
  };

  WebCore::HTMLElement* toHTMLElement(JSValue*); // returns 0 if passed-in value is not a JSHTMLElement object
  WebCore::HTMLTableCaptionElement* toHTMLTableCaptionElement(JSValue*); // returns 0 if passed-in value is not a JSHTMLElement object for a HTMLTableCaptionElement
  WebCore::HTMLTableSectionElement* toHTMLTableSectionElement(JSValue*); // returns 0 if passed-in value is not a JSHTMLElement object for a HTMLTableSectionElement

  KJS_DEFINE_PROTOTYPE(JSHTMLCollectionProto)

  class JSHTMLCollection : public DOMObject {
  public:
    JSHTMLCollection(ExecState*, WebCore::HTMLCollection*);
    ~JSHTMLCollection();
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual JSValue* callAsFunction(ExecState*, JSObject* thisObj, const List&args);
    virtual bool implementsCall() const { return true; }
    virtual bool toBoolean(ExecState*) const { return true; }
    enum { Item, NamedItem, Tags };
    JSValue* getNamedItems(ExecState*, const Identifier& propertyName) const;
    virtual const ClassInfo* classInfo() const { return &info; }
    static const ClassInfo info;
    WebCore::HTMLCollection* impl() const { return m_impl.get(); }
  protected:
    RefPtr<WebCore::HTMLCollection> m_impl;
  private:
    static JSValue* lengthGetter(ExecState*, JSObject*, const Identifier&, const PropertySlot&);
    static JSValue* indexGetter(ExecState*, JSObject*, const Identifier&, const PropertySlot&);
    static JSValue* nameGetter(ExecState*, JSObject*, const Identifier&, const PropertySlot&);
  };

  class HTMLAllCollection : public JSHTMLCollection {
  public:
    HTMLAllCollection(ExecState* exec, WebCore::HTMLCollection* c) :
      JSHTMLCollection(exec, c) { }
    virtual bool toBoolean(ExecState*) const { return false; }
    virtual bool masqueradeAsUndefined() const { return true; }
  };
  
  ////////////////////// Image Object ////////////////////////

  class ImageConstructorImp : public DOMObject {
  public:
    ImageConstructorImp(ExecState*, WebCore::Document*);
    virtual bool implementsConstruct() const;
    virtual JSObject* construct(ExecState*, const List& args);
  private:
    RefPtr<WebCore::Document> m_doc;
  };

  JSValue* getHTMLCollection(ExecState*, WebCore::HTMLCollection*);
  JSValue* getHTMLOptionsCollection(ExecState*, WebCore::HTMLOptionsCollection*);
  JSValue* getAllHTMLCollection(ExecState*, WebCore::HTMLCollection*);

} // namespace

#endif
