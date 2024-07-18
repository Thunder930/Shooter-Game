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
    glfwSetFramebufferSizeCallback(window, resizeCallback);
}

void Load() {
    Battleship* player = new Battleship(SHIP_START_X, SHIP_START_Y, false, renderables);
    renderables.push_back(player);
    collidables.push_back(player);
    Battleship* enemy = new Battleship(0.7f, 0.0f, true, renderables);
    renderables.push_back(enemy);
    collidables.push_back(enemy);
}

void Render(double deltaTime)
{
    // Put all rendering objects here
    for (int i = 0; i < renderables.size(); i++) {
        renderables[i]->Render();
        renderables[i]->Update(deltaTime);
    }
}

void Collide() {
    for (int i = 0; i < collidables.size(); i++) {
        for (int j = 0; j < collidables.size() && j != i; j++) {
            if (collidables[i]->IsColliding(collidables[j]->GetDimensions())) {
                collidables[i]->Collide();
            }
        }
        collidables[i]->Update(collidables);
    }
}

void Update(GLFWwindow*& window, double deltaTime) {
    // Update the posotions/states of everything. Use deltaTime to ensure that nothing is tied to frame rate.
    Render(deltaTime);
    Collide();
    ProcessInput(window, deltaTime);
}

void UnLoad() {
    // Free anything that was malloced
    renderables.clear();
    glfwTerminate();
}

void ProcessInput(GLFWwindow *window, double deltaTime) {
    Battleship* player = (Battleship*)renderables[0];
    // Example of getting a key state
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        player->Move(true, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        player->Move(false, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        player->Fire(collidables);
    }
}

void resizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}