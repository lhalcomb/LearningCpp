#pragma once
#include <glad/glad.h>
#include <cstddef> // for size_t

class Rectangle {
public:
    Rectangle(const float vertices[], size_t vertexCount,
              const unsigned int indices[], size_t indexCount, bool wireframe);
    ~Rectangle();

    // No copy
    Rectangle(const Rectangle&) = delete;
    Rectangle& operator=(const Rectangle&) = delete;

    // Move semantics
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;

    void draw() const;

private:
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLuint EBO = 0;
    size_t numIndices = 0;
};
