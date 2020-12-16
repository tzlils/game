#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLAD/glad.h>
#include <Rendering/LineRenderer.h>

void drawLine(ShaderProgram shader, glm::vec2 p1, glm::vec2 p2) {
    GLuint VBO;
    GLuint VAO;
    GLfloat vertices[] = { 
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,
    
        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);  
    glBindVertexArray(0);

    shader.bind();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(p1, 0.0f));  
    model = glm::scale(model, glm::vec3(p2, 1.0f));

    shader.setMat4("model", model);
    shader.setVec3("spriteColor", glm::vec3(0.5f));

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 6);
    glBindVertexArray(0);
}