/**MIT License

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
@see main_window.h
*/
#include "main_window.h"
GLFWwindow* window;
bool MainWindow::createWindow(char name[], int width, int height) {
	// initialize GLFW
	if (!glfwInit()) {
		return false;
	}
	window = glfwCreateWindow(width, height, name, NULL, NULL);
	if (window==NULL) {
		glfwTerminate();
		return false;
	}
	// making window context
	glfwMakeContextCurrent(window);
	// initializing GLEW
	if (!(glewInit() == GLEW_OK)) {
		return false;
	}
}
bool MainWindow::windowShouldClose() {
	if (!glfwWindowShouldClose(window)) {
		return false;
	}
	return true;
}
void MainWindow::swapBuffersAndPollEvents() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}