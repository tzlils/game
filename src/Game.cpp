#include <Game.h>
#include <Resources/ShaderProgram.h>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <Rendering/LineRenderer.h>
#include <Sound/SoundPlayer.h>
// #include <Resources/ResourceManager.h>
#include <sstream>
#include <thread>
#include <string>

Game::Game(int w, int h) {
    width = w;
    height = h;
}

/**
    **Game::Init()
    *Initializes the main game class
*/
void Game::Init() {
    glm::mat4 projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);

    shader = ShaderProgram("assets/screen.vs", "assets/screen.fs");
    renderer = new SpriteRenderer(shader);

    // snd = SoundPlayer();
    // snd.Init();

    /*
        Prepare Shader
    */
    shader.bind();
    shader.setInt("image", 0);
    shader.setMat4("projection", projection);


    /*
        Prepare Text Shader
    */
    ShaderProgram textShader = ShaderProgram("assets/text.vs", "assets/text.fs");
    textShader.bind();
    textShader.setMat4("projection", projection);
    textShader.setInt("text", 0);
    trenderer = new TextRenderer(width, height);

    /*
        *Prepare Text Renderer and load in font (assets/Super-Mario-World.tff)
    */
    trenderer->TextShader = textShader;
    trenderer->Load("assets/SMW Text NC.ttf", 48);

    /*
        *Loads some textures for drawing layer 1
    */
    bg = loadTextureFromFile("assets/background.png", true);
    grass = loadTextureFromFile("assets/grass.png", true);
    dirt = loadTextureFromFile("assets/dirt.png", true);
    resizeFrames = 0;

    // objIndex = 0;
    // player = Player();
    // player.position.x = width/2;
    // player.position.y = height/2;
    // objects[objIndex] = GameObject(glm::vec2(width/2, height/2), glm::vec2(16, 24), idle);
    // objects[objIndex].isStatic = false;
    // objIndex += 1;

    // objects[objIndex] = GameObject(glm::vec2(0, height-groundHeight+1), glm::vec2(width, groundHeight-1), dirt);
    // objects[objIndex].isStatic = true;
    // objIndex += 1;

    // Manager = new ResourceManager();

    // Manager->set<int>("num", 4);
    // printf("num = %i\n", Manager->get<int>("num"));

    // Manager->set<Texture2D>("bg", loadTextureFromFile("assets/background.png", true)); 

}

void Game::ProcessInput(GLFWwindow* window) {
    bool keyExit  = (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS);
    bool keyRight = (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS);
    bool keyLeft  = (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS);
    bool keyUp    = (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS);
    // bool keyDown  = (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS);
    bool keyPlus  = (glfwGetKey(window, GLFW_KEY_LEFT_BRACKET) == GLFW_PRESS);
    bool keyMinus = (glfwGetKey(window, GLFW_KEY_RIGHT_BRACKET) == GLFW_PRESS);
    bool keyJump  = (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS);
    // float speed = 20.0f;

    if(keyExit) glfwSetWindowShouldClose(window, true);
    if(keyRight) {
        // player.direction = true;
        // if(player.velocity.x < speed) {
        //     player.velocity.x += 1.5;
        // }
    }
    if(keyLeft)  {
        // player.direction = false;
        // if(player.velocity.x > -speed) {
        //     player.velocity.x -= 1.5;
        // }
    }
    if(!keyLeft && !keyRight && keyUp) {
        // player.current = player.textures["looking_up"];
    }
    if(keyPlus && resizeFrames <= 0) {
        // player.position.y -= TILEHEIGHT*TILEMUL;
        // TILEMUL += 1;
        // resizeFrames = 50;
    }
    if(keyMinus && resizeFrames <= 0) {
        TILEMUL -= 1;
        // resizeFrames = 50;
    }
    if(keyJump) {
        // player.Jump();
    }

    resizeFrames -= 1;
    // if(keyDown) {
    //     if(!crouching) {
    //         objects[0].position.y -= 8;
    //     }

    //     crouching = true;
    //     objects[0].sprite = crouch;
    //     objects[0].size.y = 16*scale;
    //     objects[0].velocity.x /= 2;
    // } else {
    //     if(crouching) {
    //         objects[0].position.y -= 24;
    //     }
    //     crouching = false;
    // }
}


