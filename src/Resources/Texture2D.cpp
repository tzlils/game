#include <iostream>
#include <Resources/Texture2D.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


// Texture2D::Texture2D()
//     : Width(0), Height(0), Internal_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_NEAREST), Filter_Max(GL_NEAREST)
// {
//     glGenTextures(1, &this->ID);
// }

// void Texture2D::Generate(GLuint width, GLuint height, unsigned char* data) {
// }

// void Texture2D::Bind() const {
//     glBindTexture(GL_TEXTURE_2D, this->ID);
// }

namespace Texture {
    Texture2D loadFromFile(const std::string file, GLboolean alpha) {
        // Create Texture object
        Texture2D texture;
        texture.Internal_Format = GL_RGB;
        texture.Image_Format = GL_RGB;
        texture.Wrap_S = GL_REPEAT;
        texture.Wrap_T = GL_REPEAT;
        texture.Filter_Min = GL_NEAREST;
        texture.Filter_Max = GL_NEAREST;
        if (alpha) {
            texture.Internal_Format = GL_RGBA;
            texture.Image_Format = GL_RGBA;
        }
        // Load image
        int width, height, channels;
        unsigned char *data = stbi_load(file.c_str(), &width, &height, &channels, 0); 
        // Now generate texture
        // texture.Generate(width, height, data);

        glGenTextures(1, &texture.ID);

        texture.Width = width;
        texture.Height = height;
        // Create Texture
        glBindTexture(GL_TEXTURE_2D, texture.ID);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 
        glTexImage2D(GL_TEXTURE_2D, 0, texture.Internal_Format, width, height, 0, texture.Image_Format, GL_UNSIGNED_BYTE, data);
        // Set Texture wrap and filter modes
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, texture.Wrap_S);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, texture.Wrap_T);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, texture.Filter_Min);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, texture.Filter_Max);
        // Unbind texture
        glBindTexture(GL_TEXTURE_2D, 0);
        // And finally free image data
        stbi_image_free(data);
        return texture;
    }
}