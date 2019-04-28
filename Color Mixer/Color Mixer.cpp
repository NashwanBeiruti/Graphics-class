#include <gl\glut.h>

bool left_button_down_Red = false; 
bool left_button_down_Green = false;
bool left_button_down_Blue = false;

bool l_is_pressed = false;
bool r_is_pressed = false;

int width = 800;
int height = 600;

int cyred = 277; // Starting Redslider y position
int cxred = 100; // starting Redslider x position

int cygreen = 277; // Starting Greenslider y position
int cxgreen = 200; // Starting Greenslider x position

int cyblue = 277; // Starting Blueslider y position
int cxblue = 300; // Starting Blueslider x position

int r = 0; // counter for red color
int g = 0; // counter for green color
int b = 0; // counter for blue color


void DrawSquare(int red, int green, int blue) {
	
	glColor3ub(red, green, blue); // Color
	glBegin(GL_QUADS);
	glVertex2f(700,550);
	glVertex2f(700,350);
	glVertex2f(500,350);
	glVertex2f(500,550); // Draws Square
	
	glEnd();
}

void DrawRectangle(int red, int green, int blue) {
	
	glBegin(GL_QUADS);
	
	glColor3f(1, 1, 1); // white
	glVertex2f(465,225);
	glVertex2f(465,275);
	glVertex2f(735,275);
	glVertex2f(735,225);
	
	if (l_is_pressed) {
		glColor3ub(red,green,blue);
		glVertex2f(600,225);
		glColor3ub(red-191.25,green-191.25,blue-191.25);
		glVertex2f(600,275);
		glColor3ub(red-127.5,green-127.5,blue-127.5);
		glVertex2f(465,275);
		glColor3ub(red-63.75,green-63.75,blue-63.75);
		glVertex2f(465,225);
	}

	if (r_is_pressed) {
		glColor3ub(red-191.25,green-191.25,blue-191.25);
		glVertex2f(600,225);
		glColor3ub(red-127.5,green-127.5,blue-127.5);
		glVertex2f(600,275);
		glColor3ub(red-63.75,green-63.75,blue-63.75);
		glVertex2f(735,275);
		glColor3ub(red,green,blue);
		glVertex2f(735,225);
	}
	
	
	glEnd();
}

void DrawRedLines() {
	glLineWidth(3);
	glBegin(GL_LINES);
	
	glColor3f(.9,0,0);
	glVertex2f(100, 150);
	glVertex2f(100,405);
	
	glEnd();
	
}

void DrawRedSlider(int x, int y) {
	
	glColor3f(1,1,1);

	glBegin(GL_QUADS);
	
	glVertex2f(100 + 15, y);
	glVertex2f(100 + 15, y+7);
	glVertex2f(100 - 15, y+7);
	glVertex2f(100 - 15, y);
	
	if (left_button_down_Red) {
		glColor3f(1,0,0);
		glVertex2f(100 + 15, y);
		glVertex2f(100 + 15, y+7);
		glVertex2f(100 - 15, y+7);
		glVertex2f(100 - 15, y);
		r = y - 150;
	}
	
	glEnd();
	
}

void DrawGreenLines() {
	glLineWidth(3);
	glBegin(GL_LINES);
	
	glColor3f(0,.9,0);
	glVertex2f(200,150);
	glVertex2f(200,405);
	
	glEnd();
	
}

void DrawGreenSlider(int x, int y) {
	
	glColor3f(1,1,1);

	glBegin(GL_QUADS);
	
	glVertex2f(200 + 15, y);
	glVertex2f(200 + 15, y+7);
	glVertex2f(200 - 15, y+7);
	glVertex2f(200 - 15, y);
	
	
	if (left_button_down_Green) {
		glColor3f(0,1,0);
		glVertex2f(200 + 15, y);
		glVertex2f(200 + 15, y+7);
		glVertex2f(200 - 15, y+7);
		glVertex2f(200 - 15, y);
		g = y - 150;
	}
	
	glEnd();
	
}

void DrawBlueLines() {
	glLineWidth(3);
	glBegin(GL_LINES);
	
	glColor3f(0,0,.9);
	glVertex2f(300,150);
	glVertex2f(300,405);
	
	glEnd();
	
}

