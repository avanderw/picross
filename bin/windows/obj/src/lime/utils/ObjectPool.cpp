// Generated by Haxe 3.4.4
#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED__List_ListNode
#include <_List/ListNode.h>
#endif
#ifndef INCLUDED_haxe_IMap
#include <haxe/IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_lime_utils_ObjectPool
#include <lime/utils/ObjectPool.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_26_new,"lime.utils.ObjectPool","new",0x6a851d63,"lime.utils.ObjectPool.new","lime/utils/ObjectPool.hx",26,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_60_add,"lime.utils.ObjectPool","add",0x6a7b3f24,"lime.utils.ObjectPool.add","lime/utils/ObjectPool.hx",60,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_71___default_clean,"lime.utils.ObjectPool","__default_clean",0xb88b96ae,"lime.utils.ObjectPool.__default_clean","lime/utils/ObjectPool.hx",71,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_78_clear,"lime.utils.ObjectPool","clear",0x9b3c4550,"lime.utils.ObjectPool.clear","lime/utils/ObjectPool.hx",78,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_94___default_create,"lime.utils.ObjectPool","__default_create",0x35ffc237,"lime.utils.ObjectPool.__default_create","lime/utils/ObjectPool.hx",94,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_99_get,"lime.utils.ObjectPool","get",0x6a7fcd99,"lime.utils.ObjectPool.get","lime/utils/ObjectPool.hx",99,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_125_release,"lime.utils.ObjectPool","release",0xc47d104a,"lime.utils.ObjectPool.release","lime/utils/ObjectPool.hx",125,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_155___addInactive,"lime.utils.ObjectPool","__addInactive",0xbe535e4f,"lime.utils.ObjectPool.__addInactive","lime/utils/ObjectPool.hx",155,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_180___getInactive,"lime.utils.ObjectPool","__getInactive",0xb2eae9c4,"lime.utils.ObjectPool.__getInactive","lime/utils/ObjectPool.hx",180,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_224___removeInactive,"lime.utils.ObjectPool","__removeInactive",0x1e106c0c,"lime.utils.ObjectPool.__removeInactive","lime/utils/ObjectPool.hx",224,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_273_get_size,"lime.utils.ObjectPool","get_size",0x7e180467,"lime.utils.ObjectPool.get_size","lime/utils/ObjectPool.hx",273,0xc114d76b)
HX_LOCAL_STACK_FRAME(_hx_pos_06bcacad9f56fcf1_278_set_size,"lime.utils.ObjectPool","set_size",0x2c755ddb,"lime.utils.ObjectPool.set_size","lime/utils/ObjectPool.hx",278,0xc114d76b)
namespace lime{
namespace utils{

void ObjectPool_obj::__construct( ::Dynamic create, ::Dynamic clean, ::Dynamic size){
            	HX_GC_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_26_new)
HXLINE(  28)		if (hx::IsNotNull( create )) {
HXLINE(  30)			this->create = create;
            		}
HXLINE(  34)		if (hx::IsNotNull( clean )) {
HXLINE(  36)			this->clean = clean;
            		}
HXLINE(  40)		if (hx::IsNotNull( size )) {
HXLINE(  42)			this->set_size(size);
            		}
HXLINE(  46)		this->_hx___pool =  ::haxe::ds::ObjectMap_obj::__alloc( HX_CTX );
HXLINE(  48)		this->activeObjects = (int)0;
HXLINE(  49)		this->inactiveObjects = (int)0;
HXLINE(  51)		this->_hx___inactiveObject0 = null();
HXLINE(  52)		this->_hx___inactiveObject1 = null();
HXLINE(  53)		this->_hx___inactiveObjectList =  ::List_obj::__alloc( HX_CTX );
            	}

Dynamic ObjectPool_obj::__CreateEmpty() { return new ObjectPool_obj; }

void *ObjectPool_obj::_hx_vtable = 0;

Dynamic ObjectPool_obj::__Create(hx::DynamicArray inArgs)
{
	hx::ObjectPtr< ObjectPool_obj > _hx_result = new ObjectPool_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return _hx_result;
}

bool ObjectPool_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x7cea4d17;
}

