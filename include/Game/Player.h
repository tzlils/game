#pragma once
#include <GLM/glm.hpp>
#include <Rendering/SpriteRenderer.h>
#include <Resources/Texture2D.h>
#include <map>
#include <string>

class Player {
    public:
        glm::vec2 position;
        glm::vec2 velocity;
        glm::vec2 size;
        bool direction;
        int runningframes;
        double jumpframes;
        bool onGround;
        float acceleration;
        float airTime;
        float HFRICTION;
        float VFRICTION;

        double enteredAir;


        ShaderProgram shader;


        std::map<std::string, Texture2D> textures; 
        Texture2D current;

        Player();
        void Update();
        void Draw(SpriteRenderer* renderer);
        void Jump();
};