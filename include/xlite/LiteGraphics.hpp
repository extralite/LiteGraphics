#pragma once

#include <xlite/ogl/BufferObject.hpp>
#include <xlite/ogl/ElementBufferObject.hpp>
#include <xlite/ogl/FragmentShader.hpp>
#include <xlite/ogl/Shader.hpp>
#include <xlite/ogl/ShaderProgram.hpp>
#include <xlite/ogl/VertexBufferObject.hpp>
#include <xlite/ogl/VertexShader.hpp>

#include <cstdint>

namespace Lite {

    namespace Graphics {
        int Load();

        void Clear();
        void ClearColor(float r, float g, float b, float a);

        void EnableDepthTesting();
        void EnableBlending();
        void EnableTexture2D();

        void ViewPort(int32_t x, int32_t y, int32_t width, int32_t height);
    }// namespace Graphics

}// namespace Lite
