// Generated by Haxe 3.4.4
#include <hxcpp.h>

#ifndef INCLUDED_openfl__internal_stage3D__AGALConverter_RegisterMapEntry
#include <openfl/_internal/stage3D/_AGALConverter/RegisterMapEntry.h>
#endif
#ifndef INCLUDED_openfl__internal_stage3D__AGALConverter_RegisterUsage
#include <openfl/_internal/stage3D/_AGALConverter/RegisterUsage.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_035ce49d07eb1206_867_new,"openfl._internal.stage3D._AGALConverter.RegisterMapEntry","new",0xdb756f7a,"openfl._internal.stage3D._AGALConverter.RegisterMapEntry.new","openfl/_internal/stage3D/AGALConverter.hx",867,0x0a35cc61)
namespace openfl{
namespace _internal{
namespace stage3D{
namespace _AGALConverter{

void RegisterMapEntry_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_035ce49d07eb1206_867_new)
            	}

Dynamic RegisterMapEntry_obj::__CreateEmpty() { return new RegisterMapEntry_obj; }

void *RegisterMapEntry_obj::_hx_vtable = 0;

Dynamic RegisterMapEntry_obj::__Create(hx::DynamicArray inArgs)
{
	hx::ObjectPtr< RegisterMapEntry_obj > _hx_result = new RegisterMapEntry_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool RegisterMapEntry_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x1c4c8a4c;
}


RegisterMapEntry_obj::RegisterMapEntry_obj()
{
}

void RegisterMapEntry_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RegisterMapEntry);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(number,"number");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(usage,"usage");
	HX_MARK_END_CLASS();
}

void RegisterMapEntry_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(number,"number");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(usage,"usage");
}

hx::Val RegisterMapEntry_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return hx::Val( name ); }
		if (HX_FIELD_EQ(inName,"type") ) { return hx::Val( type ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"usage") ) { return hx::Val( usage ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"number") ) { return hx::Val( number ); }
	}
	return super::__Field(inName,inCallProp);
}

hx::Val RegisterMapEntry_obj::__SetField(const ::String &inName,const hx::Val &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"usage") ) { usage=inValue.Cast<  ::openfl::_internal::stage3D::_AGALConverter::RegisterUsage >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"number") ) { number=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RegisterMapEntry_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("name","\x4b","\x72","\xff","\x48"));
	outFields->push(HX_HCSTRING("number","\xc9","\x86","\x7a","\xa1"));
	outFields->push(HX_HCSTRING("type","\xba","\xf2","\x08","\x4d"));
	outFields->push(HX_HCSTRING("usage","\x21","\x5d","\x2f","\xaa"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo RegisterMapEntry_obj_sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(RegisterMapEntry_obj,name),HX_HCSTRING("name","\x4b","\x72","\xff","\x48")},
	{hx::fsInt,(int)offsetof(RegisterMapEntry_obj,number),HX_HCSTRING("number","\xc9","\x86","\x7a","\xa1")},
	{hx::fsInt,(int)offsetof(RegisterMapEntry_obj,type),HX_HCSTRING("type","\xba","\xf2","\x08","\x4d")},
	{hx::fsObject /*::openfl::_internal::stage3D::_AGALConverter::RegisterUsage*/ ,(int)offsetof(RegisterMapEntry_obj,usage),HX_HCSTRING("usage","\x21","\x5d","\x2f","\xaa")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *RegisterMapEntry_obj_sStaticStorageInfo = 0;
#endif

static ::String RegisterMapEntry_obj_sMemberFields[] = {
	HX_HCSTRING("name","\x4b","\x72","\xff","\x48"),
	HX_HCSTRING("number","\xc9","\x86","\x7a","\xa1"),
	HX_HCSTRING("type","\xba","\xf2","\x08","\x4d"),
	HX_HCSTRING("usage","\x21","\x5d","\x2f","\xaa"),
	::String(null()) };

static void RegisterMapEntry_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RegisterMapEntry_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void RegisterMapEntry_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RegisterMapEntry_obj::__mClass,"__mClass");
};

#endif

hx::Class RegisterMapEntry_obj::__mClass;

void RegisterMapEntry_obj::__register()
{
	hx::Object *dummy = new RegisterMapEntry_obj;
	RegisterMapEntry_obj::_hx_vtable = *(void **)dummy;
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("openfl._internal.stage3D._AGALConverter.RegisterMapEntry","\x88","\xea","\xfd","\x67");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = RegisterMapEntry_obj_sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(RegisterMapEntry_obj_sMemberFields);
	__mClass->mCanCast = hx::TCanCast< RegisterMapEntry_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = RegisterMapEntry_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = RegisterMapEntry_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = RegisterMapEntry_obj_sStaticStorageInfo;
#endif
	hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace openfl
} // end namespace _internal
} // end namespace stage3D
} // end namespace _AGALConverter
