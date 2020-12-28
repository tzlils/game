#include <GLAD/glad.h>
#define GLFW_DLL
#include <GLFW/glfw3.h>
#include <Game.h>
#include <Main.h>

#define WIDTH 500
#define HEIGHT 500

GLFWwindow* window;
float x, y;

void initGL() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "TCraft", NULL, NULL);
    if(window == NULL) {
        printf("Error");
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("Failed to initialize GLAD");
    }
}

int main() {
    initGL();
    glViewport(0, 0, WIDTH, HEIGHT);
    glClearColor(0.37f, 0.71f, 1.0f, 1.0f);
    glEnable(GL_BLEND);
    // glfwSwapInterval(0);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    game = new Game(WIDTH, HEIGHT);
    game->Init();

    while(!glfwWindowShouldClose(window)) {
        game->Update();
        game->ProcessInput(window);
        glClear(GL_COLOR_BUFFER_BIT);
        game->Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