void ObjectPool_obj::add( ::Dynamic object){
            	HX_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_60_add)
HXDLIN(  60)		if (!(::haxe::IMap_obj::exists(this->_hx___pool,object))) {
HXLINE(  62)			::haxe::IMap_obj::set(this->_hx___pool,object,false);
HXLINE(  63)			this->clean(object);
HXLINE(  64)			{
HXLINE(  64)				if (hx::IsNull( this->_hx___inactiveObject0 )) {
HXLINE(  64)					this->_hx___inactiveObject0 = object;
            				}
            				else {
HXLINE(  64)					if (hx::IsNull( this->_hx___inactiveObject1 )) {
HXLINE(  64)						this->_hx___inactiveObject1 = object;
            					}
            					else {
HXLINE(  64)						this->_hx___inactiveObjectList->add(object);
            					}
            				}
HXDLIN(  64)				this->inactiveObjects++;
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(ObjectPool_obj,add,(void))

HX_BEGIN_DEFAULT_FUNC(__default_clean,ObjectPool_obj)
void _hx_run( ::Dynamic object){
            	HX_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_71___default_clean)
            	}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

void ObjectPool_obj::clear(){
            	HX_GC_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_78_clear)
HXLINE(  80)		this->_hx___pool =  ::haxe::ds::ObjectMap_obj::__alloc( HX_CTX );
HXLINE(  82)		this->activeObjects = (int)0;
HXLINE(  83)		this->inactiveObjects = (int)0;
HXLINE(  85)		this->_hx___inactiveObject0 = null();
HXLINE(  86)		this->_hx___inactiveObject1 = null();
HXLINE(  87)		this->_hx___inactiveObjectList->clear();
            	}


HX_DEFINE_DYNAMIC_FUNC0(ObjectPool_obj,clear,(void))

HX_BEGIN_DEFAULT_FUNC(__default_create,ObjectPool_obj)
 ::Dynamic _hx_run(){
            	HX_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_94___default_create)
HXDLIN(  94)		return null();
            	}
HX_END_LOCAL_FUNC0(return )
HX_END_DEFAULT_FUNC

 ::Dynamic ObjectPool_obj::get(){
            	HX_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_99_get)
HXLINE( 101)		 ::Dynamic object = null();
HXLINE( 103)		if ((this->inactiveObjects > (int)0)) {
HXLINE( 105)			 ::Dynamic object1 = null();
HXDLIN( 105)			if (hx::IsNotNull( this->_hx___inactiveObject0 )) {
HXLINE( 105)				object1 = this->_hx___inactiveObject0;
HXDLIN( 105)				this->_hx___inactiveObject0 = null();
            			}
            			else {
HXLINE( 105)				if (hx::IsNotNull( this->_hx___inactiveObject1 )) {
HXLINE( 105)					object1 = this->_hx___inactiveObject1;
HXDLIN( 105)					this->_hx___inactiveObject1 = null();
            				}
            				else {
HXLINE( 105)					object1 = this->_hx___inactiveObjectList->pop();
HXDLIN( 105)					if ((this->_hx___inactiveObjectList->length > (int)0)) {
HXLINE( 105)						this->_hx___inactiveObject0 = this->_hx___inactiveObjectList->pop();
            					}
HXDLIN( 105)					if ((this->_hx___inactiveObjectList->length > (int)0)) {
HXLINE( 105)						this->_hx___inactiveObject1 = this->_hx___inactiveObjectList->pop();
            					}
            				}
            			}
HXDLIN( 105)			this->inactiveObjects--;
HXDLIN( 105)			this->activeObjects++;
HXDLIN( 105)			object = object1;
            		}
            		else {
HXLINE( 107)			bool _hx_tmp;
HXDLIN( 107)			if (hx::IsNotNull( this->_hx___size )) {
HXLINE( 107)				_hx_tmp = hx::IsLess( this->activeObjects,this->_hx___size );
            			}
            			else {
HXLINE( 107)				_hx_tmp = true;
            			}
HXDLIN( 107)			if (_hx_tmp) {
HXLINE( 109)				object = this->create();
HXLINE( 111)				if (hx::IsNotNull( object )) {
HXLINE( 113)					::haxe::IMap_obj::set(this->_hx___pool,object,true);
HXLINE( 114)					this->activeObjects++;
            				}
            			}
            		}
