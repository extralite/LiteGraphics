#pragma once

#include <cstdint>

namespace Lite {

    namespace Graphics {

        enum TextureFormat : uint32_t {
            RGBA = 0,
            BGRA = 1,
        };

        class Texture {
        private:
            uint32_t _Texture;
            uint32_t _Format;

        public:
            Texture(int32_t width, int32_t height, TextureFormat format);
            ~Texture();

            void Bind() const;
            void Unbind() const;

            void Data(int32_t width, int32_t height, uint8_t *data);
            void SubData(int32_t x, int32_t y, int32_t width, int32_t height, uint8_t *data);
        };

    }// namespace Graphics

}// namespace Lite
