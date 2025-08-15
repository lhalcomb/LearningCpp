#include "core/Triangle.h"
#include <iostream>


Triangle::Triangle(const float vertices[], size_t vertexCount, bool wireframe): Triangle(vertices, vertexCount, nullptr, 0, wireframe) {}

Triangle::Triangle(const float vertices[], size_t vertexCount, const unsigned int indices[], size_t indexCount, bool wireframe)
    /*
    float vertices[] - set up triangle with Normalized Device Coordinates
    size_t vertexCount - the size of the vertices float array 
    bool wireframe - Draw the outline of the triangle - true, Fill in Triangle - false
    */
{   
    this->vertexCount = vertexCount;
    this->indexCount = indexCount;
    this->hasIndices = (indices != nullptr && indexCount > 0);
    
    // ----- Auto-detect floats per vertex -----
    size_t floatsPerVertex = 3; // minimum is position (x,y,z)
    {
        // Try to guess from common layouts
        if (vertexCount % 8 == 0) {          // pos(3) + color(3) + tex(2)
            floatsPerVertex = 8;
        } else if (vertexCount % 6 == 0) {   // pos(3) + color(3)
            floatsPerVertex = 6;
        } else if (vertexCount % 5 == 0) {   // pos(3) + tex(2)
            floatsPerVertex = 5;
        }
    }

    // Infer attributes from floats per vertex
    bool hasColor = (floatsPerVertex >= 6);
    bool hasTexCoords = (floatsPerVertex == 5 || floatsPerVertex == 8);
    
    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    if (hasIndices) glGenBuffers(1, &EBO);

    // Bind VAO first
    glBindVertexArray(VAO);

    // Bind and fill VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_STATIC_DRAW);

    // EBO if needed
    if (hasIndices) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    }


    // ----- Vertex attribute pointers -----
    size_t stride = floatsPerVertex * sizeof(float);
    size_t offset = 0;

     // Position attribute
    // Set vertex attribute pointers
    glVertexAttribPointer(
        0,                  // Attribute location in shader (layout(location = 0))
        3,                  // Number of components per vertex attribute (x, y, z)
        GL_FLOAT,           // Data type
        GL_FALSE,           // Normalize?
        stride,             // Stride (distance between consecutive vertex attributes)
        (void*)offset           // Offset from start of data
    );
    glEnableVertexAttribArray(0); //enable vertices
    offset += 3 * sizeof(float);
    

    if (hasColor) {
    // Set vertex attribute pointers
        glVertexAttribPointer(
            1,                  // Attribute location in shader (layout(location = 1))
            3,                  // Number of components per vertex attribute (r, g, b)
            GL_FLOAT,           // Data type
            GL_FALSE,           // Normalize?
            stride,             // Stride (distance between consecutive vertex attributes)
            (void*)(offset)     // Offset from start of data
        );
        glEnableVertexAttribArray(1); //enable colors
        
        offset += 3 * sizeof(float);
    }

    if (hasTexCoords) {
        // Set vertex attribute pointers
            glVertexAttribPointer(
                2,                  // Attribute location in shader (layout(location = 2))
                2,                  // Number of components per vertex attribute 
                GL_FLOAT,           // Data type
                GL_FALSE,           // Normalize?
                stride,             // Stride (distance between consecutive vertex attributes)
                (void*)(offset)       // Offset from start of data
            );
        glEnableVertexAttribArray(2); //enable texture
        offset += 2 * sizeof(float);
    }

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
    if (hasIndices) glDeleteBuffers(1, &EBO);
};

void Triangle::draw() const {
    glBindVertexArray(VAO);
    if (hasIndices){
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
    }else{
    
        size_t floatsPerVertex = 3;
        if (vertexCount % 8 == 0) floatsPerVertex = 8;
        else if (vertexCount % 6 == 0) floatsPerVertex = 6;
        else if (vertexCount % 5 == 0) floatsPerVertex = 5;
        size_t numVertices = vertexCount / floatsPerVertex;
        glDrawArrays(GL_TRIANGLES, 0, numVertices);
    }
    glBindVertexArray(0);
};