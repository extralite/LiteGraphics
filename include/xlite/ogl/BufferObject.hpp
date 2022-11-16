#pragma once

#include <cstdint>
#include <vector>

namespace Lite {

    namespace Graphics {

        enum BufferObjectType : uint32_t {
            VertexArray = 0,
            ElementArray = 1,
        };

        template<typename _T, BufferObjectType _Ty>
        class BufferObject {
        private:
            uint32_t _Object;
            uint32_t _Size;
            uint32_t _Type;

        public:
            BufferObject();
            ~BufferObject();

            void Bind() const;
            void Unbind() const;

            void Data(std::vector<_T> data);

            uint32_t Size() const {
                return _Size;
            }
        };

    }// namespace Graphics

}// namespace Lite
