// Generated by Haxe 3.4.4
#ifndef INCLUDED_openfl__internal_renderer_AbstractBlendModeManager
#define INCLUDED_openfl__internal_renderer_AbstractBlendModeManager

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_STACK_FRAME(_hx_pos_cb23a2f94d762c95_15_new)
HX_DECLARE_CLASS3(openfl,_internal,renderer,AbstractBlendModeManager)

namespace openfl{
namespace _internal{
namespace renderer{


class HXCPP_CLASS_ATTRIBUTES AbstractBlendModeManager_obj : public hx::Object
{
	public:
		typedef hx::Object super;
		typedef AbstractBlendModeManager_obj OBJ_;
		AbstractBlendModeManager_obj();

	public:
		enum { _hx_ClassId = 0x0310e86a };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="openfl._internal.renderer.AbstractBlendModeManager")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return hx::Object::operator new(inSize+extra,false,"openfl._internal.renderer.AbstractBlendModeManager"); }

		hx::ObjectPtr< AbstractBlendModeManager_obj > __new() {
			hx::ObjectPtr< AbstractBlendModeManager_obj > __this = new AbstractBlendModeManager_obj();
			__this->__construct();
			return __this;
		}

		static hx::ObjectPtr< AbstractBlendModeManager_obj > __alloc(hx::Ctx *_hx_ctx) {
			AbstractBlendModeManager_obj *__this = (AbstractBlendModeManager_obj*)(hx::Ctx::alloc(_hx_ctx, sizeof(AbstractBlendModeManager_obj), false, "openfl._internal.renderer.AbstractBlendModeManager"));
			*(void **)__this = AbstractBlendModeManager_obj::_hx_vtable;
{
            	HX_STACKFRAME(&_hx_pos_cb23a2f94d762c95_15_new)
            	}
		
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AbstractBlendModeManager_obj();

		HX_DO_RTTI_ALL;
		hx::Val __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_HCSTRING("AbstractBlendModeManager","\x9b","\xc5","\x89","\x9b"); }

		virtual void setBlendMode( ::Dynamic blendMode);
		::Dynamic setBlendMode_dyn();

};

} // end namespace openfl
} // end namespace _internal
} // end namespace renderer

#endif /* INCLUDED_openfl__internal_renderer_AbstractBlendModeManager */ 
