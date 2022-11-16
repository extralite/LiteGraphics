#include <xlite/ogl/ShaderProgram.hpp>

#include <xlite/ogl/FragmentShader.hpp>
#include <xlite/ogl/VertexShader.hpp>

#include <glad/gl.h>

#include <iostream>

using namespace Lite::Graphics;

ShaderProgram::ShaderProgram() : _Program(0) {
    _Program = glCreateProgram();
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(_Program);
}

void ShaderProgram::Bind() const {
    glUseProgram(_Program);
}

void ShaderProgram::Unbind() const {
    glUseProgram(0);
}

bool ShaderProgram::Link() {
    glLinkProgram(_Program);

    GLint success = 0;
    glGetProgramiv(_Program, GL_LINK_STATUS, &success);

    if (!success) {
        GLint length = 0;
        glGetProgramiv(_Program, GL_INFO_LOG_LENGTH, &length);

        GLchar *info = (GLchar *) malloc(length * sizeof(GLchar));
        glGetProgramInfoLog(_Program, length, nullptr, info);

        std::cerr << "LiteGraphics Error: Shader linking error\n"
                  << info << std::endl;

        free(info);
        return GL_FALSE;
    }

    return GL_TRUE;
}

template<ShaderType _Type>
void ShaderProgram::Attach(const Shader<_Type> &shader) {
    glAttachShader(_Program, shader._Shader);
}

template<ShaderType _Type>
void ShaderProgram::Detach(const Shader<_Type> &shader) {
    glDetachShader(_Program, shader._Shader);
}

void ShaderProgram::Matrix4x4f(std::string uniform, const float *data) {
    GLuint _Location = glGetUniformLocation(_Program, uniform.c_str());
    glUniformMatrix4fv(_Location, 1, GL_FALSE, data);
}

template void ShaderProgram::Attach(const Shader<ShaderType::Vertex> &shader);
template void ShaderProgram::Attach(const Shader<ShaderType::Fragment> &shader);

template void ShaderProgram::Detach(const Shader<ShaderType::Vertex> &shader);
template void ShaderProgram::Detach(const Shader<ShaderType::Fragment> &shader);