HXLINE( 120)		return object;
            	}


HX_DEFINE_DYNAMIC_FUNC0(ObjectPool_obj,get,return )

void ObjectPool_obj::release( ::Dynamic object){
            	HX_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_125_release)
HXLINE( 139)		this->activeObjects--;
HXLINE( 141)		bool _hx_tmp;
HXDLIN( 141)		if (hx::IsNotNull( this->_hx___size )) {
HXLINE( 141)			_hx_tmp = hx::IsLess( (this->activeObjects + this->inactiveObjects),this->_hx___size );
            		}
            		else {
HXLINE( 141)			_hx_tmp = true;
            		}
HXDLIN( 141)		if (_hx_tmp) {
HXLINE( 143)			this->clean(object);
HXLINE( 144)			{
HXLINE( 144)				if (hx::IsNull( this->_hx___inactiveObject0 )) {
HXLINE( 144)					this->_hx___inactiveObject0 = object;
            				}
            				else {
HXLINE( 144)					if (hx::IsNull( this->_hx___inactiveObject1 )) {
HXLINE( 144)						this->_hx___inactiveObject1 = object;
            					}
            					else {
HXLINE( 144)						this->_hx___inactiveObjectList->add(object);
            					}
            				}
HXDLIN( 144)				this->inactiveObjects++;
            			}
            		}
            		else {
HXLINE( 148)			::haxe::IMap_obj::remove(this->_hx___pool,object);
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(ObjectPool_obj,release,(void))

void ObjectPool_obj::_hx___addInactive( ::Dynamic object){
            	HX_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_155___addInactive)
HXLINE( 161)		if (hx::IsNull( this->_hx___inactiveObject0 )) {
HXLINE( 163)			this->_hx___inactiveObject0 = object;
            		}
            		else {
HXLINE( 165)			if (hx::IsNull( this->_hx___inactiveObject1 )) {
HXLINE( 167)				this->_hx___inactiveObject1 = object;
            			}
            			else {
HXLINE( 171)				this->_hx___inactiveObjectList->add(object);
            			}
            		}
HXLINE( 175)		this->inactiveObjects++;
            	}


HX_DEFINE_DYNAMIC_FUNC1(ObjectPool_obj,_hx___addInactive,(void))

 ::Dynamic ObjectPool_obj::_hx___getInactive(){
            	HX_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_180___getInactive)
HXLINE( 182)		 ::Dynamic object = null();
HXLINE( 184)		if (hx::IsNotNull( this->_hx___inactiveObject0 )) {
HXLINE( 186)			object = this->_hx___inactiveObject0;
HXLINE( 187)			this->_hx___inactiveObject0 = null();
            		}
            		else {
HXLINE( 189)			if (hx::IsNotNull( this->_hx___inactiveObject1 )) {
HXLINE( 191)				object = this->_hx___inactiveObject1;
HXLINE( 192)				this->_hx___inactiveObject1 = null();
            			}
            			else {
HXLINE( 196)				object = this->_hx___inactiveObjectList->pop();
HXLINE( 198)				if ((this->_hx___inactiveObjectList->length > (int)0)) {
HXLINE( 200)					this->_hx___inactiveObject0 = this->_hx___inactiveObjectList->pop();
            				}
HXLINE( 204)				if ((this->_hx___inactiveObjectList->length > (int)0)) {
HXLINE( 206)					this->_hx___inactiveObject1 = this->_hx___inactiveObjectList->pop();
            				}
            			}
            		}
HXLINE( 216)		this->inactiveObjects--;
HXLINE( 217)		this->activeObjects++;
HXLINE( 219)		return object;
            	}


