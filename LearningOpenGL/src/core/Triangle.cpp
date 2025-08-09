#include "core/Triangle.h"

Triangle::Triangle(const float vertices[], size_t vertexCount, bool wireframe)
    /*
    float vertices[] - set up triangle with Normalized Device Coordinates
    size_t vertexCount - the size of the vertices float array 
    bool wireframe - Draw the outline of the triangle - true, Fill in Triangle - false
    */
{   
    this->vertexCount = vertexCount;
    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind VAO first
    glBindVertexArray(VAO);

    // Bind and fill VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(
        0,                  // Attribute location in shader (layout(location = 0))
        3,                  // Number of components per vertex attribute (x, y, z)
        GL_FLOAT,           // Data type
        GL_FALSE,           // Normalize?
        3 * sizeof(float),  // Stride (distance between consecutive vertex attributes)
        (void*)0            // Offset from start of data
    );
    glEnableVertexAttribArray(0);

    // Unbind VBO (optional)
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // Unbind VAO (optional)
    glBindVertexArray(0);

    if (wireframe){
        //  to draw in wireframe polygons.
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

}

Triangle::~Triangle() {
    // Cleanup GPU resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
};

void Triangle::draw() const {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount / 3); // vertexCount is number of floats, so /3 for actual vertices
    glBindVertexArray(0);
};