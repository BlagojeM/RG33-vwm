#include <iostream>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <math.h>

float lx=0.0f,lz=-1.0f;
float angle=0.0;
float xx=0.0f,zz=0.0f;


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
		  xx + lx, 0,  zz + lz,
		  0.0f, 1.0f,  0.0f);


	glBegin(GL_LINES);
		glVertex3f(-1, 0, 0);
		glVertex3f(1, 0, 0);
		
		glVertex3f(0, -1, 0);
		glVertex3f(0, 1, 0);

		glVertex3f(0, 0, -1);
		glVertex3f(0, 0, 1);	
	glEnd();

	glBegin(GL_QUADS);
		//top

		glColor3f(1.0f, 0.0f, 0.0f);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);

		//left

		glColor3f(0.8f, 0.8f, 0.8f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		//right

		glColor3f(0.8f, 0.8f, 0.8f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f,- 1.0f, -1.0f);


		//bottom

		glColor3f(0.2f, 0.2f, 0.2f);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-10.0f, -1.0f, 10.0f);
		glVertex3f(10.0f, -1.0f, 10.0f);
		glVertex3f(10.0f, -1.0f, -10.0f);
		glVertex3f(-10.0f, -1.0f, -10.0f);

		//front-left

		glColor3f(0.5f, 0.5f, 0.5f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-10.0f, 2.0f, 1.0f);
		glVertex3f(-10.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, 2.0f, 1.0f);

		//front-right

		glColor3f(0.5f, 0.5f, 0.5f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(10.0f, 2.0f, 1.0f);
		glVertex3f(10.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, 2.0f, 1.0f);

		//front-top

		glColor3f(0.5f, 0.5f, 0.5f);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 2.0f, 1.0f);
		glVertex3f(1.0f, 2.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
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

	glm::mat4 trans;
	trans = glm::rotate(trans, (float)0.0174532925, glm::vec3(0.0f, 1.0f, 0.0f));

	float fraction = 0.1f;
	switch (key) {
		case 27:
			/* Zavrsava se program. */
			exit(0);
			break;
		case 'a':
			angle -= 0.02f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'd':
			angle += 0.02f;
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

	std::cout << "x " << xx << " || z " << zz << std::endl;
	std::cout << "lx " << lx << " || lz " << lz << std::endl;
	std::cout << "angle " << angle << std::endl;
	std::cout << "fraction " << fraction << std::endl;
	//printf("x %f || z %f\nlx %f || lz %f\nangle %f\nfraction %f\n",xx , zz, lx, lz, angle, fraction);

	glutPostRedisplay();
}
