#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}
// Tinh tien va quay
int phi = 0;
void display(void){
	glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 1.0, 1.0);
    glLoadIdentity ();             /* clear the matrix */
    /* viewing transformation  */
    gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
																//    eyex-y-z -> dat camera trong khong gian (x, y, z);
																//    center -> diem camera nhin vao: (x, y, z);
																//    up -> huong dinh dau cua camera : [-1, 0, 1]
																/* eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz */
    // Translatef and Rotatef
    glTranslatef(2.0, 0.0, 0.0);
	glPushMatrix(); // luu ma tran hien tai vao ngan xep
	    glRotatef(phi, 1.0, 0, 0);
	    glutWireCube(1.0); /* draw wireSphere 1 */
    glPopMatrix(); // loai bo ma tran ra khoi ngan xep
   
    glTranslatef(-4.0, 0.0, 0.0);
    glutWireCube(1.0); /* draw wireSphere 2 */
	
	glutSwapBuffers();
	glFlush ();
}

void keyboard(unsigned char key, int x, int y){
	if(key == 'a'){
		phi = (phi + 2) % 360;
		glutPostRedisplay();
	}
	// khi chay bam A -> xoay vat the quanh truc
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
//    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0); // Perspective - Projection
	glOrtho(-4.0, 4.0, -4.0, 4.0, 1.5, 20.0);  // Orthographic - Projection 
    glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Cube in 3D view");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