HX_DEFINE_DYNAMIC_FUNC0(ObjectPool_obj,_hx___getInactive,return )

void ObjectPool_obj::_hx___removeInactive(int count){
            	HX_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_224___removeInactive)
HXLINE( 226)		bool _hx_tmp;
HXDLIN( 226)		if ((count > (int)0)) {
HXLINE( 226)			_hx_tmp = (this->inactiveObjects == (int)0);
            		}
            		else {
HXLINE( 226)			_hx_tmp = true;
            		}
HXDLIN( 226)		if (_hx_tmp) {
HXLINE( 226)			return;
            		}
HXLINE( 228)		if (hx::IsNotNull( this->_hx___inactiveObject0 )) {
HXLINE( 230)			::haxe::IMap_obj::remove(this->_hx___pool,this->_hx___inactiveObject0);
HXLINE( 231)			this->_hx___inactiveObject0 = null();
HXLINE( 232)			this->inactiveObjects--;
HXLINE( 233)			count = (count - (int)1);
            		}
HXLINE( 237)		bool _hx_tmp1;
HXDLIN( 237)		if ((count != (int)0)) {
HXLINE( 237)			_hx_tmp1 = (this->inactiveObjects == (int)0);
            		}
            		else {
HXLINE( 237)			_hx_tmp1 = true;
            		}
HXDLIN( 237)		if (_hx_tmp1) {
HXLINE( 237)			return;
            		}
HXLINE( 239)		if (hx::IsNotNull( this->_hx___inactiveObject1 )) {
HXLINE( 241)			::haxe::IMap_obj::remove(this->_hx___pool,this->_hx___inactiveObject1);
HXLINE( 242)			this->_hx___inactiveObject1 = null();
HXLINE( 243)			this->inactiveObjects--;
HXLINE( 244)			count = (count - (int)1);
            		}
HXLINE( 248)		bool _hx_tmp2;
HXDLIN( 248)		if ((count != (int)0)) {
HXLINE( 248)			_hx_tmp2 = (this->inactiveObjects == (int)0);
            		}
            		else {
HXLINE( 248)			_hx_tmp2 = true;
            		}
HXDLIN( 248)		if (_hx_tmp2) {
HXLINE( 248)			return;
            		}
HXLINE( 250)		{
HXLINE( 250)			 ::_List::ListNode _g_head = this->_hx___inactiveObjectList->h;
HXDLIN( 250)			while(hx::IsNotNull( _g_head )){
HXLINE( 250)				 ::Dynamic val = _g_head->item;
HXDLIN( 250)				_g_head = _g_head->next;
HXDLIN( 250)				 ::Dynamic object = val;
HXLINE( 252)				::haxe::IMap_obj::remove(this->_hx___pool,object);
HXLINE( 253)				this->_hx___inactiveObjectList->remove(object);
HXLINE( 254)				this->inactiveObjects--;
HXLINE( 255)				count = (count - (int)1);
HXLINE( 257)				bool _hx_tmp3;
HXDLIN( 257)				if ((count != (int)0)) {
HXLINE( 257)					_hx_tmp3 = (this->inactiveObjects == (int)0);
            				}
            				else {
HXLINE( 257)					_hx_tmp3 = true;
            				}
HXDLIN( 257)				if (_hx_tmp3) {
HXLINE( 257)					return;
            				}
            			}
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(ObjectPool_obj,_hx___removeInactive,(void))

 ::Dynamic ObjectPool_obj::get_size(){
            	HX_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_273_get_size)
HXDLIN( 273)		return this->_hx___size;
            	}


