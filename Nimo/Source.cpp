#include <iostream>
#include "src/MainWindow/main_window.h"
int main() {
	char windowName[] = "Hello World";
	std::cout << "HEllo all is working"<<"\n";
	
	if(MainWindow::createWindow(windowName, 1000, 800));
	while (!MainWindow::windowShouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT);

		MainWindow::swapBuffersAndPollEvents();
	}
	system("PAUSE");
	return 0;
}