
#include <iostream>
#include <windows.h>
#include <GL\glut.h>

using namespace std;

float pos[] = {-1,4,5,1};
float amb[] = {1,1,1,0.0};
float spe[] = {0.25,0.25,0.25,0.0};
float theta = 50, dt = 0.5, axes[3][3] = {{1,0,0} , {0,1,0} , {0,0,1}};
int axis = 0;

int spin = -1; // Rotation of Wind Mill direction
int time = 0; // Stores Time value
int StarRedValue = 1; // Updates Red Color of stars
int StarYellowValue = 1; // Updates Yellow Color of stars
int StarBlueValue = 0; // Updates Blue Color of stars
float bladeSize = .7; // Wind Mill Blade Size

static void Timer(int value) {
	
	time = time + 1;
	
	if (time >= 10) {
		time = 0;
		glutPostRedisplay();	
	}
	
	glutTimerFunc(100,Timer,0);
} // Time Function

void CreateStars() {
	
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	
	glPointSize(3.0);
	
	glColor3f(StarRedValue,StarYellowValue,StarBlueValue); // Color of Stars
	
	glBegin(GL_POINTS);
	
	if (time > 5) {
		glVertex3f(.5,.4,.2);
		glVertex3f(.6,.3,.2);
		glVertex3f(-.3,.2,.2);
		glVertex3f(-.6,.2,.2);
		glVertex3f(.2,.8,.2);
		glVertex3f(.8,.7,.2);
		glVertex3f(-.6,.8,.2);
		glVertex3f(-.7,.5,.2);
	} // Show Stars every 5 miliseconds
	
	glVertex3f(.2,.2,.2);
	glVertex3f(-.3,.4,.2);
	glVertex3f(-.4,-.1,.2);
	glVertex3f(.45,-.15,.2);
	glVertex3f(-.7,-.2,.2); 
	
	glEnd(); // Creates star points
}


void display() {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Enables Window For Writing
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);	
	
	
	glPushMatrix();
	
	glColor3f(.3,.3,.3);
	glRotated(theta,0,0,1);
	glutSolidSphere(0.04,20,10);
	
	glPopMatrix(); // Creates outter Gear of Wind Turbine
	
	
	glPushMatrix(); 
	
	CreateStars(); // Creates Background Stars
	
	glBegin(GL_QUADS);
	
	glColor3f(0,0,.5);
	glVertex3f(2.0,-0.4,.4);
	glVertex3f(-2.0,-0.4,.4);
	glVertex3f(-2.0,-2.0,.4);
	glVertex3f(2.0,-2.0,.4);
	
	glEnd();
	
	glColor3f(.3,.3,.3);
	glRotated(70,1,0,0);
	glTranslated(0,.2,0);
	GLUquadricObj *quadObj;
	quadObj = gluNewQuadric();
	gluQuadricDrawStyle(quadObj, GLU_FILL);
	gluCylinder(quadObj,.055,0,1,50,50); // Wind Turbine Base
	
	glPopMatrix();

	
	glPushMatrix();
	
	glColor3f(.3,.3,.3);
	glRotated(theta,0,0,1);
	glutSolidSphere(0.02,20,10); 
	
	glColor3f(1,0,1);
	glRotated(theta,0,0,1);
	glutSolidCone(.04,.05,20,20); 
	
	glPopMatrix(); // Creates  Gear of Wind Turbine
	
	
	glPushMatrix();
	
	glColor3f(0.3,0.3,0.3);
	glRotated(10,0,0,0);
	glTranslated(-.8,.7,.5);
	glutSolidSphere(.1,30,30);
	
	glPopMatrix(); // Creates the Background Moon
	
	
	glPushMatrix();
	
	glRotated(theta,0,0,spin);
	
	glColor3f(1,0,0);
	
	glBegin(GL_TRIANGLES);
	
	glVertex3f(0,0.0,.1);
	glVertex3f(.1,-bladeSize,.1);
	glVertex3f(-.1,-bladeSize,.1);
	
	glVertex3f(0,0.0,.1);
	glVertex3f(.1,bladeSize,.1);
	glVertex3f(-.1,bladeSize,.1);
	
	glVertex3f(0,0.0,.1);
	glVertex3f(-bladeSize,.1,.1);
	glVertex3f(-bladeSize,-.1,.1);
	
	glVertex3f(0,0.0,.1);
	glVertex3f(bladeSize,.1,.1);
	glVertex3f(bladeSize,-.1,.1);
	
	glEnd();
	
	glPopMatrix(); // Creates the Rotating Blades for the Wind Turbine
	
	
	glutSwapBuffers();

}

void rotation(void) {
	if (theta >= 360) axis = (axis + 5) % 20;
	theta = (theta < 360) ? theta + dt : dt;
	glutPostRedisplay();
} 

void key(unsigned char key, int x, int y) {
	
	if (key == 'd' || key == 'D') {
		spin = 1;
	} // Counter Clockwise Blade Rotation
	
	if (key == 'f' || key == 'F') {
		spin = -1;
	} // Clockwise Blade Rotation
	
	if (key == 'w' || key == 'W') {
		StarRedValue = 1.0;
		StarYellowValue = 1.0;
		StarBlueValue = 1.0;
	} // Make Background Stars white
	
	if (key == 'y' || key == 'Y') {
		StarRedValue = 1.0;
		StarYellowValue = 1.0;
		StarBlueValue = 0.0;
	} // Make Background Stars yellow
	
	if (key == 's' || key == 'S') {
		bladeSize = .3;
	} // Make Turbine Blades smaller
	
	if (key == 'l' || key == 'L') {
		bladeSize = 1;
	} // Make Turbine Blades larger
	
	if (key == 'm' || key == 'M') {
		bladeSize = .7;
	} // Make Turbine Blades original size
	
	glutPostRedisplay();
}

int main(int agrc, char ** argv) {
	
	glutInit(&agrc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Wind Turbine and Blinking Stars");
	glClearColor(0.184314,0.184314,0.309804,0.0); // Background Color, Midnight Blue
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,spe);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,50);

	glLightfv(GL_LIGHT0,GL_AMBIENT,amb);

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);
	
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();

	glLightfv(GL_LIGHT0,GL_POSITION,pos); // Lighting for Wind Turbine
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL); // Enables Color changing without Materialfv
	
	glutTimerFunc(1.0,Timer,0);
	glutDisplayFunc(display);
	glutIdleFunc(rotation);
	glutKeyboardFunc(key);
	
	
	cout << "To make the wind turbine blades rotate counter clockwise press D or d " << endl;
	cout << "To make the wind turbine blades rotate clockwise press F or f " << endl;
	cout << endl;
	cout << "To make the blades smaller press S or s " << endl;
	cout << "To make the blades Larger press L or l " << endl;
	cout << "To make the blades there original size press M or m " << endl;
	cout << endl;
	cout << "To change the Blinking Stars to white press W or w " << endl;;
	cout << "To change the Blinking Stars back to the original color of yellow press Y or y " << endl;
	
	glutMainLoop();
}



