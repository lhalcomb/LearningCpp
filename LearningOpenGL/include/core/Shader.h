// include/core/Shader.h
#pragma once
#include <string>
#include <glad/glad.h>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use() const;
    GLuint getID() const;

private:
    GLuint ID;
    std::string loadShaderSource(const std::string& path);
    void compileShader(GLuint shader, const std::string& source);
};
