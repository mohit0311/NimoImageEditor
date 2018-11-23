/**
@author Dipesh Chouhan
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