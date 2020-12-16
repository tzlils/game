#include <GLM/glm.hpp>
#include <Resources/Texture2D.h>
#include <Rendering/SpriteRenderer.h>

class GameObject {
    public:
        glm::vec2 position, size, velocity;
        glm::vec3 color;
        float rotation;
        Texture2D sprite;
        bool isStatic;
        bool flipped;

        GameObject();
        GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));
        virtual void Draw(SpriteRenderer* renderer);
        void Move(float delta);
        void drawVelocity(ShaderProgram shader);
};