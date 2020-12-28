#pragma once
#include <GLAD/glad.h>
#include <string>

struct Texture2D {
    GLuint ID;
    GLuint Width, Height; // Width and height of loaded image in pixels
    GLuint Internal_Format; // Format of texture object
    GLuint Image_Format; // Format of loaded image
    // Texture configuration
    GLuint Wrap_S; // Wrapping mode on S axis
    GLuint Wrap_T; // Wrapping mode on T axis
    GLuint Filter_Min; // Filtering mode if texture pixels < screen pixels
    GLuint Filter_Max; // Filtering mode if texture pixels > screen pixels
};

namespace Texture {
    Texture2D loadFromFile(const std::string file, GLboolean alpha);
}