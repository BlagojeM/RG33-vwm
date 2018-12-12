#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float lx=0.0f,lz=-1.0f;
float angle=0.0;
float xx=0.0f,zz=1.0f;


static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);


	glutKeyboardFunc(on_keyboard);
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);


	glClearColor(0.75, 0.75, 0.75, 0);
	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 0;
}

static void on_display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0, 0, 1);

    /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /*
     * Kreira se kocka i primenjuje se geometrijska transformacija na
     * istu.
     */
    glColor3f(0, 0, 1);
    glTranslatef(0, .5, 0);
    glScalef(1, 2, 1);
    glutWireCube(1);

	gluLookAt(xx, 0, zz,
			  xx + lx, 0,  zz + lz -1,
			  0.0f, 1.0f,  0.0f);


	glBegin(GL_LINES);
		glVertex3f(-1, 0, 0);
		glVertex3f(1, 0, 0);
		
		glVertex3f(0, -1, 0);
		glVertex3f(0, 1, 0);

		glVertex3f(0, 0, -1);
		glVertex3f(0, 0, 1);

	glEnd();
	glutSwapBuffers();
}

static void on_reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0f, (float) width/height,0.01, 1000);
}

static void on_keyboard(unsigned char key, int x, int y)
{
	float fraction = 0.1f;
    switch (key) {
		case 27:
			/* Zavrsava se program. */
			exit(0);
			break;
		case 'a':
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'd':
			angle += 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'w':
			xx += lx * fraction;
			zz += lz * fraction;
			break;
		case 's':
			xx -= lx * fraction;
			zz -= lz * fraction;
			break;
	}

	printf("x %f || z %f\nlx %f || lz %f\nangle %f\nfraction %f\n",xx , zz, lx, lz, angle, fraction);

	glutPostRedisplay();
}
