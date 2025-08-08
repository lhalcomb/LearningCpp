#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "core/Shader.h"
#include "core/Window.h"


//window parameters
const unsigned int SCR_WIDTH = 800; 
const unsigned int SCR_HEIGHT = 600; 

int main(){

    Window window(SCR_WIDTH, SCR_HEIGHT, "Hello Triangle!"); 

    // Load shaders
    Shader shader("../shaders/triangle1.vs", "../shaders/triangle1.fs");

    //set up triangle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left  
         0.5f, -0.5f, 0.0f, // right 
         0.0f,  0.5f, 0.0f  // top   
    };

    unsigned int VBO, VAO; // Vertex Buffer Object, Vertex Array Object
    glGenVertexArrays(1, &VAO); 
    glGenBuffers(1, &VBO); // Generate a buffer, // Generate a buffer after OpenGL context is created
    //bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind the newly created buffer to the GL_ARRAY_BUFFER target with the glBindBuffer function
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //at copies the previously defined vertex data into the buffer's memory
   
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); //linking the vertex shader attributes .... What is (void*)0? is it forcing the type of the paramter to be null?
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 

    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


     // Main loop
    while (!window.shouldClose()) {
        window.ProcessInput();

         // Render commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}