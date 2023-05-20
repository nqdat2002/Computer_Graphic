#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static float year = 0, day = 0;
static float angle1 = 0, angle2 = 0, angle3 = 0;
GLfloat light_ambient1[] = { 0.2, 0.2, 0.0, 1.0 };
GLfloat light_diffuse1[] = { 0.8, 0.8, 0.0, 1.0 };

GLfloat light_ambient2[] = { 0.2, 0.0, 0.2, 1.0 };
GLfloat light_diffuse2[] = { 0.8, 0.0, 0.8, 1.0 };

GLfloat light_ambient3[] = { 0.0, 0.2, 0.2, 1.0 };
GLfloat light_diffuse3[] = { 0.0, 0.4, 0.4, 1.0 };

void init(void) {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);
	
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glLoadIdentity();
	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
//	glPushMatrix();
//		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
//		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
//		glutSolidSphere(1.0, 20, 16);   /* draw sun */
//		glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
//		glTranslatef (2.0, 0.0, 0.0);
//		glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
//		glutSolidSphere(0.2, 10, 8);    /* draw smaller planet */
//	glPopMatrix();
//	glutSwapBuffers();
	
	glPushMatrix();
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
		glRotatef(angle1, 0, 1, 0);
		glutSolidSphere(0.8, 20, 16);   /* draw sun */
	glPopMatrix();
	
	glPushMatrix();
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
		glRotatef(angle2, 0, 1, 0);
		glTranslatef(2.5, 0, 0);
		glutSolidSphere(0.2, 20, 16);   /* draw earth */
		
		glPushMatrix();
		glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient3);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse3);
		glRotatef(angle3, 1, 0, 0);
		glTranslatef(0, 0.5, 0);
		glutSolidSphere(0.1, 20, 16);
		glPopMatrix();
		
	glPopMatrix();
	
	glutSwapBuffers();
	glFlush();
}

void reshape (int w, int h){
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

void spin(){
	angle1 = angle1 + 0.01;
	angle2 = angle2 + 0.001;
	angle3 = angle3 + 0.02;
	if (angle1 > 360) angle1 = angle1 - 360;
	if (angle2 > 360) angle2 = angle2 - 360;
	if (angle3 > 360) angle3 = angle3 - 360;
	glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
	    case 'd':
			day = (day + 10);
			if (day > 360) day = day - 360;
			glutPostRedisplay();
	        break;
	    case 'D':
			day = (day - 10);
			glutPostRedisplay();
			if (day > 360) day = day - 360;
			break;
		case 'y':
			year = (year + 2);
			if (year > 360) year = year - 360;
			glutPostRedisplay();
			break;
	    case 'Y':
	        year = (year - 2);
	        if (year > 360) year = year - 360;
	        glutPostRedisplay();
	        break;
	    
		case 'a':
	    	glutIdleFunc(spin);
	    	break;
	    default:
	        break;
   }
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (1080, 780); 
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
