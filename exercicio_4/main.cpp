#include <GL/glut.h>
#include <stdio.h>

#define LARGURA 500 /* Width */
#define ALTURA 500  /* Heigth */

const float quadrado_altura = 80;
const float quadrado_largura = quadrado_altura + 40;
float quadrado_x = LARGURA / 2 - 100;
float quadrado_y = ALTURA / 2 - quadrado_altura / 2;

const float triangulo_altura = quadrado_altura / 2;
float triangulo_x = quadrado_x;
float triangulo_y = quadrado_y + quadrado_altura;

const float porta_altura = 0.7 * quadrado_altura;
const float porta_largura = 0.3 * quadrado_largura;
float porta_x = quadrado_x + 0.3 * quadrado_largura;
float porta_y = quadrado_y + 1;

const float janela_altura = 0.4 * porta_altura;
const float janela_largura = 0.8 * porta_largura;
float janela_x = porta_x + 1.3 * porta_largura;
float janela_y = porta_y + 0.7 * porta_altura;

void desenha_quadrado()
{
    /* Define a cor do quadrado para azul */
    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_QUADS);
    glVertex2i(quadrado_x, quadrado_y);
    glVertex2i(quadrado_x, quadrado_y + quadrado_altura);
    glVertex2i(quadrado_x + quadrado_largura, quadrado_y + quadrado_altura);
    glVertex2i(quadrado_x + quadrado_largura, quadrado_y);
    glEnd();
}

void desenha_triangulo()
{
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(triangulo_x, triangulo_y);
    glVertex2i(triangulo_x + (quadrado_largura) / 2, triangulo_y + triangulo_altura);
    glVertex2i(triangulo_x + quadrado_largura, triangulo_y);
    glEnd();
}

void desenha_porta()
{
    /* Define a cor do quadrado para azul */
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glVertex2i(porta_x, porta_y);
    glVertex2i(porta_x, porta_y + porta_altura);
    glVertex2i(porta_x + porta_largura, porta_y + porta_altura);
    glVertex2i(porta_x + porta_largura, porta_y);
    glEnd();
}

void desenha_janela()
{
    /* Define a cor do quadrado para azul */
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glVertex2i(janela_x, janela_y);
    glVertex2i(janela_x, janela_y + janela_altura);
    glVertex2i(janela_x + janela_largura, janela_y + janela_altura);
    glVertex2i(janela_x + janela_largura, janela_y);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_LINES);
    glVertex2i(janela_x, janela_y + janela_altura / 2);
    glVertex2i(janela_x + janela_largura, janela_y + janela_altura / 2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2i(janela_x + janela_largura / 2, janela_y);
    glVertex2i(janela_x + janela_largura / 2, janela_y + janela_altura);
    glEnd();
}

float x = 0;
float y = 0;
float incremento_x = 4;
float incremento_y = 3;
/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
    /* Limpa a janela de visualização com a cor de fundo especificada */
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(x, y, 0);
    desenha_quadrado();
    desenha_triangulo();
    desenha_porta();
    desenha_janela();

    glPopMatrix();
    /* Executa os comandos OpenGL */
    glutSwapBuffers();
}

void Anima(int value) /* Usada quando se usar glutTimerFunc() */
{

    // Desenha();
    x += incremento_x;
    y += incremento_y;
    if (x + quadrado_x + quadrado_largura >= 500 ||
        -x  >= quadrado_x)
        incremento_x = -incremento_x;
    if (y + quadrado_y + quadrado_largura >= 500 ||
        -y  >= quadrado_y)
        incremento_y = -incremento_y;

    printf("%f\n", x);
    glutPostRedisplay();
    glutTimerFunc(20, Anima, 1);
}

/* Inicializa parâmetros de rendering */
void Inicializa(void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glOrtho(0, LARGURA, 0, ALTURA, -1, 1);
}

/* Programa Principal */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(LARGURA, ALTURA);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Animacao OpenGL");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutTimerFunc(100, Anima, 1);
    glutMainLoop();
}
