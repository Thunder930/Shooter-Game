#include "main.h"
#include "defines.h"

int main(int argc, char** argv)
{
    GLFWwindow *window;

    InitGraphics(window);

    Load();

    glfwSwapBuffers(window);

    double time = glfwGetTime();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        double deltaTime = glfwGetTime() - time;
        time = glfwGetTime();

        Render(deltaTime);

        Update(window, deltaTime);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
  
    }
    UnLoad();
    return 0;
}

void InitGraphics(GLFWwindow*& window) {
    /* Initialize the library */
    if (!glfwInit()) {
        fprintf(stderr, "Error: failed to initalize GLEW");
        exit(-1);
    }
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Shooter Game", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Error: failed to create window");
        glfwTerminate();
        exit(-1);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        exit(-1);
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

}

void Load() {
    renderables.push_back(new Ship(SHIP_START_X, SHIP_START_Y));
}

void Render(double deltaTime)
{
    // Put all rendering objects here
    for (int i = 0; i < renderables.size(); i++) {
        renderables[i]->Render();
        renderables[i]->Update(deltaTime, renderables);
    }
}

void Update(GLFWwindow*& window, double deltaTime) {
    // Update the posotions/states of everything. Use deltaTime to ensure that nothing is tied to frame rate.
    ProcessInput(window, deltaTime);
}

void UnLoad() {
    // Free anything that was malloced
    renderables.clear();
    glfwTerminate();
}

void ProcessInput(GLFWwindow *window, double deltaTime) {
    Ship* ship = (Ship*)renderables[0];
    // Example of getting a key state
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        ship->Move(true, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        ship->Move(false, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        ship->Fire(renderables);
    }
}