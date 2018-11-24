#include "src/MainWindow/main_window.h"
#include "src/cMacros/macros.h"
#include "src/shaders/shaders.h"
int main() {
	char windowName[] = wName;
	if (MainWindow::createWindow(windowName, 1000, 800)) {
		return -1;
	}
	else {
		std::cout << cStat << "\n";
	}

	unsigned int vertexArray;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);
	GLfloat vertexArrayData[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	unsigned int vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArrayData), vertexArrayData, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	unsigned int program = Shaders::loadShaders(vertexShaderPath, fragmentShaderPath);
	while (!MainWindow::windowShouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		MainWindow::swapBuffersAndPollEvents();
	}
	system("PAUSE");
	return 0;
}