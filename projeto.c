#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "stdio.h"

static int shoulder_x = 0, shoulder_y = 0, shoulder_z = 0, elbow_x, elbow_y, elbow_z = 0;

void init(void) 
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}
//a translacao dos cilindros é feita somada com a da transformacao para ajustar a movimentacao
void display(void)
{
	GLUquadricObj *obj = gluNewQuadric();
	glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	//desenha primeira esfera
	glPushMatrix();
	glTranslatef (0.0, -2.2, 0.0);//translate objeto
	gluSphere(obj, 0.3, 30, 30);//desenhar esfera
	glPopMatrix();

	//desenha primeiro cilindro
	glTranslatef (0.0, -2.2, 0.0);//translate objeto
	glRotatef ((GLfloat) shoulder_x, 1.0, 0.0, 0.0);//rotate x
	glRotatef ((GLfloat) shoulder_y, 0.0, 1.0, 0.0);//rotate y
	glRotatef ((GLfloat) shoulder_z, 0.0, 0.0, 1.0);//rotate z
	//printf("%i %i %i \n",shoulder_x,shoulder_y,shoulder_z);//teste
	glTranslatef (0.0, 0.2, 0.0);//translate transformacao
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);//ajuste
	gluCylinder(obj, 0.2, 0.2, 2, 30, 30);//desenhar cilindro
	glPopMatrix();

	//desenha segunda esfera
	glPushMatrix();
	glTranslatef (0.0, 2.2, 0.0);//translate objeto
	gluSphere(obj, 0.3, 30, 30);//desenhar cilindro - salva variaveis
	glPopMatrix();

	//desenha segundo cilindro
	glTranslatef (0.0, 2.2, 0.0);//translate objeto
	glRotatef ((GLfloat) elbow_x, 1.0, 0.0, 0.0);
	glRotatef ((GLfloat) elbow_y, 0.0, 1.0, 0.0);
	glRotatef ((GLfloat) elbow_z, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.2, 0.0);//translate transformacao
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(obj, 0.2, 0.2, 2, 30, 30);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef (0.0, 0.0, -10.0);
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key) {
		case 'q':
			if (shoulder_x > -60) {shoulder_x -= 5;}
			glutPostRedisplay();
		break;
		case 'w':
			if (shoulder_x < 60) {shoulder_x +=5;}
			glutPostRedisplay();
		break;
		case 'r':
			if (shoulder_y > -60) {shoulder_y -= 5;}
			glutPostRedisplay();
		break;
		case 'e':
			if (shoulder_y < 60) {shoulder_y +=5;}
			glutPostRedisplay();
		break;
		case 'y':
			if (shoulder_z > -60) {shoulder_z -= 5;}
			glutPostRedisplay();
		break;
		case 't':
			if (shoulder_z < 60) {shoulder_z +=5;}
			glutPostRedisplay();
		break;
		case 'a':
			if (elbow_x > -60) {elbow_x -= 5;}
			glutPostRedisplay();
		break;
		case 's':
			if (elbow_x < 60) {elbow_x +=5;}
			glutPostRedisplay();
		break;
		case 'f':
			if (elbow_y > -60) {elbow_y -= 5;}
			glutPostRedisplay();
		break;
		case 'd':
			if (elbow_y < 60) {elbow_y +=5;}
			glutPostRedisplay();
		break;
		case 'h':
			if (elbow_z > -60) {elbow_z -= 5;}
			glutPostRedisplay();
		break;
		case 'g':
			if (elbow_z < 60) {elbow_z +=5;}
			glutPostRedisplay();
		break;
		default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800, 800); 
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
