
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

// when British person sees images on the screen
void graphics_init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
