#pragma once
#include <GLAD/glad.h>
#include <Resources/ShaderProgram.h>
#include <Resources/Texture2D.h>

class SpriteRenderer {
    public:
        SpriteRenderer();
        SpriteRenderer(ShaderProgram &shader);
        ~SpriteRenderer();

        void DrawSprite(Texture2D &texture, glm::vec2 position, 
            glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f, 
            glm::vec3 color = glm::vec3(1.0f), bool flipped = false);
    private:
        ShaderProgram shader; 
        GLuint quadVAO;

        void initRenderData();
};