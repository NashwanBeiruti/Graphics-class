#include <gl/glut.h>


void DisplayIllusion(void) {
	int x = 800; 
	int y = 800;
	int start = 50; // Starting rectangle size
	float color = .1;
	float r;
	glClear(GL_COLOR_BUFFER_BIT);
	int i = 0;
    
	for( i = 0; i < 20; i++) {
		r = color; // Updates the shade of red that is used
		
		glColor3f(r, 0, 0); // Set the color value as r, which is represents red, blue and green are set to 0
		
		glBegin(GL_QUADS);
		glVertex2f(start, start);
		glVertex2f(x-start, start);
		glVertex2f(x-start, y-start);
		glVertex2f(start,y-start); 
		
		glEnd();
		start = start + 20; // Increases square size
		color = color + 0.03; // Update color value
	} // Creates 20 squares

  	glFlush();

}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Pyramid Illusion Project");
	glClearColor(0.0, 0.0, 0.0, 0.0); // Black Background
	gluOrtho2D(0.0, 800.0, 0.0, 800.0); // 800x800 Viewing Area
	glutDisplayFunc(DisplayIllusion);
	glutMainLoop();

    return 0;
}
