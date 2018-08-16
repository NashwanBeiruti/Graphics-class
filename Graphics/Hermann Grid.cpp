#include<gl\glut.h>

void DrawSquares(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	
	glColor3f(0, 0, 0); // Black
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4); // Draws Black Squares
	glEnd();
}

void DrawLoop() {
	
	glClear(GL_COLOR_BUFFER_BIT); // Enables Window For Writing
	int x; // X-Axis Position
	int y; // Y-Axis Position
	glTranslatef(175,150,0); // Initiliazes Position For Starting Squares

	for (x = 0; x < 350; x = x + 70) {

		for (y = 0; y < 300; y = y + 60) {
			DrawSquares(x, y + 50, x + 50, y + 50, x + 50, y, x, y); // Creates Vertices for each square
		}

	} // Creates 5x5 Grid of Squares
	
	glFlush();
}

int main(int agrc, char ** argv) {
	
	glutInit(&agrc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600,600); // Window Size 600x600
	glutCreateWindow("Hermann Grid Illusion"); 
	glClearColor(1, 1, 1, 1); // White Background
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 720, 0, 720); // Creates 720x720 Viewing Area
	glutDisplayFunc(DrawLoop);
	glutMainLoop();

}
