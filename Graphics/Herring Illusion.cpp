#include <gl/glut.h>

void DrawParallel() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0,0,0); // Black
	glBegin(GL_LINES);
	
	
	glVertex2f(-20.0,3.0);
	glVertex2f(20.0,3.0); // Line Above Origin
	
	glVertex2f(-20.0,-3.0);
	glVertex2f(20.0,-3.0); // Line Below Origin
}

void DrawLines() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1.0,1.0,0); // Yellow
	glBegin(GL_LINES);
	int x = 0;
	int y = 0;
	int z = 24;
	
	while (x > -24) {

		glVertex2f(0.0,0.0);
		glVertex2f(x,24.0);
		glVertex2f(0.0,0.0);
		glVertex2f(x,-24.0); 

		x = x - 6;
	} // Lines for Quadrants 2 and 3

	while (y < 24) {
		glVertex2f(0.0,0.0);
		glVertex2f(y,24.0);
		glVertex2f(0.0,0.0);
		glVertex2f(y,-24.0); 
		y = y + 6;
	} // Lines for Quadrants 1 and 4
	
	
	while (z > 0) {
		glVertex2f(0.0,0.0);
		glVertex2f(-24.0,z); // Quadrant 2
		
		glVertex2f(0.0,0.0);
		glVertex2f(-24.0,-z); // Quadrant 3
		
		glVertex2f(0.0,0.0);
		glVertex2f(24.0,z); // Quadrant 1
		
		glVertex2f(0.0,0.0);
		glVertex2f(24.0,-z); // Quadrant 4
		
		z = z - 6;
	} // Lines for Quadrants 1,2,3,4 going downwards
	
	DrawParallel();
	glEnd();
	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Hering Illusion");

	glClearColor(0.22, 0.69, 0.87, 1.0); // Light Blue
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-24.0, 24.0, -24.0, 24.0, -24.0, 24.0); // 24x24 graph

	glutDisplayFunc(DrawLines);

	glutMainLoop();

}
