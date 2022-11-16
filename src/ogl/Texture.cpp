#include <xlite/ogl/Texture.hpp>

#include <glad/gl.h>

using namespace Lite::Graphics;

static GLenum GetGLTextureFormat(TextureFormat type) {
    switch (type) {
        case TextureFormat::RGBA:
            return GL_RGBA;
        case TextureFormat::BGRA:
            return GL_BGRA;
    }

    return GL_RGBA;
}

Texture::Texture(int32_t width, int32_t height, TextureFormat format)
    : _Texture(0), _Format(GetGLTextureFormat(format)) {
    glGenTextures(1, &_Texture);
    Bind();

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    Data(width, height, nullptr);
    Unbind();
}

Texture::~Texture() {
    glDeleteTextures(1, &_Texture);
}

void Texture::Bind() const {
    glBindTexture(GL_TEXTURE_2D, _Texture);
}

void Texture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Data(int32_t width, int32_t height, uint8_t *data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, _Format, GL_UNSIGNED_BYTE, data);
}

void Texture::SubData(int32_t x, int32_t y, int32_t width, int32_t height, uint8_t *data) {
    glTexSubImage2D(GL_TEXTURE_2D, 0, x, y, width, height, _Format, GL_UNSIGNED_BYTE, data);
}
