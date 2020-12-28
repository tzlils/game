#pragma once
#include <map>
#include <GLAD/glad.h>
#include <GLM/glm.hpp>


struct Character {
    GLuint TextureID;   // ID handle of the glyph texture
    glm::ivec2 Size;    // Size of glyph
    glm::ivec2 Bearing; // Offset from baseline to left/top of glyph
    GLuint Advance;     // Horizontal offset to advance to next glyph
};

typedef struct {
	std::map<char, Character> Characters; 
} Font;

namespace Text {
	Font loadFromFile(const std::string file, unsigned int fontSize);
	void Render(Font font, std::string text, float x, float y, float scale = 1.0, glm::vec3 color = glm::vec3(1.0));
}