#include "graphics.h"

shader::shader(const char *vertexPath, const char *fragmentPath)
{
    unsigned int vertexShader, fragmentShader;
    const char *vertexShaderSource;
    const char *fragmentShaderSource;

    std::ifstream huh;
    huh.open("events.h");
    if (!huh.is_open())
    {
        std::cout << ":(\n";
    }
    std::string str;
    while (std::getline(huh, str))
    {
        std::cout << str << std::endl;
    }

    std::ifstream vFile(vertexPath);
    std::ifstream fFile(fragmentPath);

    if (!vFile.is_open())
        std::cout << "vertex file opening error from file: " << vertexPath << "\n";
    if (!fFile.is_open())
        std::cout << "fragment file opening error from file: " << fragmentPath << "\n";

    std::string line, source;
    while (std::getline(vFile, line))
    {
        source += line + '\n';
    }
    vertexShaderSource = source.c_str();
    while (std::getline(fFile, line))
    {
        source += line + '\n';
    }
    fragmentShaderSource = source.c_str();

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    ID = glCreateProgram();

    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glUseProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void shader::use()
{
    glUseProgram(ID);
}

const float spriteVertices[] = {
    0.5, 0.5, 0.0,
    0.5, -0.5, 0.0,
    -0.5, -0.5, 0.0,
    -0.5, 0.5, 0.0};
const unsigned int spriteIndices[] = {
    0, 1, 3,
    1, 2, 3};
graphics_init::graphics_init()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(spriteVertices), spriteVertices, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(spriteIndices), spriteIndices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
}
void graphics_init::draw()
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}