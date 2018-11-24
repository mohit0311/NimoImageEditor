#include <iostream>
#include "src/MainWindow/main_window.h"
#include "src/cMacros/macros.h"
int main() {
	char windowName[] = wName;
	if (MainWindow::createWindow(windowName, 1000, 800)) {
		return -1;
	}
	else {
		std::cout << cStat << "\n";
	}
	while (!MainWindow::windowShouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT);

		MainWindow::swapBuffersAndPollEvents();
	}
	system("PAUSE");
	return 0;
}