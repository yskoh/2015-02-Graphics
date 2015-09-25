#include <gl/glut.h>
#include <windows.h>
#include <math.h>

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

void SetupRC(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);

	 GLfloat amb[] = {0.2f,0.2f,0.2f};
    
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
	glEnable(GL_COLOR_MATERIAL);
    
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	
    GLfloat diff[] = { 1.0f,1.0f,1.0f};
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    
    glEnable(GL_LIGHTING);
    
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diff);
    glEnable(GL_LIGHT0);
    
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}
void TimerFunc(int value) {
	glutPostRedisplay();
	glutTimerFunc(100, TimerFunc, 1);
}
void ChangeSize(int w, int h) {
	GLfloat nRange = 100.0f;
	GLfloat lightPos[] = { 0.0f, 0.0f, -100.0f, 1.0f };
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange*2.0f, nRange*2.0f);
	else
		glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange*2.0f, nRange*2.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

}

void RenderScene() {
	static GLfloat fElect1 = 0.0f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -100.0f);
	glColor3ub(255, 0, 0);
	glutSolidSphere(10.0f, 15, 15);
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 60.0f);
	glColor3ub(125,0,125);
	glutSolidSphere(6.0f, 15, 15);
	glPopMatrix();
	glPushMatrix();
	glRotatef(180.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 90.0f);
	glColor3ub(255, 255, 0);
	glutSolidSphere(6.0f, 15, 15);
	glPopMatrix();
	glPushMatrix();
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(-70.0f, 0.0f, 0.0f);
	glColor3ub(0,0,255);
	glutSolidSphere(6.0f, 15, 15);
	glPopMatrix();
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(fElect1, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 60.0f);
	glutSolidSphere(6.0f, 15, 15);
	glPopMatrix();
	
	fElect1 += 10.0f;
	if (fElect1 > 360.0f)
		fElect1 = 0.0f;
	glutSwapBuffers();
}

void KeyControl(int key, int x, int y) {
	if (key == GLUT_KEY_DOWN) {
		xRot += 5.0f;
	}
	if (key == GLUT_KEY_UP) {
		xRot -= 5.0f;
	}
	if (key == GLUT_KEY_LEFT) {
		yRot -= 5.0f;
	}
	if (key == GLUT_KEY_RIGHT) {
		yRot += 5.0f;
	}
	glutPostRedisplay();
}

void main(int argc, char*argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("SolarSysOrbit");

	glutReshapeFunc(ChangeSize);
	glutTimerFunc(33, TimerFunc, 1);
	//add
	glutSpecialFunc(KeyControl);
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
}