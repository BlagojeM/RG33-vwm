// g++ -o program main.cpp Room.cpp Wall.cpp -lglut -lGL -lGLU -lm
//	./program

#include <iostream>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <math.h>
//#include "LevelOne.h"
#include "Room.hpp"
#include "Wall.hpp"
#include "Person.hpp"

#define TIMER_INTERVAL1 10
#define TIMER_INTERVAL2 10
#define TIMER_ID1 0
#define TIMER_ID2 0


float lx=0.0f,lz=-1.0f;
float angle=0.0f;
float angle1=0.0f;
float xx=0.0f,zz=0.0f;
float yy = 0.0f, yy_par = 0.0f;

float mouse_x = 0.0f;
float mouse_y = 0.0f;
int width_a = 0;
int height_a = 0;

float person_x = 0.0f;
float person_y = 0.0f;

float jump_ongoing = 1.0f;


static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);
static void on_mouse(int x, int y);
static void on_timer1(int);
static void on_timer2(int);


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(300, 150);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	glutFullScreen();


	glutKeyboardFunc(on_keyboard);
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	//glutMotionFunc(on_mouse);
	glutPassiveMotionFunc(on_mouse);
	glutTimerFunc(TIMER_INTERVAL1, on_timer1, TIMER_ID1);

	glClearColor(0.75, 0.75, 0.75, 0);
	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
	return 0;
}

static void on_timer1(int){
	
	glutWarpPointer(width_a/2, height_a/2);

	glutTimerFunc(TIMER_INTERVAL1, on_timer1, TIMER_ID1);
	glutPostRedisplay();
}
static void on_timer2(int){
	if(jump_ongoing > 0){
		jump_ongoing -= 0.07;
		glutTimerFunc(TIMER_INTERVAL2, on_timer2, TIMER_ID2);
	}
	else
		jump_ongoing = 0;
	glutPostRedisplay();
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
    //glColor3f(0, 0, 1);
    //glTranslatef(0, .5, 0);
    //glScalef(1, 2, 1);
    glutWireCube(1);

	gluLookAt(xx, 0.5f + yy +jump_ongoing, zz,
		  xx + lx, 0.5f + yy + yy_par + jump_ongoing,  zz + lz,
		  0.0f, 1.0f,  0.0f);


	//LevelOne x;
	glm::vec3 a = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 b = glm::vec3(5.0f, 0.0f, 0.0f);
	glm::vec3 c = glm::vec3(5.0f, 0.0f, 5.0f);
	glm::vec3 d = glm::vec3(10.0f, 0.0f, 2.5f);
	glm::vec3 e = glm::vec3(15.0f, 0.0f, 5.0f);
	glm::vec3 f = glm::vec3(15.0f, 0.0f, 0.0f);
	glm::vec3 g = glm::vec3(20.0f, 0.0f, 0.0f);
	glm::vec3 h = glm::vec3(15.0f, 0.0f, 15.0f);
	glm::vec3 i = glm::vec3(10.0f, 0.0f, 10.0f);
	glm::vec3 j = glm::vec3(5.0f, 0.0f, 15.0f);


	std::vector<glm::vec3> zidovi, kaoCovek;
	
	zidovi.push_back(a);
	zidovi.push_back(b);
	zidovi.push_back(c);
	zidovi.push_back(d);
	zidovi.push_back(e);
	zidovi.push_back(f);
	zidovi.push_back(g);
	zidovi.push_back(h);
	zidovi.push_back(i);
	zidovi.push_back(j);
	zidovi.push_back(a);
	

	Room sampleRoom(zidovi);
	sampleRoom.Draw();


	a = glm::vec3(0.25f + xx, 0.0f, zz + 0.25f);
	b  = glm::vec3(-0.25f  + xx, 0.0f, zz + 0.25f);
	c = glm::vec3(-0.25f + xx, 0.0f, zz - 0.25f);
	d = glm::vec3(0.25f + xx, 0.0f, zz - 0.25f);

	kaoCovek.push_back(a);
	kaoCovek.push_back(b);
	kaoCovek.push_back(c);
	kaoCovek.push_back(d);

	Person testCovek(kaoCovek);
	testCovek.Draw();
	glutSwapBuffers();
}

static void on_reshape(int width, int height)
{
	width_a = width;
	height_a = height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (float) width/height,0.01, 1000);
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
		case 'j':
			yy_par += 0.05f;
			break;
		case 'k':
			yy_par -= 0.05f;
			break;
		case 'n':
			yy += 0.1f;
			break;
		case 'm':
			yy -= 0.1f;
			break;
		case 32: //spacebar
			if(!jump_ongoing){
				glutTimerFunc(TIMER_INTERVAL2, on_timer2, TIMER_ID2);
				jump_ongoing = 1;
			}
			break;
	}

	//std::cout << "x " << xx << " || z " << zz << std::endl;
	//std::cout << "lx " << lx << " || lz " << lz << std::endl;
	//std::cout << "angle " << angle << std::endl;
	//std::cout << "fraction " << fraction << std::endl;
	//printf("x %f || z %f\nlx %f || lz %f\nangle %f\nfraction %f\n",xx , zz, lx, lz, angle, fraction);

	glutPostRedisplay();
}

static void on_mouse(int x, int y){
	if(x > width_a/2)
		angle += x*0.00005f;
	if(x < width_a/2)
		angle -= x*0.00005f;
	if(y > height_a/2)
		//yy_par -= 0.01f;
		angle1 -= y*0.00005f;
	if(y < height_a/2)
		//yy_par += 0.01f;
		angle1 += y*0.000005f;
	lx = sin(angle);
	lz = -cos(angle);

}
