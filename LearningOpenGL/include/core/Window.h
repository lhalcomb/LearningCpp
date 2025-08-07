// include/core/Window.h
#pragma once
#include <GLFW/glfw3.h>
#include <string>

class Window{
    public: 
        Window(int width, int height, const std::string& title);
        ~Window();

        void ProcessInput();

        void pollEvents() const;
        void swapBuffers() const;
        bool shouldClose() const;

        GLFWwindow* getGLFWwindow() const;
    private:
        GLFWwindow* window;

};