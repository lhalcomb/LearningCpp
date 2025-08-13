#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>     
#include "core/Window.h"
#include "core/Shader.h"
#include "core/Triangle.h"

//window parameters
const unsigned int SCR_WIDTH = 800; 
const unsigned int SCR_HEIGHT = 600; 


int main(){

    Window window(SCR_WIDTH, SCR_HEIGHT, "Uniform Offset Exercise"); 
    //Shader shader("../shaders/triangle1.vs", "../shaders/firstuniform.fs");
    Shader shader("../shaders/offsetvalue.vs", "../shaders/colorvalue.fs");

    unsigned int shaderProgram = shader.getID();
    float offset = 0.5f;
    


    float vertices[] = {
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
         0.0f,  0.5f, 0.0f   // top 
    };

    float vertsNcolors[] = {
        // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
     };

    //Triangle triangle(vertices, sizeof(vertices), false);
    Triangle triangle(vertsNcolors, sizeof(vertsNcolors) / sizeof(float), false);

     // Main loop
    while (!window.shouldClose()) {
        window.ProcessInput();

         // Render commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // be sure to activate the shader before any calls to glUniform
        glUseProgram(shaderProgram);

        // update shader uniform
        // double  timeValue = glfwGetTime();
        // float greenValue = static_cast<float>(sin(timeValue) / 2.0 + 0.5);
        // int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        // glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        shader.setFloat("xOffset", offset);
        shader.use();
        triangle.draw();
        
        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}