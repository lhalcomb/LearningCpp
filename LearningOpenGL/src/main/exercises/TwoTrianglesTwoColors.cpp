#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>     
#include "core/Window.h"
#include "core/Shader.h"
#include "core/Triangle.h"

//window parameters
const unsigned int SCR_WIDTH = 800; 
const unsigned int SCR_HEIGHT = 600; 


int main(){

    Window window(SCR_WIDTH, SCR_HEIGHT, "Hello Window!"); 
     // Load shaders
    Shader YellowShader("../shaders/triangle1.vs", "../shaders/ytriangle.fs");
    Shader OrangeShader("../shaders/triangle1.vs", "../shaders/triangle1.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------


    float vertices1[] = {
        // first triangle
        -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top 
        
    };

    float vertices2[] = {
        // second triangle
         0.0f, -0.5f, 0.0f,  // left
         0.9f, -0.5f, 0.0f,  // right
         0.45f, 0.5f, 0.0f   // top 
    };


    Triangle OrangeTriangle(vertices1, sizeof(vertices1), false);
    Triangle YellowTriangle(vertices2, sizeof(vertices2), false);

     // Main loop
    while (!window.shouldClose()) {
        window.ProcessInput();

         // Render commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

         
        YellowShader.use();
        YellowTriangle.draw();

        OrangeShader.use();
        OrangeTriangle.draw();
        

        
        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}