#pragma once

#include <cstdint>
#include <string>

namespace Lite {

    namespace Graphics {

        enum ShaderType : uint32_t {
            Vertex = 0,
            Fragment = 1,
        };

        template<ShaderType _Ty>
        class Shader {
            friend class ShaderProgram;

        private:
            uint32_t _Shader;

        public:
            Shader(std::string source);
            ~Shader();
        };

    }// namespace Graphics

}// namespace Lite
