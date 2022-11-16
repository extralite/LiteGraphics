#pragma once

#include <xlite/ogl/Shader.hpp>

#include <cstdint>
#include <string>

namespace Lite {

    namespace Graphics {

        class ShaderProgram {
        private:
            uint32_t _Program;

        public:
            ShaderProgram();
            ~ShaderProgram();

            void Bind() const;
            void Unbind() const;

            bool Link();

            template<ShaderType _Type>
            void Attach(const Shader<_Type> &shader);
            template<ShaderType _Type>
            void Detach(const Shader<_Type> &shader);

            void Matrix4x4f(std::string uniform, const float *data);
        };

    }// namespace Graphics

}// namespace Lite
