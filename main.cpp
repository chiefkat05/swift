#include "graphics.h"

void framebuffer_size_callback(GLFWwindow *win, int width, int height)
{
    glViewport(0, 0, width, height);
}

event_handler ehandler;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    ehandler.key_callback(window, key, scancode, action, mods);
}

int main()
{
    std::string input;
    std::cout << "Welcome to swift!\n";

    glfwInit();

    GLFWwindow *window = glfwCreateWindow(1280, 720, "swift", NULL, NULL);
    if (window == NULL)
    {
        std::cerr << "glfw window failed to open\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(50, 50, 1180, 620);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwSetKeyCallback(window, key_callback);

    shader shad("./shaders/main.vs", "./shaders/main.fs");
    graphics_init ginit;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ehandler.poll(); // for future reference, JAMES, this does not actually handle input 'requests'. It is used for handling messages SENT TO THE EVENT HANDLER. Stupid.

        glfwPollEvents();

        shad.use();
        ginit.draw();

        std::cout << "a key is " << ehandler.requestKeyState(GLFW_KEY_A) << "\n";

        if (ehandler.requestKeyState(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window, true);

        glfwSwapBuffers(window);
    }

    glfwTerminate();

    std::cout << "Game will close.\n"; // switch to x11 omigosh
    return 0;
}