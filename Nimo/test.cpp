#include <glew.h>
#include <glfw3.h>
#include <iostream>
int main() {

	if (!glfwInit()) {
		std::cout << "error in initializing the library" << "\n";
		return -1;
	}
	system("PAUSE");
	return 0;

}