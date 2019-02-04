/* Código inicial no OpenGL */

#include <GL/glut.h>

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

void Desenha_quadrado_cor_verde()
{
	/* Define a cor do quadrado para verde */
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2i(100, 200);
		glVertex2i(100, 300);
		glVertex2i(200, 300);
		glVertex2i(200, 200);
	glEnd();

	/* Define um ponto na cor preta */
	glColor3f(0.0, 0.0, 0.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(150, 250);
	glEnd();
}

void Desenha_quadrado_cor_azul()
{
	/* Define a cor do quadrado para azul */
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2i(300, 200);
		glVertex2i(300, 300);
		glVertex2i(400, 300);
		glVertex2i(400, 200);
	glEnd();

	/* Define um ponto na cor preta */
	glColor3f(0.0, 0.0, 0.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(350, 250);
	glEnd();
}

/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	/* Especifica que as transformações irão alterar os desenhos (modelos) */
	glMatrixMode(GL_MODELVIEW);  
	/* Carrega na matriz corrente a matriz identidade */
	glLoadIdentity();	

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

	glScalef(0.5, 0.5, 1.0);
	glTranslatef(0.0, 50.0, 0.0);
	Desenha_quadrado_cor_verde();

	/* Empilha uma matriz para realizar transformações somente no quadrado verde */
	glPushMatrix();
	/* Carrega nessa nova matriz a identidade para ignorar qualquer 
	   transformação anterior */
	glLoadIdentity();
	glTranslatef(0.0, 50.0, 0.0);
	Desenha_quadrado_cor_azul();

	/* Desempilha a matriz criada por glPushMatriz e carrega na pilha a matriz anterior */
	glPopMatrix();

	/* Executa os comandos OpenGL */
	glFlush();
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
	Inicializa();
	glutMainLoop();
}

