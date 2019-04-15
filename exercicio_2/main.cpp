/* Código inicial no OpenGL */

#include <GL/glut.h>

#define LARGURA  600		/* Width */
#define ALTURA   600		/* Heigth */

float x_corpo = 80;
float y_corpo = 50;

float x_cabeca = 90;
float y_cabeca = 360;

float x_braco = 200;
float y_braco = 200;

float x_antebraco = 200;
float y_antebraco = 90;

float translate_y = 0;
float translate_x = 0;

float sx = 1;
float sy = 1;

float rb = 0;
float rab = 0;

void Desenha_corpo_cor_azul()
{
	/* Define a cor do quadrado para azul */
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2i(x_corpo, y_corpo);
		glVertex2i(x_corpo, y_corpo + 300);
		glVertex2i(x_corpo +120, y_corpo + 300);
		glVertex2i(x_corpo +120, y_corpo);
	glEnd();
}

void Desenha_cabeca_cor_azul()
{
	/* Define a cor do quadrado para azul */
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2i(x_cabeca, y_cabeca);
		glVertex2i(x_cabeca, y_cabeca + 100);
		glVertex2i(x_cabeca + 100, y_cabeca + 100);
		glVertex2i(x_cabeca + 100, y_cabeca);
	glEnd();
}

void Desenha_braco()
{
	/* Define a cor do quadrado para azul */
	glColor3f(0.2f, 0.7f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2i(x_braco, x_braco);
		glVertex2i(x_braco, x_braco + 150);
		glVertex2i(x_braco + 50, x_braco + 150);
		glVertex2i(x_braco+ 50, x_braco);
	glEnd();
}

void Desenha_antebraco()
{
	/* Define a cor do quadrado para azul */
	glColor3f(0.0f, 0.3f, 0.5f);
	glBegin(GL_QUADS);
		glVertex2i(x_antebraco, y_antebraco);
		glVertex2i(x_antebraco, y_antebraco + 110);
		glVertex2i(x_antebraco + 50, y_antebraco + 110);
		glVertex2i(x_antebraco + 50, y_antebraco);
	glEnd();
}

/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	/* Carrega na matriz corrente a matriz identidade */

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

	glTranslatef(translate_x, translate_y, 0.0);
	glScalef(sx, sy, 0.0);

	Desenha_corpo_cor_azul();

    Desenha_cabeca_cor_azul();

	glTranslatef(220, 350, 0.0);

	glRotatef(rb, 0.0, 0.0, 1.0);

	glTranslatef(-220, -350, 0.0); 
	Desenha_braco();

	glTranslatef(x_antebraco+25, y_antebraco + 110, 0.0);

	glRotatef(rab, 0.0, 0.0, 1.0);

	glTranslatef(-(x_antebraco+25), -(y_antebraco + 110), 0.0); 
    Desenha_antebraco();

	/* Executa os comandos OpenGL */
	glFlush();
}

void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
		case 'A':
		case 'a':
			sx += 0.01;
			sy += 0.01;
			break;

		case 'D':
		case 'd':
			sx -= 0.01;
			sy -= 0.01;
			break;

		case 'R':
			rb += 1;
			break;

		case 'r':
			rab += 1;
			break;

		case 'T':
			rb -= 1;
			break;

		case 't':
			rab -= 1;
			break;

		case 'q':
			exit(1);
			break;
    }

    /* Necessário chamar toda vez que se faz uma alteração ou evento na janela
     * Indica a funcao glutMainLoop a chamar glutDisplayFunc com as alterações */
    glutPostRedisplay();
}


void GerenciaSetas(int key, int x, int y)
{
    switch (key) {
		case GLUT_KEY_UP:
            translate_y += 10;
            break;

		case GLUT_KEY_DOWN:
			translate_y -= 10;
			break;

		case GLUT_KEY_LEFT:
			translate_x -= 10;
			break;

		case GLUT_KEY_RIGHT:
			translate_x += 10;
			break;
        
    }

    /* Necessário chamar toda vez que se faz uma alteração ou evento na janela
     * Indica a funcao glutMainLoop a chamar glutDisplayFunc com as alterações */
    glutPostRedisplay();
}

/* Inicializa parâmetros de rendering */
void Inicializa (void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, LARGURA, 0, ALTURA, -1 ,1);

}

/* Programa Principal */
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Robo");
	glutDisplayFunc(Desenha);
    glutSpecialFunc(GerenciaSetas);
    glutKeyboardFunc(GerenciaTeclado);
	Inicializa();
	glutMainLoop();
}

