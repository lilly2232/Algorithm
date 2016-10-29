#include <iostream>
#define MAX 10
using namespace std;
int arr[MAX][MAX];
int check();
bool flag = false;
bool rect(int x, int y, int k)
{
	for (int i = 1; i <= 9; i++)
		if (arr[i][y] == k)
			return false;

	for (int i = 1; i <= 9; i++)
		if (arr[x][i] == k)
			return false;

	int tx = 0, ty = 0;
	if (x >= 1 && x < 4) tx = 1;
	else if (x >= 4 && x < 7)tx = 4;
	else tx = 7;

	if (y >= 1 && y < 4) ty = 1;
	else if (y >= 4 && y < 7) ty = 4;
	else ty = 7;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (arr[tx + i][ty + j] == k)
				return false;
	return true;
}
void print()
{
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++)
			cout << arr[i][j];
		cout << endl;
	}
}
void sol(int col,int row)
{
	if (flag == true)
		return;
	
	if (col == 10)
	{
		print();
		flag = true;
		return;
	}
	if (row == 10)
	{
		sol(col+1, 1);
		return;
	}
	
	if (arr[col][row] == 0)
	{
		for (int i = 1; i < 10; i++) 
			if (rect(col, row, i)) {
				arr[col][row] = i;
				sol(col, row + 1);
				arr[col][row] = 0;
			}
	} else
		sol(col, row + 1);
}
int main()
{
	char str[MAX];
	for (int i = 1; i < 10; i++)
	{
		cin >> str;
		for (int j = 0; j < 9; j++) 
			arr[i][j + 1] = str[j] - 48;
	}
	sol(1,1);
}
