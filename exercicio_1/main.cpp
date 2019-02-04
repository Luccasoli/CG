#include <GL/glut.h>

#define LARGURA 500 /* Width */
#define ALTURA 500  /* Heigth */

void Desenha_triangulo()
{
    /* Define a cor do desenho para azul */
    glColor3f(1, 1, 1);

    /* Desenha um triângulo na cor corrente */
    glBegin(GL_TRIANGLES);
    glVertex2i(0, ALTURA / 2);
    glVertex2i(LARGURA / 2, ALTURA);
    glVertex2i(LARGURA, ALTURA / 2);
    glEnd();
}

void Quadrado()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glVertex2i(0, ALTURA / 2);
    glVertex2i(LARGURA / 2, ALTURA);
    glVertex2i(LARGURA, ALTURA / 2);
    glColor3f(0, 0, 1);
    glVertex2i(LARGURA / 2, 0);

    glEnd();
}

void QuadradoCentro()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_QUADS);
    glLineWidth(5.0f);
    glColor3f(1, 1, 1); // Branco
    glVertex2i(LARGURA, ALTURA / 2);
    glColor3f(0, 1, 0); // Verde
    glVertex2i(LARGURA, ALTURA);
    glColor3f(0, 0, 0); // Preto
    glVertex2i(LARGURA / 2, ALTURA);
    glColor3f(1, 0, 0); // Vermelho
    glVertex2i(LARGURA / 2, ALTURA / 2);
    // glColor3f(1, 1, 1); // Branco
    glEnd();
}

void LinhasConsecutivas()
{
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glLineWidth(1.3);
    glColor3f(0, 0, 0);

    glBegin(GL_LINE_STRIP);
    glVertex2i(LARGURA / 2, 0);
    glVertex2i(LARGURA / 2 + 100, 2 * ALTURA / 3);
    glColor3f(0, 1, 0);
    glVertex2i(LARGURA / 3 - 50, ALTURA / 3 + 60);
    glEnd();
}

void Desenha(void)
{
    /* Limpa a janela de visualização com a cor de fundo especificada */
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, ALTURA/2, 250, ALTURA/2);
    glScissor(0, ALTURA/2, 250, ALTURA/2);
    glEnable(GL_SCISSOR_TEST);
    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Desenha_triangulo();

    glViewport(LARGURA/2, ALTURA/2, LARGURA/2, ALTURA/2);
    glScissor(250, ALTURA/2, 250, ALTURA/2);
    glEnable(GL_SCISSOR_TEST);
    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Quadrado();

    glViewport(0, 0, LARGURA/2, ALTURA/2);
    glScissor(0, 0, LARGURA/2, ALTURA/2);
    glEnable(GL_SCISSOR_TEST);
    glClearColor(0, 1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    LinhasConsecutivas();

    // glDisable(GL_SCISSOR_TEST);
    glViewport(LARGURA/2, 0, LARGURA/2, ALTURA/2);
    glScissor(LARGURA/2, 0, LARGURA/2, ALTURA/2);
    glEnable(GL_SCISSOR_TEST);
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    QuadradoCentro();

    /* Executa os comandos OpenGL */
    glFlush();
}

void Inicializa(void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glOrtho(0, LARGURA, 0, ALTURA, -1, 1);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(LARGURA, ALTURA);
    // glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercicio 1");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutMainLoop();
}