#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>     
#include "core/Window.h"

//window parameters
const unsigned int SCR_WIDTH = 800; 
const unsigned int SCR_HEIGHT = 600; 


int main(){

    Window window(SCR_WIDTH, SCR_HEIGHT, "Hello Window!"); 


     // Main loop
    while (!window.shouldClose()) {
        window.ProcessInput();

         // Render commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}