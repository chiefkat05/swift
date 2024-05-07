
#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct shader
{
};

struct sprite
{
};

void framebuffer_size_callback(GLFWwindow *win, int width, int height)
{
    glViewport(50, 50, width - 100, height - 100);
}

// when British person sees images on the screen
void graphics_init()
{
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
    // gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    // glViewport(50, 50, 1180, 620);
    // glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
    }

    glfwTerminate();
}
