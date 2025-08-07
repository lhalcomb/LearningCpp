// src/core/Shader.cpp
#include "core/Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {
    // Load, compile, and link shader logic here
}

void Shader::use() const {
    glUseProgram(ID);
}
