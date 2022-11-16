#include <xlite/ogl/BufferObject.hpp>

#include <glad/gl.h>

using namespace Lite::Graphics;

static GLenum GetGLBufferType(BufferObjectType type) {
    switch (type) {
        case BufferObjectType::VertexArray:
            return GL_ARRAY_BUFFER;
        case BufferObjectType::ElementArray:
            return GL_ELEMENT_ARRAY_BUFFER;
    }

    return GL_ARRAY_BUFFER;
}

template<typename _T, BufferObjectType _Ty>
BufferObject<_T, _Ty>::BufferObject()
    : _Object(0), _Size(0), _Type(GetGLBufferType(_Ty)) {
    glGenBuffers(1, &_Object);
}

template<typename _T, BufferObjectType _Ty>
BufferObject<_T, _Ty>::~BufferObject() {
    glDeleteBuffers(1, &_Object);
}

template<typename _T, BufferObjectType _Ty>
void BufferObject<_T, _Ty>::Bind() const {
    glBindBuffer(_Type, _Object);
}

template<typename _T, BufferObjectType _Ty>
void BufferObject<_T, _Ty>::Unbind() const {
    glBindBuffer(_Type, 0);
}

template<typename _T, BufferObjectType _Ty>
void BufferObject<_T, _Ty>::Data(std::vector<_T> data) {
    _Size = data.size();
    glBufferData(_Type, sizeof(_T) * _Size, &data[0], GL_STATIC_DRAW);
}

template class BufferObject<float, BufferObjectType::VertexArray>;
template class BufferObject<uint32_t, BufferObjectType::ElementArray>;
