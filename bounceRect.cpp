#include <windows.h>
#include <GL\glut.h>

GLfloat x = 0;
GLfloat y = 0;
GLfloat x2 = 10;
GLfloat y2 = 10;
GLfloat x3 = -10;
GLfloat y3 = -10;
GLfloat x4 = 20;
GLfloat y4 = -20;



GLsizei rsize = 50.0f;

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
GLfloat x2step = -1.0f;
GLfloat y2step = -1.0f;
GLfloat x3step = 2.0f;
GLfloat y3step= 2.0f;
GLfloat x4step = -3.0f;
GLfloat y4step = -3.0f;


GLfloat window_width;
GLfloat window_height;

void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	glRectf(x, y, x + rsize, y + rsize);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glRectf(x2, y2, x2 + rsize, y2 + rsize);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);
	glRectf(x3, y3, x3 + rsize, y3 + rsize);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0f, 0.0f, 1.0f);
	glRectf(x4, y4, x4 + rsize, y4 + rsize);
	glPopMatrix();
	glutSwapBuffers();
}

void BoundCheck(GLfloat* dx, GLfloat* dy, GLfloat* dxStep, GLfloat* dyStep) {

	if (*dx > window_width - rsize || *dx < -window_width) {
		*dxStep = -(*dxStep);
	}
	if (*dy > window_height - rsize || *dy < -window_height) {
		*dyStep = -(*dyStep);
	}
	if (*dx > window_width - rsize) {
		*dx = window_width - rsize - 1;
	}
	if (*dy > window_height - rsize) {
		*dy = window_height - rsize - 1;
	}

	*dx += *dxStep;
	*dy += *dyStep;
}

void TimerFunction(int value) {
	BoundCheck(&x,&y,&xstep,&ystep);
	BoundCheck(&x2, &y2, &x2step, &y2step);
	BoundCheck(&x3,&y3,&x3step,&y3step);
	BoundCheck(&x4,&y4,&x4step,&y4step);
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
	//idleFunc
}

void SetupRC(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void ChangeSize(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) {
		window_width = 100.0f;
		window_height = 100.0f *h/w;
		glOrtho(-100.0f, 100.0f, -window_height, window_height, 1.0, -1.0);
	}
	else {
		window_width = 100.0f * w / h;
		window_height = 100.0f;
		glOrtho(-window_width, window_width, -100.0f, 100.0f, 1.0, -1.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("BounceRectangle");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(2000, TimerFunction, 1);
	SetupRC();
	glutMainLoop();
}