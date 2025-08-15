#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>     
#include "core/Window.h"
#include "core/Shader.h"

//window parameters
const unsigned int SCR_WIDTH = 400; 
const unsigned int SCR_HEIGHT = 400; 

#include <cmath>
#define SQRT3 sqrt(3)


int main(){

    Window window(SCR_WIDTH, SCR_HEIGHT, "Triforce!!"); 
    Shader shader("../shaders/triangle1.vs", "../shaders/ytriangle.fs");

    float cSqrt3 = static_cast<float>(SQRT3); 

    float vertices[] = {
        // left triangle - wisdom
        -1.0f, -cSqrt3/2, 0.0f,  // left 
        0.0f, -cSqrt3/2, 0.0f,  // right
        -0.5f, 0.0f, 0.0f,  // top 

        // right triangle - time
         0.0f, -cSqrt3/2, 0.0f,  // left
         1.0f, -cSqrt3/2, 0.0f,  // right
         0.5f, 0.0f, 0.0f,   // top 

         //top triangle - courage
         -0.5f, 0.0f, 0.0f,  // left
         0.5f, 0.0f, 0.0f,  // right
         0.0f, cSqrt3/2, 0.0f   // top 
    };
    

    unsigned int VBO, VAO; // Vertex Buffer Object, Vertex Array Object
    glGenVertexArrays(1, &VAO); 
    glGenBuffers(1, &VBO); // Generate a buffer, // Generate a buffer after OpenGL context is created
    //bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);
    // 0. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind the newly created buffer to the GL_ARRAY_BUFFER target with the glBindBuffer function
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //at copies the previously defined vertex data into the buffer's memory
    // 1. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); //linking the vertex shader attributes .... What is (void*)0? is it forcing the tyoe of the paramter to be null?
    glEnableVertexAttribArray(0);

    /* ---- do this process (0, 1, 2, 3) for everytime you want to draw an object, but there is a better way. */
    // 2. use our shader program when we want to render an object
    //glUseProgram(shaderProgram);
    // 3. now draw the object
    // -------------------------------------- instead do this with steps 0, 1

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 

     // Main loop
    while (!window.shouldClose()) {
        window.ProcessInput();

         // Render commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 9); 
        
        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}