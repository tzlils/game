#include <Game/Player.h>
#include <Resources/Texture2D.h>
#include <Rendering/LineRenderer.h>

Player::Player() {
    // textures.insert(std::make_pair("idle", loadTextureFromFile("assets/idle.png", true)));
    // textures.insert(std::make_pair("crouch", loadTextureFromFile("assets/crouch.png", true)));
    // textures.insert(std::make_pair("moving", loadTextureFromFile("assets/moving.png", true)));
    // textures.insert(std::make_pair("looking_up", loadTextureFromFile("assets/looking_up.png", true)));
    // textures.insert(std::make_pair("jump", loadTextureFromFile("assets/jump.png", true)));
    // textures.insert(std::make_pair("fall", loadTextureFromFile("assets/fall.png", true)));
    current = textures["idle"];
    position = glm::vec2(0.0f);
    velocity = glm::vec2(0.0f);
    size = glm::vec2(current.Width, current.Height);
    runningframes = 0;
    jumpframes = 0;
    HFRICTION = 0.92;
    VFRICTION = 0.4;
}

void Player::Jump() {
    if(onGround && airTime <= 0) {
        velocity.y = -12.0f;
        HFRICTION = 0.84;
    }
}

void Player::Update() {

    //Apply friction
    if(std::abs(velocity.x) < 0.05) velocity.x = 0;
    else velocity.x *= HFRICTION;
    // if(abs(velocity.y) < 0.05) velocity.y = 0;
    // else velocity.y *= FRICTION;
    // if(velocity.x > 0) velocity.x -= velocity.x/FRICTION;
    // else if(velocity.x < 0) velocity.x += velocity.x/-FRICTION;
    // if(velocity.y > 0) velocity.y -= velocity.y/-12;
    // if(velocity.y < 0) velocity.y += velocity.y/-12;

    // velocity.y += 2.f*(glfwGetTime()-enteredAir);
    // if(game->CollidesWithGround(position+velocity, size)) {
    //     onGround = true;
    //     airTime = 0;
    //     velocity.y = 0;
    //     HFRICTION = 0.92;
    //     position += glm::vec2(velocity.x, 0.0f);
    //     enteredAir = glfwGetTime();
    // } else {
    //     // printf("Ground: %i\n", onGround);
    //     // if(!onGround) return;
    //     // HFRICTION = 0.5;
    //     airTime += 0.01;
    //     position += velocity;
    //     onGround = false;
    //     if(!game->CollidesWithGround(position, size)) { }
    // }

    // if(abs(velocity.x) > 0 && runningframes < 6) {
    //     runningframes -= 1;
    //     if(runningframes <= 0) runningframes = 10;
    //     current = textures["moving"];
    // } else {
    //     current = textures["idle"];
    //     runningframes -= 1;
    // }

    // if(velocity.y < 0) {
    //     current = textures["jump"];
    // } else if(velocity.y > 0) {
    //     current = textures["fall"];
    // }
}

void Player::Draw(SpriteRenderer* renderer) {
    renderer->DrawSprite(current, position, size, 0.0f, glm::vec3(1.0f), direction);
}