HX_DEFINE_DYNAMIC_FUNC0(ObjectPool_obj,get_size,return )

 ::Dynamic ObjectPool_obj::set_size( ::Dynamic value){
            	HX_STACKFRAME(&_hx_pos_06bcacad9f56fcf1_278_set_size)
HXLINE( 280)		if (hx::IsNull( value )) {
HXLINE( 282)			this->_hx___size = null();
            		}
            		else {
HXLINE( 286)			int current = (this->inactiveObjects + this->activeObjects);
HXLINE( 287)			this->_hx___size = value;
HXLINE( 289)			if (hx::IsGreater( current,value )) {
HXLINE( 291)				this->_hx___removeInactive((current - value));
            			}
            			else {
HXLINE( 293)				if (hx::IsGreater( value,current )) {
HXLINE( 295)					 ::Dynamic object;
HXLINE( 297)					{
HXLINE( 297)						int _g1 = (int)0;
HXDLIN( 297)						int _g = (value - current);
HXDLIN( 297)						while((_g1 < _g)){
HXLINE( 297)							_g1 = (_g1 + (int)1);
HXDLIN( 297)							int i = (_g1 - (int)1);
HXLINE( 299)							object = this->create();
HXLINE( 301)							if (hx::IsNotNull( object )) {
HXLINE( 303)								::haxe::IMap_obj::set(this->_hx___pool,object,false);
HXLINE( 304)								this->_hx___inactiveObjectList->add(object);
HXLINE( 305)								this->inactiveObjects++;
            							}
            							else {
HXLINE( 309)								goto _hx_goto_12;
            							}
            						}
            						_hx_goto_12:;
            					}
            				}
            			}
            		}
HXLINE( 319)		return value;
            	}


HX_DEFINE_DYNAMIC_FUNC1(ObjectPool_obj,set_size,return )


void ObjectPool_obj::__alloc_dynamic_functions(hx::Ctx *_hx_ctx,ObjectPool_obj *_hx_obj) {
	if (!_hx_obj->create.mPtr) _hx_obj->create = new __default_create(_hx_obj);
	if (!_hx_obj->clean.mPtr) _hx_obj->clean = new __default_clean(_hx_obj);
}
hx::ObjectPtr< ObjectPool_obj > ObjectPool_obj::__new( ::Dynamic create, ::Dynamic clean, ::Dynamic size) {
	hx::ObjectPtr< ObjectPool_obj > __this = new ObjectPool_obj();
	__this->__construct(create,clean,size);
	return __this;
}

hx::ObjectPtr< ObjectPool_obj > ObjectPool_obj::__alloc(hx::Ctx *_hx_ctx, ::Dynamic create, ::Dynamic clean, ::Dynamic size) {
	ObjectPool_obj *__this = (ObjectPool_obj*)(hx::Ctx::alloc(_hx_ctx, sizeof(ObjectPool_obj), true, "lime.utils.ObjectPool"));
	*(void **)__this = ObjectPool_obj::_hx_vtable;
	lime::utils::ObjectPool_obj::__alloc_dynamic_functions(_hx_ctx,__this);
	__this->__construct(create,clean,size);
	return __this;
}

ObjectPool_obj::ObjectPool_obj()
{
	create = new __default_create(this);
	clean = new __default_clean(this);
}

void ObjectPool_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ObjectPool);
	HX_MARK_MEMBER_NAME(activeObjects,"activeObjects");
	HX_MARK_MEMBER_NAME(inactiveObjects,"inactiveObjects");
	HX_MARK_MEMBER_NAME(_hx___inactiveObject0,"__inactiveObject0");
	HX_MARK_MEMBER_NAME(_hx___inactiveObject1,"__inactiveObject1");
	HX_MARK_MEMBER_NAME(_hx___inactiveObjectList,"__inactiveObjectList");
	HX_MARK_MEMBER_NAME(_hx___pool,"__pool");
	HX_MARK_MEMBER_NAME(_hx___size,"__size");
	HX_MARK_MEMBER_NAME(clean,"clean");
	HX_MARK_MEMBER_NAME(create,"create");
	HX_MARK_END_CLASS();
}

void ObjectPool_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(activeObjects,"activeObjects");
	HX_VISIT_MEMBER_NAME(inactiveObjects,"inactiveObjects");
	HX_VISIT_MEMBER_NAME(_hx___inactiveObject0,"__inactiveObject0");
	HX_VISIT_MEMBER_NAME(_hx___inactiveObject1,"__inactiveObject1");
	HX_VISIT_MEMBER_NAME(_hx___inactiveObjectList,"__inactiveObjectList");
	HX_VISIT_MEMBER_NAME(_hx___pool,"__pool");
	HX_VISIT_MEMBER_NAME(_hx___size,"__size");
	HX_VISIT_MEMBER_NAME(clean,"clean");
	HX_VISIT_MEMBER_NAME(create,"create");
}

