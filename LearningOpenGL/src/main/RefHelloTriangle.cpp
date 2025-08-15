#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "core/Shader.h"
#include "core/Window.h"
#include "core/Triangle.h"


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

    // float vertices1[] = {
    //     // first triangle
    //     -0.9f, -0.5f, 0.0f,  // left 
    //     -0.0f, -0.5f, 0.0f,  // right
    //     -0.45f, 0.5f, 0.0f,  // top 
        
    // };

    // float vertices2[] = {
    //     // second triangle
    //      0.0f, -0.5f, 0.0f,  // left
    //      0.9f, -0.5f, 0.0f,  // right
    //      0.45f, 0.5f, 0.0f   // top 
    // };
    //Call the triangle object
    Triangle triangle(vertices, sizeof(vertices)/sizeof(float), false);
    //Triangle triangle1(vertices1, sizeof(vertices1), false);
    //Triangle triangle2(vertices2, sizeof(vertices2), false);

     // Main loop
    while (!window.shouldClose()) {
        window.ProcessInput();

         // Render commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        triangle.draw();
        //triangle1.draw();
        //triangle2.draw();
        
        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}