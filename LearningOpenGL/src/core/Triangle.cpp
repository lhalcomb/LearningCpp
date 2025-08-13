#include "core/Triangle.h"

Triangle::Triangle(const float vertices[], size_t vertexCount, bool wireframe)
    /*
    float vertices[] - set up triangle with Normalized Device Coordinates
    size_t vertexCount - the size of the vertices float array 
    bool wireframe - Draw the outline of the triangle - true, Fill in Triangle - false
    */
{   
    this->vertexCount = vertexCount;

    // Auto-detect attributes based on vertexCount
    bool hasColor = false;
    bool hasTexCoords = false;

    if (vertexCount == 18) { // positions + colors
        hasColor = true;
    }
    else if (vertexCount == 24) { // positions + colors + texcoords
        hasColor = true;
        hasTexCoords = true;
    }

    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind VAO first
    glBindVertexArray(VAO);

    // Bind and fill VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), vertices, GL_STATIC_DRAW);

    size_t strideComponents = 3; // always have position

    if (hasColor) strideComponents += 3;
    if (hasTexCoords) strideComponents += 2;

    size_t stride = strideComponents * sizeof(float);

     // Position attribute
    // Set vertex attribute pointers
    glVertexAttribPointer(
        0,                  // Attribute location in shader (layout(location = 0))
        3,                  // Number of components per vertex attribute (x, y, z)
        GL_FLOAT,           // Data type
        GL_FALSE,           // Normalize?
        stride,              // Stride (distance between consecutive vertex attributes)
        (void*)0            // Offset from start of data
    );
    glEnableVertexAttribArray(0); //enable vertices

    size_t offset = 3 * sizeof(float);

    if (hasColor) {
    // Set vertex attribute pointers
        glVertexAttribPointer(
            1,                  // Attribute location in shader (layout(location = 1))
            3,                  // Number of components per vertex attribute (r, g, b)
            GL_FLOAT,           // Data type
            GL_FALSE,           // Normalize?
            stride,             // Stride (distance between consecutive vertex attributes)
            (void*)offset            // Offset from start of data
        );
        glEnableVertexAttribArray(1); //enable colors
        
        offset += 3 * sizeof(float);
    }

    if (hasTexCoords) {
        // Set vertex attribute pointers
            glVertexAttribPointer(
                2,                  // Attribute location in shader (layout(location = 2))
                3,                  // Number of components per vertex attribute 
                GL_FLOAT,           // Data type
                GL_FALSE,           // Normalize?
                stride,             // Stride (distance between consecutive vertex attributes)
                (void*)offset           // Offset from start of data
            );
        glEnableVertexAttribArray(2); //enable texture
        
    }

    
    

    if (vertexCount == 18){
         
    };
   

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
    glDrawArrays(GL_TRIANGLES, 0, vertexCount / (vertexCount / 3)); // vertexCount is number of floats, so /3 for actual vertices
    glBindVertexArray(0);
};