#pragma once 
#include <glad/glad.h>
#include <cstddef>


class Triangle{
    public:
        Triangle(const float vertices[], size_t vertexCount, bool wireframe = false);
        Triangle(const float vertices[], size_t vertexCount, const unsigned int indices[], size_t indexCount, bool wireframe);
        ~Triangle();

        //Prevents copying the openGL Object IDs
        Triangle(const Triangle&) = delete;
        Triangle& operator=(const Triangle&) = delete;

        // Allow move semantics, to transfer one object Id to another when change of variables
        Triangle(Triangle&& other) noexcept;
        Triangle& operator=(Triangle&& other) noexcept;

        void draw() const; //render the triangle accordingly

    private:
        GLuint VBO, VAO, EBO;
        size_t vertexCount;
        size_t indexCount = 0;
        bool hasIndices = false;
};