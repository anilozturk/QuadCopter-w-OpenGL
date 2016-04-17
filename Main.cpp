#include <gl/glut.h>
#include <gl/GLU.h>

float moveX = 0.0;
float moveY = 0.0;
int degree = 2;
int play = 0;
float eyeX = 0.0;
float eyeY = 0.0;
float eyePos = 20.0;
float rotateX = 0;
float rotateY = 0;
float rotateZ = 0;
float boyutX = 1.0;
float boyutY = 1.0;
float boyutZ = 1.0;

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 54: // quadcopter'in ileri hareketini sa�lar (klavyedeki 6 tu�u)
		play = 1; // quadcopter'e hareket komutu verdi�imizde pervaneleri d�nmeye ba�l�ycak
		moveX += 0.2;
		moveY -= 0.2;
		glutPostRedisplay();
		break;

	case 55: // quadcopter'in geri hareketini sa�lar (klavyedeki 7 tu�u)
		play = 1; // quadcopter'e hareket komutu verdi�imizde pervaneleri d�nmeye ba�l�ycak
		moveX -= 0.2;
		moveY += 0.2;
		glutPostRedisplay();
		break;

	case 27: // ESC tu�u ��k��� sa�lar
		exit(0);
		break;
		
	case 'a':
		eyeX += 0.5;
		glutPostRedisplay();
		break;

	case 'd':
		eyeX -= 0.5;
		glutPostRedisplay();
		break;

	case 'w':
		eyeY += 0.5;
		glutPostRedisplay();
		break;

	case 's':
		eyeY -= 0.5;
		glutPostRedisplay();
		break;

	case 45: // '+' tu�u kameray� zoom in yapmak i�in
		eyePos += 0.3;
		glutPostRedisplay();
		break;

	case 43: // '-' tu�u kameray� zoom out yapmak i�in
		eyePos -= 0.3;
		glutPostRedisplay();
		break;

	case 'q': // y ekseninde rotate
		rotateY += 5;
		glutPostRedisplay();
		break;

	case 'e': // y ekseninde rotate
		rotateY -= 5;
		glutPostRedisplay();
		break;

	case 'r': // x ekseninde rotate
		rotateX += 5;
		glutPostRedisplay();
		break;

	case 'f': // x ekseninde rotate
		rotateX -= 5;
		glutPostRedisplay();
		break;

	case 'z': // z ekseninde rotate
		rotateZ += 5;
		glutPostRedisplay();
		break;

	case 'x': // z ekseninde rotate
		rotateZ -= 5;
		glutPostRedisplay();
		break;

	case 'b': // quadcopter'in boyutu b�y�r
		boyutX += 0.10;
		boyutY += 0.10;
		boyutZ += 0.10;
		glutPostRedisplay();
		break;

	case 'k': // quadcopter'in boyutu k���l�r
		boyutX -= 0.10;
		boyutY -= 0.10;
		boyutZ -= 0.10;
		glutPostRedisplay();
		break;
	}
}

void timer(int id) // quadcopter'in pervanelerinin d�nmesi i�in bir zamanlay�c� fonksiyonu
{
	if (play == 1)
	{
		degree += 2;
		glutPostRedisplay();
	}
	glutTimerFunc(10, timer, 0);
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
}

