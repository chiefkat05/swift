
#include "events.h"

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

event_handler ehandler;

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    ehandler.key_callback(window, key, scancode, action, mods);
}
// when British person sees images on the screen
void graphics_init()
{

}
