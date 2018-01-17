// Generated by Haxe 3.4.4
#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_lime_utils_BytePointerData
#include <lime/utils/BytePointerData.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_316503c62a207c57_250_new,"lime.utils.BytePointerData","new",0x7e54685b,"lime.utils.BytePointerData.new","lime/utils/BytePointer.hx",250,0x50fae541)
namespace lime{
namespace utils{

void BytePointerData_obj::__construct( ::haxe::io::Bytes bytes,int offset){
            	HX_STACKFRAME(&_hx_pos_316503c62a207c57_250_new)
HXLINE( 252)		this->bytes = bytes;
HXLINE( 253)		this->offset = offset;
            	}

Dynamic BytePointerData_obj::__CreateEmpty() { return new BytePointerData_obj; }

void *BytePointerData_obj::_hx_vtable = 0;

Dynamic BytePointerData_obj::__Create(hx::DynamicArray inArgs)
{
	hx::ObjectPtr< BytePointerData_obj > _hx_result = new BytePointerData_obj();
	_hx_result->__construct(inArgs[0],inArgs[1]);
	return _hx_result;
}

bool BytePointerData_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x479b34cb;
}


hx::ObjectPtr< BytePointerData_obj > BytePointerData_obj::__new( ::haxe::io::Bytes bytes,int offset) {
	hx::ObjectPtr< BytePointerData_obj > __this = new BytePointerData_obj();
	__this->__construct(bytes,offset);
	return __this;
}

hx::ObjectPtr< BytePointerData_obj > BytePointerData_obj::__alloc(hx::Ctx *_hx_ctx, ::haxe::io::Bytes bytes,int offset) {
	BytePointerData_obj *__this = (BytePointerData_obj*)(hx::Ctx::alloc(_hx_ctx, sizeof(BytePointerData_obj), true, "lime.utils.BytePointerData"));
	*(void **)__this = BytePointerData_obj::_hx_vtable;
	__this->__construct(bytes,offset);
	return __this;
}

BytePointerData_obj::BytePointerData_obj()
{
}

void BytePointerData_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BytePointerData);
	HX_MARK_MEMBER_NAME(bytes,"bytes");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_END_CLASS();
}

void BytePointerData_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bytes,"bytes");
	HX_VISIT_MEMBER_NAME(offset,"offset");
}

hx::Val BytePointerData_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"bytes") ) { return hx::Val( bytes ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { return hx::Val( offset ); }
	}
	return super::__Field(inName,inCallProp);
}

hx::Val BytePointerData_obj::__SetField(const ::String &inName,const hx::Val &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"bytes") ) { bytes=inValue.Cast<  ::haxe::io::Bytes >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BytePointerData_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("bytes","\x6b","\x08","\x98","\xbd"));
	outFields->push(HX_HCSTRING("offset","\x93","\x97","\x3f","\x60"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo BytePointerData_obj_sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(BytePointerData_obj,bytes),HX_HCSTRING("bytes","\x6b","\x08","\x98","\xbd")},
	{hx::fsInt,(int)offsetof(BytePointerData_obj,offset),HX_HCSTRING("offset","\x93","\x97","\x3f","\x60")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *BytePointerData_obj_sStaticStorageInfo = 0;
#endif

static ::String BytePointerData_obj_sMemberFields[] = {
	HX_HCSTRING("bytes","\x6b","\x08","\x98","\xbd"),
	HX_HCSTRING("offset","\x93","\x97","\x3f","\x60"),
	::String(null()) };

static void BytePointerData_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BytePointerData_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void BytePointerData_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BytePointerData_obj::__mClass,"__mClass");
};

#endif

hx::Class BytePointerData_obj::__mClass;

void BytePointerData_obj::__register()
{
	hx::Object *dummy = new BytePointerData_obj;
	BytePointerData_obj::_hx_vtable = *(void **)dummy;
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("lime.utils.BytePointerData","\xe9","\x9e","\x94","\x8d");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = BytePointerData_obj_sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(BytePointerData_obj_sMemberFields);
	__mClass->mCanCast = hx::TCanCast< BytePointerData_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = BytePointerData_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = BytePointerData_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = BytePointerData_obj_sStaticStorageInfo;
#endif
	hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace utils
