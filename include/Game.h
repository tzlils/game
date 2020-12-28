#pragma once
#include <Resources/Texture2D.h>
#include <Rendering/SpriteRenderer.h>
#include <Rendering/TextRenderer.h>
// #include <Resources/ResourceManager.h>
#include <GLFW/glfw3.h>
#include <Sound/SoundPlayer.h>
#include <pthread.h>

class Game {
    public:
        Game(int width, int height);
        ~Game();
        int width, height;
        void Init();
        void ProcessInput(GLFWwindow* window);
        void Update();
        void Render();
        // void CheckCollisions();
        // bool CollidesWithGround(glm::vec2 pos, glm::vec2 size);
    private:
        int TILEMUL = 4;
        int TILEWIDTH = 16;
        int TILEHEIGHT = 16;
        int groundHeight = 112;
        int resizeFrames;

        double lastTime;
        double deltaTime;
        double lastFrame;
        SpriteRenderer* renderer;
        TextRenderer* trenderer;
        ShaderProgram shader;
        Texture2D bg;
        Texture2D grass;
        Texture2D dirt;
        SoundPlayer snd;
        pthread_t *sndt;

        // ResourceManager* Manager;
};