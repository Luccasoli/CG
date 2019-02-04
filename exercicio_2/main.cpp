/* Código inicial no OpenGL */

#include <GL/glut.h>

#define LARGURA  500		/* Width */
#define ALTURA   600		/* Heigth */

float deslocamento = 0;
float x_corpo = 80;
float y_corpo = 50;

float x_cabeca = 80;
float y_cabeca = 360;

float x_braco = 200;
float y_braco = 200;

float x_antebraco = 200;
float y_antebraco = 120;

float translate_y = 0;
float translate_x = 0;

bool tx_bool = false;
bool ty_bool = false;

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

void Desenha_cabeca_cor_verde()
{
	/* Define a cor do quadrado para azul */
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2i(x_cabeca, y_cabeca);
		glVertex2i(x_cabeca, y_cabeca + 120);
		glVertex2i(x_cabeca + 120, y_cabeca + 120);
		glVertex2i(x_cabeca + 120, y_cabeca);
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
		glVertex2i(x_antebraco, y_antebraco + 80);
		glVertex2i(x_antebraco + 50, y_antebraco + 80);
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

	/* P_vermelhor = (250, 400) */
	/* P_verde = (250, 250) */
	/* P_azul = (250, 100) */

	// glTranslatef(250.0, 400.0, 1.0);
	// glScalef(0.5, 0.5, 1.0);
	// glTranslatef(-250.0, -400.0, 0.0);
	// Desenha_quadrado_cor_vermelho();

	// glPushMatrix();
	// glLoadIdentity();

	// glTranslatef(250.0, 250.0, 0.0);
	// glRotatef(30.0, 0.0, 0.0, 1.0);
	// glTranslatef(-250.0, -250.0, 0.0);
	// Desenha_quadrado_cor_verde();

	// glPopMatrix();

	glLoadIdentity();
    
    if(tx_bool) {
        glTranslatef(10.0, 0.0, 1.0);
        tx_bool = !tx_bool;
    }

    if(ty_bool) {
        glTranslatef(0.0, translate_y, 1.0);
        ty_bool = !ty_bool;
    }

	Desenha_corpo_cor_azul();

    Desenha_cabeca_cor_verde();

    Desenha_braco();

    Desenha_antebraco();

	/* Executa os comandos OpenGL */
	glFlush();
}

void GerenciaTeclado(int key, int x, int y)
{
    switch (key) {
		case GLUT_KEY_UP:
            ty_bool = true;
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
	glutCreateWindow("Transformacoes");
	glutDisplayFunc(Desenha);
    glutSpecialFunc(GerenciaTeclado);
	Inicializa();
	glutMainLoop();
}

