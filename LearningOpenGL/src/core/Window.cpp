#define GL_SILENCE_DEPRECATION
#include <glad/glad.h>             
#include <GLFW/glfw3.h>            
#include "core/Window.h"
#include <iostream>



Window::Window(int width, int height, const std::string& title){
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        std::exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    #endif

    const char* c_title = title.c_str(); // convert string to c read char string
    window = glfwCreateWindow(width, height, c_title, nullptr, nullptr); 
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        std::exit(EXIT_FAILURE);
    }

    int fbSizeX, fbSizeY; 
    glfwGetFramebufferSize(window, &fbSizeX, &fbSizeY);
     glViewport(0, 0, fbSizeX, fbSizeY);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow*, int w, int h) { // openGL frame buffer that setes the size of the window. The scary bit is an unnamed lambda function "[](GLFWwindow*, int w, int h) -> glViewport(0,0,w,h)"
        glViewport(0, 0, w, h);
    });
};

Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::pollEvents() const {
    glfwPollEvents();
}

void Window::swapBuffers() const {
    glfwSwapBuffers(window);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(window);
}

bool Window::isKeyPressed(int key)
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}
void Window::ProcessInput()
{
    if ((glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) || (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS))
        glfwSetWindowShouldClose(window, true);
}

GLFWwindow* Window::getGLFWwindow() const {
    return window;
}