hx::Val ObjectPool_obj::__Field(const ::String &inName,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return hx::Val( add_dyn() ); }
		if (HX_FIELD_EQ(inName,"get") ) { return hx::Val( get_dyn() ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { if (inCallProp == hx::paccAlways) return hx::Val( get_size() ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clean") ) { return hx::Val( clean ); }
		if (HX_FIELD_EQ(inName,"clear") ) { return hx::Val( clear_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"__pool") ) { return hx::Val( _hx___pool ); }
		if (HX_FIELD_EQ(inName,"__size") ) { return hx::Val( _hx___size ); }
		if (HX_FIELD_EQ(inName,"create") ) { return hx::Val( create ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"release") ) { return hx::Val( release_dyn() ); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_size") ) { return hx::Val( get_size_dyn() ); }
		if (HX_FIELD_EQ(inName,"set_size") ) { return hx::Val( set_size_dyn() ); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeObjects") ) { return hx::Val( activeObjects ); }
		if (HX_FIELD_EQ(inName,"__addInactive") ) { return hx::Val( _hx___addInactive_dyn() ); }
		if (HX_FIELD_EQ(inName,"__getInactive") ) { return hx::Val( _hx___getInactive_dyn() ); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"inactiveObjects") ) { return hx::Val( inactiveObjects ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"__removeInactive") ) { return hx::Val( _hx___removeInactive_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"__inactiveObject0") ) { return hx::Val( _hx___inactiveObject0 ); }
		if (HX_FIELD_EQ(inName,"__inactiveObject1") ) { return hx::Val( _hx___inactiveObject1 ); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"__inactiveObjectList") ) { return hx::Val( _hx___inactiveObjectList ); }
	}
	return super::__Field(inName,inCallProp);
}

hx::Val ObjectPool_obj::__SetField(const ::String &inName,const hx::Val &inValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { if (inCallProp == hx::paccAlways) return hx::Val( set_size(inValue.Cast<  ::Dynamic >()) ); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clean") ) { clean=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"__pool") ) { _hx___pool=inValue.Cast< ::Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__size") ) { _hx___size=inValue.Cast<  ::Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"create") ) { create=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeObjects") ) { activeObjects=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"inactiveObjects") ) { inactiveObjects=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"__inactiveObject0") ) { _hx___inactiveObject0=inValue.Cast<  ::Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__inactiveObject1") ) { _hx___inactiveObject1=inValue.Cast<  ::Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"__inactiveObjectList") ) { _hx___inactiveObjectList=inValue.Cast<  ::List >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ObjectPool_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_HCSTRING("activeObjects","\xae","\xb3","\x18","\x3a"));
	outFields->push(HX_HCSTRING("inactiveObjects","\xa9","\x0c","\xc7","\xfb"));
	outFields->push(HX_HCSTRING("size","\xc1","\xa0","\x53","\x4c"));
	outFields->push(HX_HCSTRING("__inactiveObject0","\x46","\x3d","\x21","\x7f"));
	outFields->push(HX_HCSTRING("__inactiveObject1","\x47","\x3d","\x21","\x7f"));
	outFields->push(HX_HCSTRING("__inactiveObjectList","\x28","\xdd","\x99","\x7e"));
	outFields->push(HX_HCSTRING("__pool","\xfc","\xe3","\x54","\xf9"));
	outFields->push(HX_HCSTRING("__size","\xe1","\x03","\x4c","\xfb"));
	super::__GetFields(outFields);
};

