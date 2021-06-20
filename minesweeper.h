#include <iostream>
#include <vector>
#include<cmath>
#include<ctime>
using namespace std;

class position {
public:
	position() {}
	position(int row, int col) {
		this->row = row;
		this->col = col;
	}
	int getRow() {
		return row;
	}
	int getCol() {
		return col;
	}
private:
	int row, col;
};
class minesweeper {
private:
	int edge = 0;
	int bombnumber = 0;
	int direct[8][2] = { { -1,-1 },{ 0,-1 },{ 1,-1 },{ -1,0 },{ 1,0 },{ -1,1 },{ 0,1 },{ 1,1 } }; //8個方向
	int** bomb; //炸彈
	int** bombAround; //每個cell周圍有多少炸彈
	int** cellPress; //cell是否按壓
	int** cellBlock; //cell是否按右鍵鎖住
public:
	minesweeper() {}

	minesweeper(int number, int bombnumber) {
		edge = number;
		this->bombnumber = bombnumber;
		setInit();
	}

	void setInit() {
		//動態宣告陣列
		bomb = new int* [edge];
		bombAround = new int* [edge];
		cellPress = new int* [edge];
		cellBlock = new int* [edge];

		for (int i = 0; i < edge; i++) {
			bomb[i] = new int[edge];
			bombAround[i] = new int[edge];
			cellPress[i] = new int[edge];
			cellBlock[i] = new int[edge];
		}

		//陣列初始化
		for (int i = 0; i < edge; i++) {
			fill(&bomb[i][0], &bomb[i][0] + edge, 0);
			fill(&bombAround[i][0], &bombAround[i][0] + edge, 0);
			fill(&cellBlock[i][0], &cellBlock[i][0] + edge, 0);
			fill(&cellPress[i][0], &cellPress[i][0] + edge, 0);
		}

		//炸彈產生
		srand((unsigned)time(0));
		for (int i = 0; i < bombnumber;) {
			int row = rand() % edge, col = rand() % edge;
			if (bomb[row][col] == 0) {
				bomb[row][col] = 1;
				i++;
			}
		}

		//每個格子周圍炸彈數
		for (int i = 0; i < edge; i++) {
			for (int j = 0; j < edge; j++) {
				if (bomb[i][j] == 0) {
					for (int k = 0; k < 8; k++) {
						int row = i + direct[k][0], col = j + direct[k][1];
						if ((row >= 0 && row < edge) && (col >= 0 && col < edge) && bomb[row][col] == 1)
							bombAround[i][j]++;
					}
				}
				else {
					bombAround[i][j] = -1;
				}
			}
		}
	}

	vector<position> extend(int row, int col) {
		vector<position> v;

		position p(row, col);
		v.push_back(p);
		for (int i = 0; i < v.size(); i++) {
			if (bombAround[v[i].getRow()][v[i].getCol()] == 0) {
				for (int j = 0; j < 8; j++) {
					int tempRow = v[i].getRow() + direct[j][0], tempCol = v[i].getCol() + direct[j][1];
					if ((tempRow >= 0 && tempRow < edge) && (tempCol >= 0 && tempCol < edge)) {
						bool flag = false;
						for (int k = 0; k < v.size(); k++) {
							if (v[k].getRow() == tempRow && v[k].getCol() == tempCol) {
								flag = true;
								break;
							}
						}
						if (!flag) {
							position p2(tempRow, tempCol);
							v.push_back(p2);
						}
					}
				}
			}
		}
		return v;
	}

	void setBlock(int row, int col, int n) {
		cellBlock[row][col] = n;
	}

	bool isBlock(int row, int col) {
		if (cellBlock[row][col] == 1) return true;
		else return false;
	}

	void setAllCellPress() {
		for (int i = 0; i < edge; i++) {
			fill(&cellPress[i][0], &cellPress[i][0] + edge, 1);
		}
	}

	void setPress(int row, int col, int n) {
		cellPress[row][col] = n;
	}

	bool isPress(int row, int col) {
		if (cellPress[row][col] == 1) return true;
		else return false;
	}

	int getBomb(int row, int col) {
		return bomb[row][col];
	}

	int getBombAround(int row, int col) {
		return bombAround[row][col];
	}

	void reset(int edge, int bombnumber) {
		for (int i = 0; i < this->edge; i++) {
			delete[]bomb[i];
			delete[]bombAround[i];
			delete[]cellPress[i];
			delete[]cellBlock[i];
		}
		delete[]bomb;
		delete[]bombAround;
		delete[]cellPress;
		delete[]cellBlock;

		this->edge = edge;
		this->bombnumber = bombnumber;
		setInit();
	}

	bool isEnd() {
		int count = 0;
		for (int i = 0; i < edge; i++) {
			for (int j = 0; j < edge; j++) {
				if (bomb[i][j] == 1 && cellBlock[i][j] == 1) {
					count++;
				}
			}
		}

		if (count == edge) return true;
		else return false;
	}

	void show() {
		cout << "edge" << edge << endl;
		for (int i = 0; i < edge; i++) {
			for (int j = 0; j < edge; j++) {
				cout << bomb[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < edge; i++) {
			for (int j = 0; j < edge; j++) {
				cout << bombAround[i][j] << " ";
			}
			cout << endl;
		}
	}

	~minesweeper() {
		for (int i = 0; i < edge; i++) {
			delete[]bomb[i];
			delete[]bombAround[i];
			delete[]cellPress[i];
			delete[]cellBlock[i];
		}
		delete[]bomb;
		delete[]bombAround;
		delete[]cellPress;
		delete[]cellBlock;
	}
};