void DrawBlueSlider(int x, int y) {
	
	glColor3f(1,1,1);

	glBegin(GL_QUADS);
	
	glVertex2f(300 + 15, y);
	glVertex2f(300 + 15, y+7);
	glVertex2f(300 - 15, y+7);
	glVertex2f(300 - 15, y);
	
	if (left_button_down_Blue) {
		glColor3f(0,0,1);
		glVertex2f(300 + 15, y);
		glVertex2f(300 + 15, y+7);
		glVertex2f(300 - 15, y+7);
		glVertex2f(300 - 15, y);	
		b = y - 150;
	}
	
	glEnd();
	
}

void SliderValue (int x, int y, int space, int score){
	int i;
	int j;
	int k;
	glColor3f(0,0,0); // Black Letters
	
	j = score;
	i = 0;
	k = 0;
	
	while (j > 9) {
		k = j % 10;
		glRasterPos2f(x-(i*space),y);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+k);
		i++;
		j /= 10;
	}
	
	glRasterPos2f(x-(i*space),y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,48+j);
	
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT); // Enables Window For Writing
	
	DrawRedLines(); // Draws Red Line
	DrawRedSlider(cxred,cyred); // Draws Red Slider
	
	DrawGreenLines(); // Draws Green Line
	DrawGreenSlider(cxgreen,cygreen); // Draws Green Slider
	
	DrawBlueLines(); // Draws Blue Lines
	DrawBlueSlider(cxblue,cyblue); // Draws Blue Slider
	
	DrawSquare(r,g,b); // Draws and updates color of Square
	DrawRectangle(r,g,b);
	
	SliderValue(100,418,12,cyred - 150); // Counter for red slider
	SliderValue(200,418,12,cygreen - 150); // Counter for green slider
	SliderValue(300,418,12,cyblue - 150); // counter for blue slider

	glFlush();
	glEnd();
}

void mouse(int button, int state, int x, int y) {
	switch(button) {
		case GLUT_LEFT_BUTTON:
		
		if (state == GLUT_DOWN && (height - y >= 150) && (height - y <= 404) && (x >= 75) && (x <= 125)) {
				cxred = x;
				cyred = height - y;
				left_button_down_Red = true;
		}

		else {
			left_button_down_Red = false;
		}
		
		if (state == GLUT_DOWN && (height - y >= 150) && (height - y <= 405) && (x >= 175) && (x <= 225)) {
			cxgreen = x;
			cygreen = height - y;
			left_button_down_Green = true;
		}
		
		else {
			left_button_down_Green = false;
		}

		if (state == GLUT_DOWN && (height - y >= 150) && (height - y <= 405) && (x >= 275) && (x <= 325)) {
			cxblue = x;
			cyblue = height - y;
			left_button_down_Blue = true;
		}
		
		else {
			left_button_down_Blue = false;
		}
	}
	
	glutPostRedisplay();
}

void motion(int x, int y) {
	
	if ((height - y >= 150) && (height - y <= 405) && (x >= 75) && (x <= 125)) {
		cxred = x;
		cyred = height - y;
		left_button_down_Red = true;
	}
	else {
		left_button_down_Red = false;
	}
	
	if ((height - y >= 150) && (height - y <= 405) && (x >= 175) && (x <= 225)) {
		cxgreen = x;
		cygreen = height - y;
		left_button_down_Green = true;
	}
		
	else {
		left_button_down_Green = false;
	}
	
	if ((height - 1 - y >= 150) && (height - 1 - y <= 405) && (x >= 275) && (x <= 325)) {
			cxblue = x;
			cyblue = height - 1 - y;
			left_button_down_Blue = true;
		}
		
		else {
			left_button_down_Blue = false;
		}
	
	glutPostRedisplay();
	
}

void key(unsigned char key, int x, int y) {
	if (key == 'l') {
		l_is_pressed = true;
	}
	
	else {
		r_is_pressed = false;
	}
	if (key == 'r') {
		r_is_pressed = true;
	}
	else {
		r_is_pressed = false;
	}
	
	glutPostRedisplay();
}


int main(int agrc, char ** argv) {
	
	glutInit(&agrc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width,height); // Window Size 600x600
	glutCreateWindow("Color Mixer"); 
	glClearColor(.3, .3, .3, 1); // Background
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, width, 0, height); //800x600 graph
	glutDisplayFunc(Display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(key);
	glutMainLoop();

}
