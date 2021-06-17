#include"Checkerboard.h"

Checkerboard::Checkerboard(int range)
{
	Range = range;
	for (int i = 0; i < range; i++)
	{
		vector<Grid> checkerboard_s;
		for (int j = 0; j < range; j++)
		{
			checkerboard_s.push_back(label);
		}
		checkerboard.push_back(checkerboard_s);
	}
	this->countTotalBoom(range);
	int count = totalBoom;
	int x, y;
	srand(time(NULL));

	while (count > 0)
	{
		x = rand()%range;
		y = rand()%range;
		if(checkerboard[x][y].isBoom==false)
		{
			checkerboard[x][y].isBoom = true;
			count--;
		}
	}
	for (y = 0; y < range; y++)
	{
		for (x = 0; x < range; x++)
		{
			if (checkerboard[x][y].isBoom == false)
			{
				for (int y2 = y - 1; y2 <= y + 1; y2++)
				{
					for (int x2 = x - 1; x2 <= x + 1; x2++)
					{
						if (y2 >= 0 && x2 >= 0 && y2 < range && x2 < range)
						{
							if (checkerboard[x2][y2].isBoom == true)
							{
								checkerboard[x][y].boomNumber++;
							}
						}
					}
				}
			}
		}
	}
}
void Checkerboard::countTotalBoom(int x)
{
	totalBoom = x * x / 7;
}
void Checkerboard::print(bool check)
{
	cout << " ";
	for (int i = 1; i <= Range; i++)
	{
		if (i >= 10)
		{
			if (i == 10)cout << setw(6) << i;
			else cout << setw(5) << i;
		}
			
		else cout << setw(5) << i;
		
	}
	cout << endl;
	for (int y = 0; y < Range; y++)
	{
		if(y+1>=10)cout<< y + 1;
		else cout << "0" << y + 1;
		for (int x = 0; x < Range; x++)
		{
			if (checkerboard[x][y].isOpen == true||check==true)
			{
				if (checkerboard[x][y].isBoom == true)
				{
					cout<<setw(5) << "●" ;
				}
				else if(checkerboard[x][y].boomNumber==0)
				{
					cout<< setw(5) << "□";
				}
				else
				{
					cout<< setw(5) <<checkerboard[x][y].boomNumber ;
				}
			}
			else
			{
				cout<< setw(5) << "■" ;
			}
		}
		cout << endl;
	}
}
void Checkerboard::CheckboomNumber0(int x, int y)
{
	int y2 = y - 1;//檢查上
	int x2 = x;
	Recursion(x2, y2);

	y2 = y + 1;//檢查下
	x2 = x;
	Recursion(x2, y2);

	y2 = y;//檢查左
	x2 = x - 1;
	Recursion(x2, y2);

	y2 = y;//檢查右
	x2 = x + 1;
	Recursion(x2, y2);
}
void Checkerboard::Recursion(int x2, int y2)
{
	if (y2 >= 0 && x2 >= 0 && y2 < Range && x2 < Range)//檢查上
	{
		if (checkerboard[x2][y2].isBoom == false&&checkerboard[x2][y2].isOpen==false)
		{
			checkerboard[x2][y2].isOpen = true;
			openCount++;
			if (checkerboard[x2][y2].boomNumber == 0)
			{
				cout << x2 << " " << y2 << endl;
				CheckboomNumber0(x2, y2);
			}
		}
	}
}
bool Checkerboard::checkWin()
{
	for (int y = 0; y < Range; y++)
	{
		for (int x = 0; x < Range; x++)
		{
			if (checkerboard[x][y].isBoom == false&&checkerboard[x][y].isOpen==false)
			{
				return false;
			}
		}
	}
	return true;
}
