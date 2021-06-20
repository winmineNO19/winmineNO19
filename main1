#include<stdlib.h>
#include<glut.h>
#include<iostream>
#include<cmath>
#include "minesweeper.h"
using namespace std;

//color define
#define smallCellColor glColor3f(0.658824f, 0.658824f, 0.658824f);;
#define cellBlockColor glColor3f(1,0,0);
#define textColor glColor3f(1, 1, 0);
#define defaultColor glColor3f(0.329412f, 0.329412f, 0.329412f);
int edge = 10; //設定格數為edge*edge
int bombnumber = 10;
GLfloat cell = 300 / edge;
int numPosition = cell / 2;
GLsizei wh = 500, ww = 500;
minesweeper n(edge, bombnumber); //第一個為格子，第二個為炸彈數

void reset(int new_edge, int new_bombnumber)
{
	edge = new_edge;
	bombnumber = new_bombnumber;
	cell = 300 / edge;
	numPosition = cell / 2;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glFlush();

	n.reset(edge, bombnumber);

	glutPostRedisplay();
}

void drawLine()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(2);
	glBegin(GL_LINES);
	for (float i = 100; i <= 400; i += cell)
	{
		glVertex2f(i, 100);
		glVertex2f(i, 400);
		glVertex2f(100, i);
		glVertex2f(400, i);
	}
	glEnd();
	glFlush();
}



void drawCell(int x1, int y1) {
	float size = cell;

	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x1, y1 + size);
	glVertex2f(x1 + size, y1 + size);
	glVertex2f(x1 + size, y1);
	glEnd();
	glFlush();
}

void numFont(int n) {
	switch (n) {
	case -1:
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '*');
		break;
	case 0:
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '0');
		break;
	case 1:
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '1');
		break;
	case 2:
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '2');
		break;
	case 3:
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '3');
		break;
	case 4:
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '4');
		break;
	case 5:
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '5');
		break;
	case 6:
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '6');
		break;
	case 7:
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '7');
		break;
	case 8:
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '8');
		break;
	default:
		break;
	}
	glFlush();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.8f, 0.8f, 0.8f);
	glBegin(GL_POLYGON);
	glVertex2f(100, 400);
	glVertex2f(100, 450);
	glVertex2f(400, 450);
	glVertex2f(400, 400);
	glEnd();
	glLineWidth(3);
	glColor3f(0.8f, 0.8f, 0.8f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(100, 400);
	glVertex2f(100, 450);
	glVertex2f(400, 450);
	glVertex2f(400, 400);
	glEnd();
	glColor3f(0.329412f, 0.329412f, 0.329412f);
	glBegin(GL_POLYGON);
	glVertex2f(100, 100);
	glVertex2f(400, 100);
	glVertex2f(400, 400);
	glVertex2f(100, 400);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(2);
	glBegin(GL_LINES);

	for (float i = 100; i <= 400; i += cell)
	{
		glVertex2f(i, 100);
		glVertex2f(i, 400);
		glVertex2f(100, i);
		glVertex2f(400, i);
	}
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(230, 410);
	glVertex2f(230, 440);
	glVertex2f(270, 440);
	glVertex2f(270, 410);
	glEnd();
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(240, 418);
	glVertex2f(240, 432);
	glVertex2f(260, 432);
	glVertex2f(260, 418);
	glEnd();

	glFlush();
}

