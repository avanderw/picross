// Generated by Haxe 3.4.4
#ifndef INCLUDED_openfl__internal_stage3D_opengl_GLVertexBuffer3D
#define INCLUDED_openfl__internal_stage3D_opengl_GLVertexBuffer3D

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(lime,utils,ArrayBufferView)
HX_DECLARE_CLASS2(openfl,_Vector,AbstractVector)
HX_DECLARE_CLASS3(openfl,_internal,renderer,RenderSession)
HX_DECLARE_CLASS4(openfl,_internal,stage3D,opengl,GLVertexBuffer3D)
HX_DECLARE_CLASS2(openfl,display3D,VertexBuffer3D)
HX_DECLARE_CLASS2(openfl,utils,ByteArrayData)
HX_DECLARE_CLASS2(openfl,utils,IDataInput)
HX_DECLARE_CLASS2(openfl,utils,IDataOutput)

namespace openfl{
namespace _internal{
namespace stage3D{
namespace opengl{


class HXCPP_CLASS_ATTRIBUTES GLVertexBuffer3D_obj : public hx::Object
{
	public:
		typedef hx::Object super;
		typedef GLVertexBuffer3D_obj OBJ_;
		GLVertexBuffer3D_obj();

	public:
		enum { _hx_ClassId = 0x162428d4 };

		void __construct();
		inline void *operator new(size_t inSize, bool inContainer=false,const char *inName="openfl._internal.stage3D.opengl.GLVertexBuffer3D")
			{ return hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return hx::Object::operator new(inSize+extra,false,"openfl._internal.stage3D.opengl.GLVertexBuffer3D"); }

		hx::ObjectPtr< GLVertexBuffer3D_obj > __new() {
			hx::ObjectPtr< GLVertexBuffer3D_obj > __this = new GLVertexBuffer3D_obj();
			__this->__construct();
			return __this;
		}

		static hx::ObjectPtr< GLVertexBuffer3D_obj > __alloc(hx::Ctx *_hx_ctx) {
			GLVertexBuffer3D_obj *__this = (GLVertexBuffer3D_obj*)(hx::Ctx::alloc(_hx_ctx, sizeof(GLVertexBuffer3D_obj), false, "openfl._internal.stage3D.opengl.GLVertexBuffer3D"));
			*(void **)__this = GLVertexBuffer3D_obj::_hx_vtable;
			return __this;
		}

		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GLVertexBuffer3D_obj();

		HX_DO_RTTI_ALL;
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, hx::PropertyAccess inCallProp);
		static void __register();
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_HCSTRING("GLVertexBuffer3D","\x3a","\x2e","\x7c","\x55"); }

		static void create( ::openfl::display3D::VertexBuffer3D vertexBuffer, ::openfl::_internal::renderer::RenderSession renderSession, ::Dynamic bufferUsage);
		static ::Dynamic create_dyn();

		static void dispose( ::openfl::display3D::VertexBuffer3D vertexBuffer, ::openfl::_internal::renderer::RenderSession renderSession);
		static ::Dynamic dispose_dyn();

		static void uploadFromByteArray( ::openfl::display3D::VertexBuffer3D vertexBuffer, ::openfl::_internal::renderer::RenderSession renderSession, ::openfl::utils::ByteArrayData data,int byteArrayOffset,int startVertex,int numVertices);
		static ::Dynamic uploadFromByteArray_dyn();

		static void uploadFromTypedArray( ::openfl::display3D::VertexBuffer3D vertexBuffer, ::openfl::_internal::renderer::RenderSession renderSession, ::lime::utils::ArrayBufferView data);
		static ::Dynamic uploadFromTypedArray_dyn();

		static void uploadFromVector( ::openfl::display3D::VertexBuffer3D vertexBuffer, ::openfl::_internal::renderer::RenderSession renderSession, ::openfl::_Vector::AbstractVector data,int startVertex,int numVertices);
		static ::Dynamic uploadFromVector_dyn();

};

} // end namespace openfl
} // end namespace _internal
} // end namespace stage3D
} // end namespace opengl

#endif /* INCLUDED_openfl__internal_stage3D_opengl_GLVertexBuffer3D */ 