#if HXCPP_SCRIPTABLE
static hx::StorageInfo ObjectPool_obj_sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(ObjectPool_obj,activeObjects),HX_HCSTRING("activeObjects","\xae","\xb3","\x18","\x3a")},
	{hx::fsInt,(int)offsetof(ObjectPool_obj,inactiveObjects),HX_HCSTRING("inactiveObjects","\xa9","\x0c","\xc7","\xfb")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(ObjectPool_obj,_hx___inactiveObject0),HX_HCSTRING("__inactiveObject0","\x46","\x3d","\x21","\x7f")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(ObjectPool_obj,_hx___inactiveObject1),HX_HCSTRING("__inactiveObject1","\x47","\x3d","\x21","\x7f")},
	{hx::fsObject /*::List*/ ,(int)offsetof(ObjectPool_obj,_hx___inactiveObjectList),HX_HCSTRING("__inactiveObjectList","\x28","\xdd","\x99","\x7e")},
	{hx::fsObject /*::haxe::IMap*/ ,(int)offsetof(ObjectPool_obj,_hx___pool),HX_HCSTRING("__pool","\xfc","\xe3","\x54","\xf9")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(ObjectPool_obj,_hx___size),HX_HCSTRING("__size","\xe1","\x03","\x4c","\xfb")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(ObjectPool_obj,clean),HX_HCSTRING("clean","\x89","\x71","\x5b","\x48")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(ObjectPool_obj,create),HX_HCSTRING("create","\xfc","\x66","\x0f","\x7c")},
	{ hx::fsUnknown, 0, null()}
};
static hx::StaticInfo *ObjectPool_obj_sStaticStorageInfo = 0;
#endif

static ::String ObjectPool_obj_sMemberFields[] = {
	HX_HCSTRING("activeObjects","\xae","\xb3","\x18","\x3a"),
	HX_HCSTRING("inactiveObjects","\xa9","\x0c","\xc7","\xfb"),
	HX_HCSTRING("__inactiveObject0","\x46","\x3d","\x21","\x7f"),
	HX_HCSTRING("__inactiveObject1","\x47","\x3d","\x21","\x7f"),
	HX_HCSTRING("__inactiveObjectList","\x28","\xdd","\x99","\x7e"),
	HX_HCSTRING("__pool","\xfc","\xe3","\x54","\xf9"),
	HX_HCSTRING("__size","\xe1","\x03","\x4c","\xfb"),
	HX_HCSTRING("add","\x21","\xf2","\x49","\x00"),
	HX_HCSTRING("clean","\x89","\x71","\x5b","\x48"),
	HX_HCSTRING("clear","\x8d","\x71","\x5b","\x48"),
	HX_HCSTRING("create","\xfc","\x66","\x0f","\x7c"),
	HX_HCSTRING("get","\x96","\x80","\x4e","\x00"),
	HX_HCSTRING("release","\xc7","\x85","\xed","\x58"),
	HX_HCSTRING("__addInactive","\x8c","\x8f","\x04","\xe4"),
	HX_HCSTRING("__getInactive","\x01","\x1b","\x9c","\xd8"),
	HX_HCSTRING("__removeInactive","\xef","\xde","\xc5","\x68"),
	HX_HCSTRING("get_size","\x4a","\x5c","\x0e","\xcc"),
	HX_HCSTRING("set_size","\xbe","\xb5","\x6b","\x7a"),
	::String(null()) };

static void ObjectPool_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ObjectPool_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void ObjectPool_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ObjectPool_obj::__mClass,"__mClass");
};

#endif

hx::Class ObjectPool_obj::__mClass;

void ObjectPool_obj::__register()
{
	hx::Object *dummy = new ObjectPool_obj;
	ObjectPool_obj::_hx_vtable = *(void **)dummy;
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("lime.utils.ObjectPool","\xf1","\x2f","\xf4","\x28");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &hx::Class_obj::SetNoStaticField;
	__mClass->mMarkFunc = ObjectPool_obj_sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = hx::Class_obj::dupFunctions(ObjectPool_obj_sMemberFields);
	__mClass->mCanCast = hx::TCanCast< ObjectPool_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = ObjectPool_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = ObjectPool_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = ObjectPool_obj_sStaticStorageInfo;
#endif
	hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

} // end namespace lime
} // end namespace utils
