// Generated by Haxe 3.4.4
#ifndef INCLUDED_openfl_net_URLVariables
#define INCLUDED_openfl_net_URLVariables

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,net,URLVariables)

namespace openfl{
namespace net{


class HXCPP_CLASS_ATTRIBUTES URLVariables_obj : public hx::Object
{
	public:
		typedef hx::Object super;
		typedef URLVariables_obj OBJ_;
		URLVariables_obj();

	public:
		enum { _hx_ClassId = 0x1a9610f5 };

		void __construct(::String source);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="openfl.net.URLVariables")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return hx::Object::operator new(inSize+extra,true,"openfl.net.URLVariables"); }
		static hx::ObjectPtr< URLVariables_obj > __new(::String source);
		static hx::ObjectPtr< URLVariables_obj > __alloc(hx::Ctx *_hx_ctx,::String source);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~URLVariables_obj();

		HX_DO_RTTI_ALL;
		hx::Val __Field(const ::String &inString, hx::PropertyAccess inCallProp);
		hx::Val __SetField(const ::String &inString,const hx::Val &inValue, hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		HX_DECLARE_IMPLEMENT_DYNAMIC;
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_HCSTRING("URLVariables","\x68","\x19","\x1f","\x56"); }

		void decode(::String source);
		::Dynamic decode_dyn();

		virtual ::String toString();
		::Dynamic toString_dyn();

};

} // end namespace openfl
} // end namespace net

#endif /* INCLUDED_openfl_net_URLVariables */ 
