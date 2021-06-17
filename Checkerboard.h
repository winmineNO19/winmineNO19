#ifndef Checkerboard_h
#define Checkerboard_h
#include<vector>
#include<ctime>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<iomanip>
#include<string>
#include"Grid.h"
using namespace std;


class Checkerboard
{
public:
	int Range=0;//計算棋盤幾*幾得變數
	int totalBoom;//總共炸彈數
	int openCount=0;
	vector<vector<Grid>> checkerboard;
	Grid label;
	

	Checkerboard(int x);
	void countTotalBoom(int x);
	void print(bool check);
	void CheckboomNumber0(int x, int y);
	void Recursion(int x2,int y2);
	bool checkWin();
};
#endif // !Checkerboard_h

