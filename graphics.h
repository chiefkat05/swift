
#include "events.h"
#include <fstream>

struct shader
{
    unsigned int ID;

    shader(const char *vertexPath, const char *fragmentPath);

    void use();

    void set_bool(const std::string &name, bool v) const;
    void set_int(const std::string &name, int v) const;
    void set_float(const std::string &name, float v) const;
};

struct sprite
{
};

// when British person sees images on the screen
class graphics_init
{
public:
    graphics_init();
    void draw();

private:
    unsigned int VBO, VAO, EBO, shaderProgram;
};