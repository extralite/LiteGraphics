#include <xlite/ogl/VertexArrayObject.hpp>

#include <glad/gl.h>

using namespace Lite::Graphics;

VertexArrayObject::VertexArrayObject()
    : _Object(0), _AttribLength(0) {
    glGenVertexArrays(1, &_Object);
}

VertexArrayObject::~VertexArrayObject() {
    glDeleteVertexArrays(1, &_Object);
}

void VertexArrayObject::Bind() const {
    glBindVertexArray(_Object);
}

void VertexArrayObject::Unbind() const {
    glBindVertexArray(0);
}

void VertexArrayObject::Attrib(int32_t size, int32_t length, int32_t offset) {
    glVertexAttribPointer(_AttribLength, size, GL_FLOAT, GL_FALSE, length * sizeof(GLfloat), (GLvoid *) (offset * sizeof(GLfloat)));
    glEnableVertexAttribArray(_AttribLength);
    _AttribLength = _AttribLength + 1;
}

void VertexArrayObject::DrawArrays(uint32_t count) {
    glDrawArrays(GL_TRIANGLES, 0, count);
}

void VertexArrayObject::DrawElements(uint32_t count) {
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
}
