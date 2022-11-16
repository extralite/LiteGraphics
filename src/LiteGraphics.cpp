#include <xlite/LiteGraphics.hpp>

#include <glad/gl.h>

#include <iostream>

int Lite::Graphics::Load() {
    int gl_version = gladLoaderLoadGL();

    if (!gl_version) {
        std::cerr << "Unable to load OpenGL" << std::endl;
        return 0;
    }

    const char *version = reinterpret_cast<const char *>(glGetString(GL_VERSION));
    std::cout << "Initialized LiteGraphics OpenGL " << version << std::endl;

    return 1;
}

void Lite::Graphics::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Lite::Graphics::ClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Lite::Graphics::EnableDepthTesting() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearDepth(1.f);
}

void Lite::Graphics::EnableBlending() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
}

void Lite::Graphics::EnableTexture2D() {
    glEnable(GL_TEXTURE_2D);
}

void Lite::Graphics::ViewPort(int32_t x, int32_t y, int32_t width, int32_t height) {
    glViewport(x, y, width, height);
}
