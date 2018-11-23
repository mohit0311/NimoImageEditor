#pragma once
#include <glew.h>
#include <glfw3.h>
class MainWindow {
private:
	MainWindow();
public:

	static bool createWindow(char[], int, int);
	static bool windowShouldClose();
	static void swapBuffersAndPollEvents();
	
};