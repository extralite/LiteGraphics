#include <xlite/LiteGraphics.hpp>
#include <glad/gl.h>

#include <iostream>

int LiteGraphics::Load() {
    int gl_version = gladLoaderLoadGL();

    if (!gl_version) {
        std::cerr << "Unable to load OpenGL" << std::endl;
        return 0;
    }

    const char *version = reinterpret_cast<const char *>(glGetString(GL_VERSION));
    std::cout << "Initialized LiteGraphics " << version << std::endl;

    return 1;
}
