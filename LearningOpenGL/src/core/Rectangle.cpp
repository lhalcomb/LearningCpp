#include "core/Rectangle.h"

Rectangle::Rectangle(const float vertices[], size_t vertexCount,
                     const unsigned int indices[], size_t indexCount, bool wireframe)
    : numIndices(indexCount)
{
    // Generate VAO, VBO, EBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind VAO first
    glBindVertexArray(VAO);

    // Vertex data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_STATIC_DRAW);

    // Index data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    // Vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VBO (optional, EBO must stay bound to VAO)
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Unbind VAO
    glBindVertexArray(0);

    if (wireframe){
        //  to draw in wireframe polygons.
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
}

Rectangle::~Rectangle()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

Rectangle::Rectangle(Rectangle&& other) noexcept
    : VAO(other.VAO), VBO(other.VBO), EBO(other.EBO), numIndices(other.numIndices)
{
    other.VAO = other.VBO = other.EBO = 0;
    other.numIndices = 0;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept
{
    if (this != &other) {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);

        VAO = other.VAO;
        VBO = other.VBO;
        EBO = other.EBO;
        numIndices = other.numIndices;

        other.VAO = other.VBO = other.EBO = 0;
        other.numIndices = 0;
    }
    return *this;
}

void Rectangle::draw() const
{
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(numIndices), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
