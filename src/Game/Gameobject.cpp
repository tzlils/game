#include <Game/Gameobject.h>
#include <Rendering/LineRenderer.h>

GameObject::GameObject() {

}

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, glm::vec3 color, glm::vec2 velocity) {
    // this->position = pos;
    // this->size = size;
    // this->sprite = sprite;
    // this->color = color;
    // this->velocity = velocity;
    // this->isStatic = false;
}

void GameObject::Draw(SpriteRenderer* renderer) {
    renderer->DrawSprite(sprite, position, size, rotation, color, flipped);
}

void GameObject::Move(float delta) {
    this->position += this->velocity;

    this->velocity.x = 0;
    this->velocity.y = 0;
    if(!isStatic) this->velocity.y += 9;
}

void GameObject::drawVelocity(ShaderProgram shader) {
    drawLine(shader, position+(size*glm::vec2(0.5f, 0.5f)), velocity*size);
}