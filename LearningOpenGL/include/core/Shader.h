// include/core/Shader.h
#pragma once
#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();

    void use() const;
    GLuint getID() const;

    // utility uniform functions
    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;

private:
    GLuint ID;
    std::string loadShaderSource(const std::string& path);
    GLuint compileShader(GLuint shader, const std::string& source);
};

#endif