/**
MIT License

Copyright (c) 2018 Nimo Image Editor

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

@author Dipesh Chouhan
@see shaders.h
*/

#include "shaders.h"
#include <fstream>
#include <sstream>
#include "glew.h"
#include "glfw3.h"
// "getShadersSource()" method need for reading the shader txt filed and returns the data as string.
std::string Shaders::getShaderSource(const char* shaderFilePath) {
	std::string shaderSource;
	std::ifstream shaderSourceFile;
	shaderSourceFile.open(shaderFilePath);
	if (shaderSourceFile.is_open()) {
		std::stringstream s_stream;
		std::string line;
		while (std::getline(shaderSourceFile, line)) {
			s_stream << line << "\n";
		}
		shaderSource = s_stream.str();
	}
	return shaderSource;
}

unsigned int Shaders::loadShaders(const char* vertexShaderFilePath, const char* fragmentShaderFilePath) {
	int* result = GL_FALSE;
	int* infoLogLength;
	// creating shaders
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// compiling shaders
	printf("%s\n", compileShader(vertexShader, vertexShaderFilePath, result, infoLogLength)[0]);
	printf("%s\n", compileShader(fragmentShader, fragmentShaderFilePath, result, infoLogLength)[0]);

	// linking program
	printf("%s\n", "linking program.....");
	unsigned int program = glCreateProgram();
	unsigned int psContainer[] = { program, vertexShader, fragmentShader };
	printf("%s\n", linkProgram_deleteShaders(psContainer, result, infoLogLength)[0]);
	return program;
}
	

std::vector<char> Shaders::compileShader(unsigned int shaderType, const char* shaderFilePath, int* result, int* infoLogLength) {
	
		printf("%s %d.....\n", "compiling shader ", shaderFilePath);
		char const* shaderPointer = getShaderSource(shaderFilePath).c_str();
		glShaderSource(shaderType, 1, &shaderPointer, NULL);
		glCompileShader(shaderType);

		//check for shader
		glGetShaderiv(shaderType, GL_COMPILE_STATUS, result);
		glGetShaderiv(shaderType, GL_INFO_LOG_LENGTH, infoLogLength);
		std::vector<char> shaderErrorMessage(*infoLogLength+1);
		if (*infoLogLength > 0) {
			glGetShaderInfoLog(shaderType, *infoLogLength, infoLogLength, &shaderErrorMessage[0]);
		}
		return shaderErrorMessage;

}

std::vector<char> Shaders::linkProgram_deleteShaders(unsigned int* programShader, int* result, int* infoLogLength) {
	glGetProgramiv(*programShader, GL_LINK_STATUS, result);
	glGetProgramiv(*programShader, GL_INFO_LOG_LENGTH, infoLogLength);
	std::vector<char> programShaderErrorMessage(*infoLogLength + 1);
	if (*infoLogLength > 0) {
		glGetProgramInfoLog(*programShader, *infoLogLength, infoLogLength, &programShaderErrorMessage[0]);
	}
	glDetachShader(*programShader, *(programShader + 1)); // detaching vertex shader
	glDetachShader(*programShader, *(programShader + 2)); // detaching fragment shader

	glDeleteShader(*(programShader + 1)); // deleting vertex shader
	glDeleteShader(*(programShader + 2)); // deleting fragment shader
	return programShaderErrorMessage;
}

