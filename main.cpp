#include "graphics.h"

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
        return;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(50, 50, 1180, 620);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwSetKeyCallback(window, key_callback);

    graphics_init();
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

        ehandler.poll(); // for future reference, JAMES, this does not actually handle input 'requests'. It is used for handling messages SENT TO THE EVENT HANDLER. Stupid.

        glfwPollEvents();

        std::cout << "a key is " << ehandler.requestKeyState(GLFW_KEY_A) << "\n";

        if (ehandler.requestKeyState(GLFW_KEY_ESCAPE))
            glfwSetWindowShouldClose(window, true);
    }

    glfwTerminate();

    std::cout << "Game will close.\n"; // switch to x11 omigosh
    return 0;
}