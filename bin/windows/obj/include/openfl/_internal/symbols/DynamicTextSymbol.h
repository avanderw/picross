// Generated by Haxe 3.4.4
#ifndef INCLUDED_openfl__internal_symbols_DynamicTextSymbol
#define INCLUDED_openfl__internal_symbols_DynamicTextSymbol

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_openfl__internal_symbols_SWFSymbol
#include <openfl/_internal/symbols/SWFSymbol.h>
#endif
HX_DECLARE_CLASS3(openfl,_internal,swf,SWFLite)
HX_DECLARE_CLASS3(openfl,_internal,symbols,DynamicTextSymbol)
HX_DECLARE_CLASS3(openfl,_internal,symbols,SWFSymbol)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)

namespace openfl{
namespace _internal{
namespace symbols{


class HXCPP_CLASS_ATTRIBUTES DynamicTextSymbol_obj : public  ::openfl::_internal::symbols::SWFSymbol_obj
{
	public:
		typedef  ::openfl::_internal::symbols::SWFSymbol_obj super;
		typedef DynamicTextSymbol_obj OBJ_;
		DynamicTextSymbol_obj();

	public:
		enum { _hx_ClassId = 0x00795451 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="openfl._internal.symbols.DynamicTextSymbol")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return hx::Object::operator new(inSize+extra,true,"openfl._internal.symbols.DynamicTextSymbol"); }
		static hx::ObjectPtr< DynamicTextSymbol_obj > __new();
		static hx::ObjectPtr< DynamicTextSymbol_obj > __alloc(hx::Ctx *_hx_ctx);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~DynamicTextSymbol_obj();

		HX_DO_RTTI_ALL;
		hx::Val __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		hx::Val __SetField(const ::String &inString,const hx::Val &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_HCSTRING("DynamicTextSymbol","\x24","\x88","\x4e","\x53"); }

		::String align;
		bool border;
		 ::Dynamic color;
		int fontHeight;
		int fontID;
		::String fontName;
		Float height;
		bool html;
		 ::Dynamic indent;
		bool input;
		 ::Dynamic leading;
		 ::Dynamic leftMargin;
		bool multiline;
		bool password;
		 ::Dynamic rightMargin;
		bool selectable;
		::String text;
		Float width;
		bool wordWrap;
		Float x;
		Float y;
		 ::openfl::display::DisplayObject _hx___createObject( ::openfl::_internal::swf::SWFLite swf);

};

} // end namespace openfl
} // end namespace _internal
} // end namespace symbols

#endif /* INCLUDED_openfl__internal_symbols_DynamicTextSymbol */ 
