#include"Checkerboard.h"
#include <typeinfo>
bool isNumber(string&  str);

int enter(const string &str)
{
	string inStr;/*,strRange,strX,strY,strTemp;
	strRange = "請輸入遊玩方格數  輸入方式為range*range \nrange=";
	strX = "請輸入想要開啟的格子 輸入方式為第x列第y行 \nx=";
	strY = "請輸入想要開啟的格子 輸入方式為第x列第y行 \ny=";
	if (enterCount == 0)strTemp = strRange;
	else if (enterCount % 2 == 1)strTemp = strX;
	else if (enterCount % 2 == 0)strTemp = strY;*/
	do
	{
		//system("CLS");
		//C.print(false);
		cout << str;
		cin >> inStr;
	} while (isNumber(inStr) == false);
	return stoi(inStr);
}
bool isNumber(string& str)
{
	for (char c : str)
	{
		if (isdigit(c) == 0)return false;
	}
	return true;
}
int main()
{
	int enterCount = 0;
	bool error=true;
	int range=0;
	int x,y;

	do
	{
		range = enter("請輸入遊玩的矩形大小 \n建議大小3<range<16 \nrange=");
	} while (range < 4||range>15);
	

	Checkerboard C(range);
	system("CLS");
	enterCount++;

	while (true)
	{
		C.print(false);
		//cout << "請輸入想要開啟的格子 輸入方式為第x列第y行" << endl
			//<< "x=";
		//cin >> x;
		//cout << "y=";
		//cin >> y;
		
		x = enter("請輸入想要開啟的格子 輸入方式為第x列第y行 \nx="); x--;
		y = enter("請輸入想要開啟的格子 輸入方式為第x列第y行 \ny="); y--;

		if (x<0 || x>=range || y<0 || y>=range)
		{
			system("CLS");
			cout << "請輸入正確的範圍" << endl;
		}
		else
		{
			if (C.checkerboard[x][y].isBoom == true)
			{
				system("CLS");
				cout << "you lose" << endl; break;
			}
			else
			{
				if (C.checkerboard[x][y].isOpen == false)//檢查有沒有打開
				{
					C.checkerboard[x][y].isOpen = true;
					if (C.checkerboard[x][y].boomNumber == 0)
					{
						C.CheckboomNumber0(x, y);
					}
					system("CLS");
				}
				else
				{
					system("CLS");
					cout << "此格已經開啟了" << endl;
				}
				if (C.checkWin())
				{
					system("CLS");
					cout << "you win" << endl; break;
				}
			}
		}
	}
	C.print(true);

	
}
