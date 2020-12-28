#include <Rendering/TextRenderer.h>
#include <ft2build.h>
#include <freetype/freetype.h>
#include <GLM/gtc/matrix_transform.hpp>
#include <iostream>

// TextRenderer::TextRenderer(GLuint width, GLuint height) {
//     // Load and configure shader
//     // this->TextShader = ShaderProgram("assets/text.vs", "assets/text.fs");
//     // this->TextShader.setMat4("projection", glm::ortho(0.0f, static_cast<GLfloat>(width), static_cast<GLfloat>(height), 0.0f));
//     // this->TextShader.setInt("text", 0);
//     // Configure VAO/VBO for texture quads
// }

// // void TextRenderer::Load(std::string font, GLuint fontSize)
// // {
// // }

// void TextRenderer::RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color)
// {
    // // Activate corresponding render state	
    // this->TextShader.bind();
    // this->TextShader.setVec3("textColor", color);
    // glActiveTexture(GL_TEXTURE0);
    // glBindVertexArray(this->VAO);

    // // Iterate through all characters
    // std::string::const_iterator c;
    // for (c = text.begin(); c != text.end(); c++) {
    //     Character ch = Characters[*c];

    //     GLfloat xpos = x + ch.Bearing.x * scale;
    //     GLfloat ypos = y + (this->Characters['H'].Bearing.y - ch.Bearing.y) * scale;

    //     GLfloat w = ch.Size.x * scale;
    //     GLfloat h = ch.Size.y * scale;
    //     // Update VBO for each character
    //     GLfloat vertices[6][4] = {
    //         { xpos,     ypos + h,   0.0, 1.0 },
    //         { xpos + w, ypos,       1.0, 0.0 },
    //         { xpos,     ypos,       0.0, 0.0 },

    //         { xpos,     ypos + h,   0.0, 1.0 },
    //         { xpos + w, ypos + h,   1.0, 1.0 },
    //         { xpos + w, ypos,       1.0, 0.0 }
    //     };

    //     // Render glyph texture over quad
    //     glBindTexture(GL_TEXTURE_2D, ch.TextureID);
    //     // Update content of VBO memory
    //     glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    //     glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // Be sure to use glBufferSubData and not glBufferData

    //     glBindBuffer(GL_ARRAY_BUFFER, 0);
    //     // Render quad
    //     glDrawArrays(GL_TRIANGLES, 0, 6);
    //     // Now advance cursors for next glyph
    //     x += (ch.Advance >> 6) * scale; // Bitshift by 6 to get value in pixels (1/64th times 2^6 = 64)
    // }
    // glBindVertexArray(0);
    // glBindTexture(GL_TEXTURE_2D, 0);
// }
