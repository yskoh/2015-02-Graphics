#include <gl/glut.h>
#include <math.h>
#define GL_PI 3.1415f
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void RenderScene()
{
	GLfloat x,y,angle;
	int iPivot = 1; 

	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN); 
	glVertex3f(0.0f, -90.0f, 75.0f); 
	for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f))
	{
		x = 50.0f*sin(angle);
		y = 50.0f*cos(angle);
		if((iPivot %2) == 0) // add
			glColor3f(1, 0.87, 0.57);
		else
			glColor3f(0.81, 0.7, 0.46);

		iPivot++;
		glVertex2f(x, y);
	}
	 double clipEq[4] = { 0, 0, 0.5, 1 };

    glEnable(GL_CLIP_PLANE0);
    glClipPlane(GL_CLIP_PLANE0, clipEq);
    glPushMatrix();
	glColor3f(0.99, 0.8, 0.91);
	glutSolidSphere(50.0f, 15, 15);
	glPopMatrix();
	//glPushMatrix();
	//glColor3f(0.99, 0.8, 0.91);
	//glutSolidSphere(50.0f, 15, 15);
	glEnd();
	
	glDisable(GL_CLIP_PLANE0);	
	glutSwapBuffers();
}
void SetupRC()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
	//glColor3f(0.0f, 0.0f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glFrontFace(GL_CW);
}

void KeyControl(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)
		xRot -=5.0f;
	if(key == GLUT_KEY_DOWN)
		xRot +=5.0f;
	if(key == GLUT_KEY_LEFT)
		yRot -=5.0f;
	if(key == GLUT_KEY_RIGHT)
		yRot +=5.0f;
	glutPostRedisplay();
}

void ChangeSize(int w, int h)
{
	GLfloat nRange = 100.0f;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w ,h );
	if(w<=h)
		glOrtho(-nRange,nRange,-
		nRange*h/w,nRange*h/w,-nRange, nRange);
	else
		glOrtho(-nRange*w/h,nRange*w/h,-
		nRange,nRange,-nRange, nRange);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(512,512); 
	glutCreateWindow("icecream cone");
	glutReshapeFunc(ChangeSize);
	glutSpecialFunc(KeyControl); // add
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
}