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

@author Dipesh Chouhan\
@see shaders.cpp
*/

#pragma once
#include <string>
#include <iostream>
#include <vector>


class Shaders {
private:
	Shaders() {};
	~Shaders() {};
	static std::string getShaderSource(const char* shaderFilePath);
	static std::vector<char> compileShader(unsigned int shaderType, const char* shaderFilePath, int* result,
		int* infoLogLength);
	static std::vector<char> linkProgram_deleteShaders(unsigned int* programShader, int* result, int* infoLogLength);

public:
	static unsigned int loadShaders(const char* vertexShaderFilePath, const char* fragmentShaderFiledPath);


};
