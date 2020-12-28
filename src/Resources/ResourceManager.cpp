#include <Resources/ResourceManager.h>
#include <map>
#include <string>
#include <ostream>
#include <iostream>
#include <memory>
#include <typeinfo>
#include <typeindex>

ResourceManager::ResourceManager() {
	// sets = std::make_unique<std::unordered_map<std::type_index, std::unique_ptr<IResourceSet>>>();
}

// void ResourceManager::registerFont	(std::string name) {
//     // First clear the previously loaded Characters
//     std::map<GLchar, Character> Characters;
//     // Then initialize and load the FreeType library
//     FT_Library ft;    
//     if (FT_Init_FreeType(&ft)) // All functions return a value different than 0 whenever an error occurred
//         std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;
//     // Load font as face
//     FT_Face face;
//     if (FT_New_Face(ft, font.c_str(), 0, &face))
//         std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;
//     // Set size to load glyphs as
//     FT_Set_Pixel_Sizes(face, 0, fontSize);
//     // Disable byte-alignment restriction
//     glPixelStorei(GL_UNPACK_ALIGNMENT, 1); 
//     // Then for the first 128 ASCII characters, pre-load/compile their characters and store them
//     for (GLubyte c = 0; c < 128; c++) // lol see what I did there 
//     {
//         // Load character glyph 
//         if (FT_Load_Char(face, c, FT_LOAD_RENDER))
//         {
//             std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
//             continue;
//         }
//         // Generate texture
//         GLuint texture;
//         glGenTextures(1, &texture);
//         glBindTexture(GL_TEXTURE_2D, texture);
//         glTexImage2D(
//             GL_TEXTURE_2D,
//             0,
//             GL_RED,
//             face->glyph->bitmap.width,
//             face->glyph->bitmap.rows,
//             0,
//             GL_RED,
//             GL_UNSIGNED_BYTE,
//             face->glyph->bitmap.buffer
//             );
//         // Set texture options
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
       
//         // Now store character for later use
//         Character character = {
//             texture,
//             glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
//             glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
//             face->glyph->advance.x
//         };
//         Characters.insert(std::pair<GLchar, Character>(c, character));
//     }
//     glBindTexture(GL_TEXTURE_2D, 0);
//     // Destroy FreeType once we're finished
//     FT_Done_Face(face);
//     FT_Done_FreeType(ft);
// }

// void ResourceManager::registerTexture(std::string name) {

// };

// void ResourceManager::registerShader (std::string name) {

// };

// Texture2D ResourceManager::getTexture() {

// }

// std::map<GLchar, Character> ResourceManager::getFont() {

// }

// ShaderProgram ResourceManager::getShader() {

// }