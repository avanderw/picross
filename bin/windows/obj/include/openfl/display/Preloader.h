// Generated by Haxe 3.4.4
#ifndef INCLUDED_openfl_display_Preloader
#define INCLUDED_openfl_display_Preloader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#ifndef INCLUDED_lime_app_Preloader
#include <lime/app/Preloader.h>
#endif
HX_DECLARE_CLASS2(lime,app,Preloader)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Preloader)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)

namespace openfl{
namespace display{


class HXCPP_CLASS_ATTRIBUTES Preloader_obj : public  ::lime::app::Preloader_obj
{
	public:
		typedef  ::lime::app::Preloader_obj super;
		typedef Preloader_obj OBJ_;
		Preloader_obj();

	public:
		enum { _hx_ClassId = 0x0d31c910 };

		void __construct( ::openfl::display::Sprite display);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="openfl.display.Preloader")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return hx::Object::operator new(inSize+extra,true,"openfl.display.Preloader"); }
		static hx::ObjectPtr< Preloader_obj > __new( ::openfl::display::Sprite display);
		static hx::ObjectPtr< Preloader_obj > __alloc(hx::Ctx *_hx_ctx, ::openfl::display::Sprite display);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Preloader_obj();

		HX_DO_RTTI_ALL;
		hx::Val __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		hx::Val __SetField(const ::String &inString,const hx::Val &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_HCSTRING("Preloader","\x56","\xc4","\x4e","\x24"); }

		 ::openfl::display::Sprite display;
		bool ready;
		void start();

		void update(int loaded,int total);

		void display_onUnload( ::openfl::events::Event event);
		::Dynamic display_onUnload_dyn();

};

} // end namespace openfl
} // end namespace display

#endif /* INCLUDED_openfl_display_Preloader */ 