void drawLines(void) // quadcopter'in pervaneleri �izdiriliyor
{
	glColor3f(148, 0, 211);
	glLineWidth(6);

	glPushMatrix();	// her torus i�in pervanelerinin koordinatlar� ve rotate'leri ayarlan�yor
					// 4 adet torusumuz var
	glTranslatef(5, 0, 4.3);
	glRotatef(degree, 0, 0, 1);

	for (int i = 0; i < 3; i++){
		glRotatef(60, 0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-1.7, 0);
		glVertex2f(1.7, 0);
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	glRotatef(60, 0, 0, 1);
	glTranslatef(5, 0, 4.3);
	glRotatef(degree, 0, 0, 1);

	for (int i = 0; i < 3; i++){
		glRotatef(60, 0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-1.7, 0);
		glVertex2f(1.7, 0);
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	glTranslatef(5, 0, 4.3);
	glRotatef(degree, 0, 0, 1);

	for (int i = 0; i < 3; i++){
		glRotatef(60, 0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-1.7, 0);
		glVertex2f(1.7, 0);
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	glRotatef(240, 0, 0, 1);
	glTranslatef(5, 0, 4.3);
	glRotatef(degree, 0, 0, 1);

	for (int i = 0; i < 3; i++){
		glRotatef(60, 0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-1.7, 0);
		glVertex2f(1.7, 0);
		glEnd();
	}
	glPopMatrix();
}

void drawTorus(void)
{
	glPushMatrix();
	glTranslatef(-5, 0, 4);
	glutSolidTorus(0.2, 2.0, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, -4.33, 4);
	glutSolidTorus(0.2, 2.0, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 0, 4);
	glutSolidTorus(0.2, 2.0, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, 4.5, 4);
	glutSolidTorus(0.2, 2.0, 20, 20);
	glPopMatrix();
}

void drawFans(void) // her fan bir torus ve ona ba�l� pervanelerden olu�ur
{
	glColor3f(0.0, 0.0, 0.0);

	drawTorus();
	drawLines();
}

void drawBox1(void) // kutular dikd�rtgenler prizmas� olarak d���n�lm��t�r ve quadcopter'imizin iskeletini olu�tururlar
{
	glRotatef(60, 0, 0, 1);

	glBegin(GL_POLYGON);//front
	glVertex3f(5, 0.2, -0.2);
	glVertex3f(5, -0.2, -0.2);
	glVertex3f(-5, -0.2, -0.2);
	glVertex3f(-5, 0.2, -0.2);
	glEnd();

	glBegin(GL_POLYGON);//back
	glVertex3f(5, 0.2, 0.2);
	glVertex3f(5, -0.2, 0.2);
	glVertex3f(-5, -0.2, 0.2);
	glVertex3f(-5, 0.2, 0.2);
	glEnd();

	glBegin(GL_POLYGON);//right
	glVertex3f(5, 0.2, -0.2);
	glVertex3f(5, 0.2, 0.2);
	glVertex3f(5, -0.2, 0.2);
	glVertex3f(5, -0.2, -0.2);
	glEnd();

	glBegin(GL_POLYGON);//left
	glVertex3f(-5, 0.2, -0.2);
	glVertex3f(-5, -0.2, -0.2);
	glVertex3f(-5, -0.2, 0.2);
	glVertex3f(-5, 0.2, 0.2);
	glEnd();

	glBegin(GL_POLYGON);//top
	glVertex3f(-5, 0.2, -0.2);
	glVertex3f(5, 0.2, -0.2);
	glVertex3f(5, 0.2, 0.2);
	glVertex3f(-5, 0.2, 0.2);
	glEnd();

	glBegin(GL_POLYGON);//bottom
	glVertex3f(-5, -0.2, -0.2);
	glVertex3f(-5, -0.2, 0.2);
	glVertex3f(5, -0.2, 0.2);
	glVertex3f(5, -0.2, -0.2);
	glEnd();
}

void drawBox2(void) // 6 y�ze sahiptir
{
	glBegin(GL_POLYGON);//front
	glVertex3f(5, 0.2, -0.2);
	glVertex3f(5, -0.2, -0.2);
	glVertex3f(-5, -0.2, -0.2);
	glVertex3f(-5, 0.2, -0.2);
	glEnd();

	glBegin(GL_POLYGON);//back
	glVertex3f(5, 0.2, 0.2);
	glVertex3f(5, -0.2, 0.2);
	glVertex3f(-5, -0.2, 0.2);
	glVertex3f(-5, 0.2, 0.2);
	glEnd();

	glBegin(GL_POLYGON);//right
	glVertex3f(5, 0.2, -0.2);
	glVertex3f(5, 0.2, 0.2);
	glVertex3f(5, -0.2, 0.2);
	glVertex3f(5, -0.2, -0.2);
	glEnd();

	glBegin(GL_POLYGON);//left
	glVertex3f(-5, 0.2, -0.2);
	glVertex3f(-5, -0.2, -0.2);
	glVertex3f(-5, -0.2, 0.2);
	glVertex3f(-5, 0.2, 0.2);
	glEnd();

	glBegin(GL_POLYGON);//top
	glVertex3f(-5, 0.2, -0.2);
	glVertex3f(5, 0.2, -0.2);
	glVertex3f(5, 0.2, 0.2);
	glVertex3f(-5, 0.2, 0.2);
	glEnd();

	glBegin(GL_POLYGON);//bottom
	glVertex3f(-5, -0.2, -0.2);
	glVertex3f(-5, -0.2, 0.2);
	glVertex3f(5, -0.2, 0.2);
	glVertex3f(5, -0.2, -0.2);
	glEnd();
}

void drawBody(void)
{
	glColor3f(0.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(0, 0, 4);
	drawBox1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 4);
	drawBox2();
	glPopMatrix();
}

void drawCylinder(void) // i�i bo� bir silindir olu�turduk ve buna 2 adet kapak yapt�k, bunun i�in gluDisk kulland�k
{						// 2 diskin her biri silindirin bir ucu i�indir
	glPushMatrix();
	glColor3f(0, 139, 139);
	glTranslatef(0, 0, 4);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, 1, 1, 2.0f, 32, 32);

	glRotatef(180, 1, 0, 0);
	gluDisk(quadratic, 0, 1, 32, 1);
	glRotatef(180, 1, 0, 0);
	glTranslatef(0, 0, 2);
	gluDisk(quadratic, 0, 1, 32, 1);
	glTranslatef(0, 0, -2);
	glPopMatrix();
}

void drawTriangle(void)// quadcopter'in hangi y�nde hareket edece�ini g�steren ��gen
{
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0, 0, 4);
	glRotatef(30, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.8, 0.7, 2);
	glVertex3f(0, -0.9, 2);
	glVertex3f(-0.8, 0.7, 2);
	glEnd();
	glPopMatrix();
}

void drawQuadcopter(void)
{
	glRotatef(rotateY, 0, 1, 0);
	glRotatef(rotateX, 1, 0, 0);
	glRotatef(rotateZ, 0, 0, 1);

	drawBody();
	drawFans();
	drawCylinder();
	drawTriangle();
}

/*void drawCoordinates(void) // koordinat sistemini referans olmas� i�in �izdik
{
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0); //x koordinat� ye�il renk
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0); // y koordinat� k�rm�z� renk
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 20.0, 0.0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0); //z koordinat� mavi renk
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 20.0);
	glEnd();
	glPopMatrix();
}*/

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyePos,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
	glTranslatef(moveX, moveY, 0);
	glScalef(boyutX, boyutY, boyutZ);
	drawQuadcopter();
	//drawCoordinates();
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Quadcopter Simulation");

	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(100, timer, 0);
	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}