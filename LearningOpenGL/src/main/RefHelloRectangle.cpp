#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "core/Shader.h"
#include "core/Window.h"
#include "core/Rectangle.h"


//window parameters
const unsigned int SCR_WIDTH = 800; 
const unsigned int SCR_HEIGHT = 600; 

int main(){

    Window window(SCR_WIDTH, SCR_HEIGHT, "Hello Rectangle!"); 

    // Load shaders
    Shader shader("../shaders/triangle.vs", "../shaders/triangle.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    //Call the rectangle object
    Rectangle rectangle(vertices, sizeof(vertices), indices, sizeof(indices), true);

     // Main loop
    while (!window.shouldClose()) {
        window.ProcessInput();

         // Render commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        rectangle.draw();
        
        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}