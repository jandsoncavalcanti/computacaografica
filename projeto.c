#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "stdio.h"

static int shoulder_y = 0, shoulder_z = 0, elbow_x, elbow_y, elbow_z = 0, hand_y = 0, hand_z = 0;

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

	glPushMatrix();
	glTranslatef (6.0, 0.0, 0.0);//translate objeto
	gluSphere(obj, 0.3, 30, 30);//desenhar cilindro
	glPopMatrix();

	//desenha primeira esfera
	glPushMatrix();
	glTranslatef (0.0, -2.2, 0.0);//translate objeto
	gluSphere(obj, 0.3, 30, 30);//desenhar esfera
	glPopMatrix();

	//desenha primeiro cilindro
	glTranslatef (0.0, -2.2, 0.0);//translate objeto
	glRotatef ((GLfloat) shoulder_y, 0.0, 1.0, 0.0);//rotate y objeto
	glRotatef ((GLfloat) shoulder_z, 0.0, 0.0, 1.0);//rotate z objeto
	glTranslatef (0.0, 0.2, 0.0);//translate transformacao
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);//ajuste
	gluCylinder(obj, 0.2, 0.2, 2, 30, 30);//desenhar cilindro
	glPopMatrix();

	//desenha segunda esfera
	glPushMatrix();
	glTranslatef (0.0, 2.2, 0.0);//translate objeto
	gluSphere(obj, 0.3, 30, 30);//desenhar cilindro
	glPopMatrix();

	//desenha segundo cilindro
	glTranslatef (0.0, 2.2, 0.0);//translate objeto
	glRotatef ((GLfloat) elbow_y, 0.0, 1.0, 0.0);
	glRotatef ((GLfloat) elbow_z, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.2, 0.0);//translate transformacao
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(obj, 0.2, 0.2, 2, 30, 30);
	glPopMatrix();

	//desenha terceira esfera
	glPushMatrix();
	glTranslatef (0.0, 2.2, 0.0);//translate objeto
	gluSphere(obj, 0.3, 30, 30);//desenhar cilindro
	glPopMatrix();

	//desenha terceiro cilindro
	glTranslatef (0.0, 2.2, 0.0);//translate objeto
	glRotatef ((GLfloat) hand_y, 0.0, 1.0, 0.0);
	glRotatef ((GLfloat) hand_z, 0.0, 0.0, 1.0);
	glTranslatef (0.0, 0.2, 0.0);//translate transformacao
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(obj, 0.2, 0.2, 2, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslatef (0.0, 2.2, 0.0);//translate objeto
	gluSphere(obj, 0.3, 30, 30);//desenhar cilindro
	glPopMatrix();

	glTranslatef (0.2, 2.2, 0.0);//translate objeto
	glTranslatef (0.0, 0.2, 0.0);//translate transformacao
	glPushMatrix();
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(60.0f, 0.0f, 1.0f, 0.0f);
	gluCylinder(obj, 0.1, 0.1, 0.5, 30, 30);
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
	switch (key)
	{
		case 'w':
			if (shoulder_z > -45) {shoulder_z -= 5;}
			glutPostRedisplay();
		break;
		case 'q':
			if (shoulder_z < 45) {shoulder_z +=5;}
			glutPostRedisplay();
		break;
		case 'r':
			shoulder_y = (shoulder_y - 5) % 360;
			glutPostRedisplay();
		break;
		case 'e':
			shoulder_y = (shoulder_y + 5) % 360;
			glutPostRedisplay();
		break;
		case 's':
			if (elbow_z > -45) {elbow_z -= 5;}
			glutPostRedisplay();
		break;
		case 'a':
			if (elbow_z < 45) {elbow_z += 5;}
			glutPostRedisplay();
		break;
		case 'f':
			elbow_y = (elbow_y - 5) % 360;
			glutPostRedisplay();
		break;
		case 'd':
			elbow_y = (elbow_y +5) % 360;
			glutPostRedisplay();
		break;
		case 'x':
			if (hand_z > -45) {hand_z -= 5;}
			glutPostRedisplay();
		break;
		case 'z':
			if (hand_z < 45) {hand_z += 5;}
			glutPostRedisplay();
		break;
		case 'v':
			hand_y = (hand_y - 5) % 360;
			glutPostRedisplay();
		break;
		case 'c':
			hand_y = (hand_y +5) % 360;
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
