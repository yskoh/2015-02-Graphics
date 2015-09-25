#include <gl/glut.h>
#include <windows.h>
#include <math.h>
#include <stdio.h>
GLfloat xRot = 0.0f;
GLfloat yRot = 0.0f;


void SetupRC() {
	glClearColor(1.0f, 1.0f,1.0f,6.0f);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glShadeModel(GL_SMOOTH);
}

void ChangeSize(int w, int h) 
{
	GLfloat fAspect;
	glViewport(0,0,w,h);
	fAspect = (GLfloat)w /(GLfloat)h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0f, fAspect, 1.0f, 500.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f,0.0f,-100.0f);
}

void KeyControl(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
		xRot -= 5.0f;
	if(key == GLUT_KEY_DOWN)
		xRot += 5.0f;
	if(key == GLUT_KEY_LEFT)
		yRot -= 5.f;
	if(key == GLUT_KEY_RIGHT)
		yRot += 5.f;

	glutPostRedisplay();
}
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f,1.0f,0.0f);
	glScalef(20.0f, 20.0f, 20.0f);
	
	glBegin(GL_TRIANGLES);
	//(0, 3, 2)
	// 0 
	glColor3ub((GLubyte)0, (GLubyte)0, (GLubyte)255);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	// 3
	glColor3ub((GLubyte)0, (GLubyte)255, (GLubyte)0);
	glVertex3f(1.0f, 1.0f, -1.0f);
	// 2
	glColor3ub((GLubyte)255, (GLubyte)0, (GLubyte)0);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	//(0, 1, 3)
	// 0 
	glColor3ub((GLubyte)0, (GLubyte)0, (GLubyte)255);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	// 1
	glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte)0);
	glVertex3f(1.0f, -1.0f, -1.0f);
	// 3
	glColor3ub((GLubyte)0, (GLubyte)255, (GLubyte)0);
	glVertex3f(1.0f, 1.0f, -1.0f);

	//(2, 6, 7)
	// 2
	glColor3ub((GLubyte)255, (GLubyte)0, (GLubyte)0);
	glVertex3f(-1.0f, 1.0f, -1.0f);  
	//6
	glColor3ub((GLubyte)255,  (GLubyte)0, (GLubyte)0);
	glVertex3f(1.0f, 1.0f, 1.0f);
	//7
	glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte) 0);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	//(2, 3, 6)
	// 2
	glColor3ub((GLubyte)255, (GLubyte)0, (GLubyte)0);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	// 3
	glColor3ub((GLubyte)0, (GLubyte)255, (GLubyte)0);
	glVertex3f(1.0f, 1.0f, -1.0f);
	//6
	glColor3ub((GLubyte)255,  (GLubyte)0, (GLubyte)0);
	glVertex3f(1.0f, 1.0f, 1.0f);

	//(7,4,5)
	//7
	glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte) 0);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	//4
	glColor3ub((GLubyte)0, (GLubyte)255, (GLubyte)0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	//5
	glColor3ub((GLubyte)0, (GLubyte)0, (GLubyte)255);
	glVertex3f(1.0f, -1.0f, 1.0f);
	//(5,6,7)
	//5
	glColor3ub((GLubyte)0, (GLubyte)0, (GLubyte)255);
	glVertex3f(1.0f, -1.0f, 1.0f);
	//6
	glColor3ub((GLubyte)255,  (GLubyte)0, (GLubyte)0);
	glVertex3f(1.0f, 1.0f, 1.0f);
	//7
	glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte) 0);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	
	//(3,1,5)
	// 3
	glColor3ub((GLubyte)0, (GLubyte)255, (GLubyte)0);
	glVertex3f(1.0f, 1.0f, -1.0f);
	// 1
	glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte)0);
	glVertex3f(1.0f, -1.0f, -1.0f);
	//5
	glColor3ub((GLubyte)0, (GLubyte)0, (GLubyte)255);
	glVertex3f(1.0f, -1.0f, 1.0f);
	//(3,5,6)
	// 3
	glColor3ub((GLubyte)0, (GLubyte)255, (GLubyte)0);
	glVertex3f(1.0f, 1.0f, -1.0f);
	//5
	glColor3ub((GLubyte)0, (GLubyte)0, (GLubyte)255);
	glVertex3f(1.0f, -1.0f, 1.0f);
	//6
	glColor3ub((GLubyte)255,  (GLubyte)0, (GLubyte)0);
	glVertex3f(1.0f, 1.0f, 1.0f);
	
	//(7,4,2)
	//7
	glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte) 0);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	//4
	glColor3ub((GLubyte)0, (GLubyte)255, (GLubyte)0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	// 2
	glColor3ub((GLubyte)255, (GLubyte)0, (GLubyte)0);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	//(2,4,0)
	// 2
	glColor3ub((GLubyte)255, (GLubyte)0, (GLubyte)0);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	//4
	glColor3ub((GLubyte)0, (GLubyte)255, (GLubyte)0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	// 0 
	glColor3ub((GLubyte)0, (GLubyte)0, (GLubyte)255);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	//(4,0,1)
	//4
	glColor3ub((GLubyte)0, (GLubyte)255, (GLubyte)0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	// 0 
	glColor3ub((GLubyte)0, (GLubyte)0, (GLubyte)255);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	// 1
	glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte)0);
	glVertex3f(1.0f, -1.0f, -1.0f);
	//(4,1,5)
	//4
	glColor3ub((GLubyte)0, (GLubyte)255, (GLubyte)0);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	// 1
	glColor3ub((GLubyte)255, (GLubyte)255, (GLubyte)0);
	glVertex3f(1.0f, -1.0f, -1.0f);
	//5
	glColor3ub((GLubyte)0, (GLubyte)0, (GLubyte)255);
	glVertex3f(1.0f, -1.0f, 1.0f);
	
	glEnd();
	// Flush drawing commands
	glPopMatrix();
	glutSwapBuffers();
}

void TimerFunc(int dTime)
{
	glutPostRedisplay();
	glutTimerFunc(dTime, TimerFunc, dTime);
}

void main(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cube");

	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(KeyControl);
	glutDisplayFunc(RenderScene);
	glutTimerFunc(33, TimerFunc, 1);
	SetupRC();
	glutMainLoop();
}