void stamp(float x1, float y1, int state) //滑鼠控制踩格子
{
	int indexX = (x1 - 100) / cell, indexY = (edge - 1) - (y1 - 100) / cell;

	if (state == 0 && !(n.isBlock(indexY, indexX)) && !(n.isPress(indexY, indexX))) {
		if (n.getBomb(indexY, indexX) == 0) {
			if (n.getBombAround(indexY, indexX) == 0) {
				vector<position> v = n.extend(indexY, indexX);
				
				for (int i = 0; i < v.size(); i++) {
					smallCellColor;
					drawCell(v[i].getCol() * cell + 100, ((edge - 1) - v[i].getRow()) * cell + 100);
					if (n.getBombAround(v[i].getRow(), v[i].getCol()) != 0) {
						textColor;
						glRasterPos2f(v[i].getCol() * cell + 100 + numPosition, ((edge - 1) - v[i].getRow()) * cell + 100 + numPosition);
						numFont(n.getBombAround(v[i].getRow(), v[i].getCol()));
					}
					n.setPress(v[i].getRow(), v[i].getCol(), 1);
				}
			}
			else {
				smallCellColor;
				drawCell(x1, y1);
				n.setPress(indexY, indexX, 1);
				textColor;
				glRasterPos2f(x1 + numPosition, y1 + numPosition);
				numFont(n.getBombAround(indexY, indexX));
			}
			drawLine();
		}
		else {
			//踩到地雷
			glColor3f(1.0f, 0.0f, 0.0f);
			float x = 200, y = 50;
			char A[10] = { 'G','A','M','E',' ','O','V','E','R','!' };
			glRasterPos2f(x, y);
			int len = (int)strlen(A);
			for (int i = 0; i < len; i++)
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, A[i]);
			}

			glFlush();
			for (int i = 0; i < edge; i++) {
				for (int j = 0; j < edge; j++) {
					if (n.getBomb(i, j) == 1) {
						cellBlockColor;
						drawCell(j * cell + 100, ((edge - 1) - i) * cell + 100);
						textColor;
						glRasterPos2f(j * cell + 100 + numPosition, ((edge - 1) - i) * cell + 100 + numPosition);
						numFont(n.getBombAround(i, j));
						drawLine();
					}
				}
			}
			n.setAllCellPress();
		}
	}
	else if (state == 1 && !(n.isPress(indexY, indexX))) {
		if ((n.isBlock(indexY, indexX))) {
			//右鍵解除鎖定
			defaultColor;
			n.setBlock(indexY, indexX, 0);
		}
		else {
			//設定鎖定
			cellBlockColor;
			n.setBlock(indexY, indexX, 1);
		}
		drawCell(x1, y1);
		drawLine();
	}
	glFlush();

	if (n.isEnd()) {
		//判斷是否結束
		glColor3f(1.0f, 0.0f, 0.0f);
		float x = 200, y = 50;
		char B[10] = { 'Y','O','U',' ','W','I','N','!' };
		glRasterPos2f(x, y);
		int len = (int)strlen(B);
		for (int i = 0; i < len; i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, B[i]);
		}

		glFlush();
		//成功
		n.setAllCellPress();
	}
}

void menu(int id)
{
	switch (id)
	{
	case 1:
		edge = 5;
		reset(edge, 5);
		break;
	case 2:
		edge = 10;
		reset(edge, 15);
		break;
	case 3:
		edge = 15;
		reset(edge, 25);
		break;

	case 4:
		exit(0);
		break;
	}
}

void init()
{

	glViewport(0, 0, ww, wh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)wh);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0, 0.0, 0.0, 1.0);

}

void changeSquare(float x, float y, int state) //判斷滑鼠踩的範圍
{
	y = wh - y;
	float x1, y1;
	for (int i = 0; i < edge; i++)
	{
		if (x < 100 || x>400) break;
		if (x < 100 + cell * (i + 1))
		{
			x1 = 100 + cell * i;
			break;
		}
	}
	for (int i = 0; i < edge; i++)
	{
		if (y < 100 || y>400) break;
		if (y < 100 + cell * (i + 1))
		{
			y1 = 100 + cell * i;
			break;
		}
	}
	if (x > 100 && x < 400 && y>100 && y < 400 && (state == 0 || state == 1)) {
		stamp(x1, y1, state);
	}
	if (x > 220 && x < 280 && y>410 && y < 440 && (state == 0 || state == 1))
	{
		//restart
		reset(edge, bombnumber);
	}

}

void mymouse(int button, int state, int x, int y)
{
	//0:左鍵 1:右鍵
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) changeSquare(x, y, 0);
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) changeSquare(x, y, 1);
}

int main(int argc, char* argv[])
{
	n.show();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww, wh);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("踩地雷");

	glutMouseFunc(mymouse);
	init();
	glutDisplayFunc(Display);

	//選單
	glutCreateMenu(menu);
	glutAddMenuEntry("簡單", 1);
	glutAddMenuEntry("正常", 2);
	glutAddMenuEntry("困難", 3);
	glutAddMenuEntry("離開遊戲", 4);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutMainLoop();
	return 0;
}
