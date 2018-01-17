// Generated by Haxe 3.4.4
#include <hxcpp.h>

#ifndef INCLUDED_lime__backend_native_NativeCFFI
#include <lime/_backend/native/NativeCFFI.h>
#endif
#ifndef INCLUDED_lime_graphics_opengl_GLObject
#include <lime/graphics/opengl/GLObject.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_def54b8cacb52d8e_3140_new,"lime.graphics.opengl.GLObject","new",0x33d200eb,"lime.graphics.opengl.GLObject.new","lime/graphics/opengl/GL.hx",3140,0xa5aa2623)
HX_LOCAL_STACK_FRAME(_hx_pos_def54b8cacb52d8e_3145_fromInt,"lime.graphics.opengl.GLObject","fromInt",0x6703afb0,"lime.graphics.opengl.GLObject.fromInt","lime/graphics/opengl/GL.hx",3145,0xa5aa2623)
namespace lime{
namespace graphics{
namespace opengl{

void GLObject_obj::__construct(int id){
            	HX_STACKFRAME(&_hx_pos_def54b8cacb52d8e_3140_new)
HXDLIN(3140)		this->id = id;
            	}

Dynamic GLObject_obj::__CreateEmpty() { return new GLObject_obj; }

void *GLObject_obj::_hx_vtable = 0;

Dynamic GLObject_obj::__Create(hx::DynamicArray inArgs)
{
	hx::ObjectPtr< GLObject_obj > _hx_result = new GLObject_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool GLObject_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x6ce04d1b;
}

 ::lime::graphics::opengl::GLObject GLObject_obj::fromInt(int type,int id){
            	HX_GC_STACKFRAME(&_hx_pos_def54b8cacb52d8e_3145_fromInt)
HXLINE(3147)		if ((id == (int)0)) {
HXLINE(3147)			return null();
            		}
HXLINE(3150)		 ::hx::Object * object = ::lime::_backend::native::NativeCFFI_obj::cffi_lime_gl_object_from_id(id,type);
HXLINE(3152)		if (hx::IsNotEq( object,hx::DynamicPtr(null()) )) {
HXLINE(3154)			return ( ( ::Dynamic)(object) );
            		}
HXLINE(3158)		object = hx::DynamicPtr( ::lime::graphics::opengl::GLObject_obj::__alloc( HX_CTX ,id));
HXLINE(3159)		::lime::_backend::native::NativeCFFI_obj::cffi_lime_gl_object_register(id,type,object);
HXLINE(3160)		return ( ( ::Dynamic)(object) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GLObject_obj,fromInt,return )


GLObject_obj::GLObject_obj()
{
}

void GLObject_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GLObject);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(refs,"refs");
	HX_MARK_END_CLASS();
}

void GLObject_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(refs,"refs");
}

hx::Val GLObject_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return hx::Val( id ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"refs") ) { return hx::Val( refs ); }
	}
	return super::__Field(inName,inCallProp);
}

bool GLObject_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"fromInt") ) { outValue = fromInt_dyn(); return true; }
	}
	return false;
}

hx::Val GLObject_obj::__SetField(const ::String &inName,const hx::Val &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"refs") ) { refs=inValue.Cast< ::Array< ::Dynamic> >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GLObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("id","\xdb","\x5b","\x00","\x00"));
	outFields->push(HX_HCSTRING("refs","\xc0","\x4f","\xa7","\x4b"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo GLObject_obj_sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(GLObject_obj,id),HX_HCSTRING("id","\xdb","\x5b","\x00","\x00")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(GLObject_obj,refs),HX_HCSTRING("refs","\xc0","\x4f","\xa7","\x4b")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *GLObject_obj_sStaticStorageInfo = 0;
#endif

static ::String GLObject_obj_sMemberFields[] = {
	HX_HCSTRING("id","\xdb","\x5b","\x00","\x00"),
	HX_HCSTRING("refs","\xc0","\x4f","\xa7","\x4b"),
	::String(null()) };

static void GLObject_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GLObject_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void GLObject_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GLObject_obj::__mClass,"__mClass");
};

#endif

hx::Class GLObject_obj::__mClass;

static ::String GLObject_obj_sStaticFields[] = {
	HX_HCSTRING("fromInt","\xa5","\xdd","\xfa","\x57"),
	::String(null())
};

void GLObject_obj::__register()
{
	hx::Object *dummy = new GLObject_obj;
	GLObject_obj::_hx_vtable = *(void **)dummy;
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("lime.graphics.opengl.GLObject","\x79","\xaf","\x16","\x07");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &GLObject_obj::__GetStatic;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = GLObject_obj_sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(GLObject_obj_sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(GLObject_obj_sMemberFields);
	__mClass->mCanCast = hx::TCanCast< GLObject_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = GLObject_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = GLObject_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = GLObject_obj_sStaticStorageInfo;
#endif
	hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
