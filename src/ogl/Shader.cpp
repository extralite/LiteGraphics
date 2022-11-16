#include <xlite/ogl/Shader.hpp>

#include <glad/gl.h>

#include <cstring>
#include <iostream>

using namespace Lite::Graphics;

static GLboolean CompileShader(GLuint shader) {
    glCompileShader(shader);

    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success) {
        GLint length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

        GLchar *info = (GLchar *) malloc(length * sizeof(GLchar));
        glGetShaderInfoLog(shader, length, nullptr, info);

        std::cerr << "LiteGraphics Error: Shader compilation error\n"
                  << info << std::endl;

        free(info);
        return GL_FALSE;
    }

    return GL_TRUE;
}

static GLenum GetGLShaderType(ShaderType type) {
    switch (type) {
        case ShaderType::Vertex:
            return GL_VERTEX_SHADER;
        case ShaderType::Fragment:
            return GL_FRAGMENT_SHADER;
    }

    return GL_ARRAY_BUFFER;
}

template<ShaderType _Ty>
Shader<_Ty>::Shader(std::string source) : _Shader(0) {
    _Shader = glCreateShader(GetGLShaderType(_Ty));

    const char *_Source = source.c_str();
    const GLint _Length = strlen(_Source);
    glShaderSource(_Shader, 1, &_Source, &_Length);

    if (!CompileShader(_Shader)) {
        glDeleteShader(_Shader);
        _Shader = 0;
    }
}

template<ShaderType _Ty>
Shader<_Ty>::~Shader() {
    glDeleteShader(_Shader);
}

template class Shader<ShaderType::Vertex>;
template class Shader<ShaderType::Fragment>;
