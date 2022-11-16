#pragma once

#include <cstdint>

namespace Lite {

    namespace Graphics {

        class VertexArrayObject {
        private:
            uint32_t _Object;
            uint32_t _AttribLength;

        public:
            VertexArrayObject();
            ~VertexArrayObject();

            void Bind() const;
            void Unbind() const;

            void Attrib(int32_t size, int32_t length, int32_t offset);

            void DrawArrays(uint32_t count);
            void DrawElements(uint32_t count);
        };

    }// namespace Graphics

}// namespace Lite