/**
 * * Game::Update()
 * Should check collisions and update sprites + update delta time
*/
void Game::Update() {
    // pthread_create(sndt, NULL, snd.PlayFrame, NULL);
    // pthread_create(sndt, NULL, &SoundPlayer::send_wrapper, &snd);
    // CheckCollisions();
    // player.Update();
    // for (int i = 0; i < 64; i++) {
    //     objects[i].Move(0);
    // }
}

/**
 * * Game::Render()
 * Should render all tiles and sprites
*/
void Game::Render() {
    // Calculate FPS
    double currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    renderer->DrawSprite(bg, glm::vec2(0, 0), glm::vec2(width, height), 0.0f);
    // renderer->DrawSprite(dirt, glm::vec2(width/2, height/2), glm::vec2(50, 50), 0.0f);    
    // for (int i = 0; i < objIndex; i++) {
    //     objects[i].Draw(renderer);
    // }

    for (int x = width; x > 0; x-=TILEWIDTH*TILEMUL) {
        for (int y = groundHeight; y > 0; y-=TILEHEIGHT*TILEMUL) {
            if(y >= groundHeight) {
                renderer->DrawSprite(grass, glm::vec2(x-TILEWIDTH*TILEMUL, height-y+1), glm::vec2(TILEWIDTH*TILEMUL, TILEHEIGHT*TILEMUL), 0.0f);
            } else {
                renderer->DrawSprite(dirt, glm::vec2(x-TILEWIDTH*TILEMUL, height-y), glm::vec2(TILEWIDTH*TILEMUL, TILEHEIGHT*TILEMUL), 0.0f);
            }
        }        
    }

    // player.size.x = player.current.Width*TILEMUL;
    // player.size.y = player.current.Height*TILEMUL;

    // std::stringstream yvelocity;
    // yvelocity << "YVEL: " << player.velocity.y;
    // trenderer->RenderText(yvelocity.str(), 20, 20, 0.5f, glm::vec3(0.0f));

    // std::stringstream xvelocity;
    // xvelocity << "XVEL: " << player.velocity.x;
    // trenderer->RenderText(xvelocity.str(), 20, 40, 0.5f, glm::vec3(0.0f));

    std::stringstream fps;
    fps << "FPS: " << (unsigned int)round(1 / deltaTime);
    trenderer->RenderText(fps.str(), height, width, 2.0f, glm::vec3(0.0f));

    // player.Draw(renderer);
    // drawLine(shader, player.position+(player.size*glm::vec2(0.5f, 0.5f)), player.velocity*15.5f);
}

bool CheckCollision(glm::vec2 pos1, glm::vec2 size1, glm::vec2 pos2, glm::vec2 size2) {
    // Collision x-axis?
    bool collisionX = pos1.x + size1.x >= pos2.x &&
        pos2.x + size2.x >= pos1.x;
    // Collision y-axis?
    bool collisionY = pos1.y + size1.y >= pos2.y &&
        pos2.y + size2.y >= pos1.y;

    // if(one.position.x < two.position.x + two.size.x &&
    // one.position.x + one.size.x > two.position.x && one.position.y <
    // two.position.y + two.size.y && one.position.y + one.size.y >
    // two.position.y) {
    //     printf("collision");
    // }
    // if(one.position.x < two.position.x) {
    // printf("1: %f 2: %f\n", one.position.x, two.position.x);
    // }
    // Collision only if on both axes
    return collisionX && collisionY;
}  

// bool Game::CollidesWithGround(glm::vec2 pos, glm::vec2 size) {
//     return CheckCollision(objects[0].position, objects[0].size, pos, size);
// }

/**
    * ! Deprecated
    * Runs collision detection on all objects
*/
// void Game::CheckCollisions() {
//     bool collided;
//     for (int i = 0; i <= objIndex-1; i++) {
//         for (int j = i+1; j <= objIndex-1; j++){
//             // collided = CheckCollision(objects[i], objects[j]);
//             if(collided) {
//                 objects[i].velocity.y -= 9;
//                 // printf("collision!\n");
//                 break;
//             }
//         }
//     }
// }