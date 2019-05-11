#include <gl/glut.h>
// Made by :Nash

void DrawWhite() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3d(1,1,1); // White
	glBegin(GL_QUADS);
	float x = 20.0; // Starting X-axis Position
	float y = 20.0; // Starting Y-axis position
	float y2 = 17.95;
	float y3 = 15.90;
	float y4 = 13.85;
	float y5 = 11.75;
	float y6 = 9.65;
	float y7 = 7.55;
	float y8 = 5.45;
	float y9 = 3.35;
	float y10 = 1.30;
	
	while ( x > 0 ) {
		
		glVertex2f(-x,y);
		glVertex2f(-x+2,y);
		glVertex2f(-x+2,y-2);
		glVertex2f(-x,y-2);
		
		glVertex2f(-x+1,y2);
		glVertex2f(-x+3,y2);
		glVertex2f(-x+3,y2-2);
		glVertex2f(-x+1,y2-2);
		
		glVertex2f(-x,y3);
		glVertex2f(-x+2,y3);
		glVertex2f(-x+2,y3-2);
		glVertex2f(-x,y3-2);
		
		glVertex2f(-x+1,y4);
		glVertex2f(-x+3,y4);
		glVertex2f(-x+3,y4-2);
		glVertex2f(-x+1,y4-2);
		
		glVertex2f(-x,y5);
		glVertex2f(-x+2,y5);
		glVertex2f(-x+2,y5-2);
		glVertex2f(-x,y5-2);
		
		glVertex2f(-x+1,y6);
		glVertex2f(-x+3,y6);
		glVertex2f(-x+3,y6-2);
		glVertex2f(-x+1,y6-2);
		
		glVertex2f(-x,y7);
		glVertex2f(-x+2,y7);
		glVertex2f(-x+2,y7-2);
		glVertex2f(-x,y7-2);
		
		glVertex2f(-x+1,y8);
		glVertex2f(-x+3,y8);
		glVertex2f(-x+3,y8-2);
		glVertex2f(-x+1,y8-2);
		
		glVertex2f(-x,y9);
		glVertex2f(-x+2,y9);
		glVertex2f(-x+2,y9-2);
		glVertex2f(-x,y9-2);
		
		glVertex2f(-x+1,y10);
		glVertex2f(-x+3,y10);
		glVertex2f(-x+3,y10-2);
		glVertex2f(-x+1,y10-2);
		
		
		x = x - 4;
	} // Creates White Squares
	
	
}
	
void DrawBlack() {
	glColor3d(0,0,0); // Black
	float y = 20.0; // Starting Y-axis position
	float y2 = 17.95;
	float y3 = 15.90;
	float y4 = 13.85;
	float y5 = 11.75;
	float y6 = 9.65;
	float y7 = 7.55;
	float y8 = 5.45;
	float y9 = 3.35;
	float y10 = 1.30;
	float z = 18.0; // Starting X-axis Position
	glBegin(GL_QUADS);
	
	while (z > 4) {
		
		glVertex2f(-z,y);
		glVertex2f(-z+2,y);
		glVertex2f(-z+2,y-2);
		glVertex2f(-z,y-2);
		
		glVertex2f(-z+1,y2);
		glVertex2f(-z+3,y2);
		glVertex2f(-z+3,y2-2);
		glVertex2f(-z+1,y2-2);
		
		glVertex2f(-z,y3);
		glVertex2f(-z+2,y3);
		glVertex2f(-z+2,y3-2);
		glVertex2f(-z,y3-2);
		
		glVertex2f(-z+1,y4);
		glVertex2f(-z+3,y4);
		glVertex2f(-z+3,y4-2);
		glVertex2f(-z+1,y4-2);
		
		glVertex2f(-z,y5);
		glVertex2f(-z+2,y5);
		glVertex2f(-z+2,y5-2);
		glVertex2f(-z,y5-2);
		
		glVertex2f(-z+1,y6);
		glVertex2f(-z+3,y6);
		glVertex2f(-z+3,y6-2);
		glVertex2f(-z+1,y6-2);
		
		glVertex2f(-z,y7);
		glVertex2f(-z+2,y7);
		glVertex2f(-z+2,y7-2);
		glVertex2f(-z,y7-2);
		
		glVertex2f(-z+1,y8);
		glVertex2f(-z+3,y8);
		glVertex2f(-z+3,y8-2);
		glVertex2f(-z+1,y8-2);
		
		glVertex2f(-z,y9);
		glVertex2f(-z+2,y9);
		glVertex2f(-z+2,y9-2);
		glVertex2f(-z,y9-2);
		
		glVertex2f(-z+1,y10);
		glVertex2f(-z+3,y10);
		glVertex2f(-z+3,y10-2);
		glVertex2f(-z+1,y10-2);
			
		
		z = z - 4;
	} // Creates Black Squares
	
}
	
	


void CreateIllusion() {
	glClear(GL_COLOR_BUFFER_BIT);
	DrawBlack();
	DrawWhite();
	glEnd();
	glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1500, 1500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Cafe Wall Illusion");

	glClearColor(0.184314,0.309804,0.309804,1.0); // Grey
	glOrtho(-24.0, 24.0, -24.0, 24.0, -24.0, 24.0); // 24x24 graph

	glutDisplayFunc(CreateIllusion);

	glutMainLoop();

}
