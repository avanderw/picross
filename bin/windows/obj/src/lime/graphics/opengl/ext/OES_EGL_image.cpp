// Generated by Haxe 3.4.4
#include <hxcpp.h>

#ifndef INCLUDED_lime_graphics_opengl_ext_OES_EGL_image
#include <lime/graphics/opengl/ext/OES_EGL_image.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_8d0895ed1f8ffb08_7_new,"lime.graphics.opengl.ext.OES_EGL_image","new",0x6c1a8a54,"lime.graphics.opengl.ext.OES_EGL_image.new","lime/graphics/opengl/ext/OES_EGL_image.hx",7,0x022e683e)
namespace lime{
namespace graphics{
namespace opengl{
namespace ext{

void OES_EGL_image_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_8d0895ed1f8ffb08_7_new)
            	}

Dynamic OES_EGL_image_obj::__CreateEmpty() { return new OES_EGL_image_obj; }

void *OES_EGL_image_obj::_hx_vtable = 0;

Dynamic OES_EGL_image_obj::__Create(hx::DynamicArray inArgs)
{
	hx::ObjectPtr< OES_EGL_image_obj > _hx_result = new OES_EGL_image_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool OES_EGL_image_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x4416ef1a;
}


OES_EGL_image_obj::OES_EGL_image_obj()
{
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *OES_EGL_image_obj_sMemberStorageInfo = 0;
static hx::StaticInfo *OES_EGL_image_obj_sStaticStorageInfo = 0;
#endif

static void OES_EGL_image_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(OES_EGL_image_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void OES_EGL_image_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(OES_EGL_image_obj::__mClass,"__mClass");
};

#endif

hx::Class OES_EGL_image_obj::__mClass;

void OES_EGL_image_obj::__register()
{
	hx::Object *dummy = new OES_EGL_image_obj;
	OES_EGL_image_obj::_hx_vtable = *(void **)dummy;
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("lime.graphics.opengl.ext.OES_EGL_image","\x62","\x10","\xd2","\x25");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = OES_EGL_image_obj_sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = hx::TCanCast< OES_EGL_image_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = OES_EGL_image_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = OES_EGL_image_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = OES_EGL_image_obj_sStaticStorageInfo;
#endif
	hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace graphics
} // end namespace opengl
} // end namespace ext
