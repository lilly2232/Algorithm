#include <iostream>
#include <algorithm>
using namespace std;
char arr[6][10];
#define INF 987654321
int pincnt = INF;
int minpin = INF;
int dir[4][4] =
{
	0,1,0,2,
	0,-1,0,-2,
	1,0,2,0,
	-1,0,-2,0,
};
void dfs(int cnt)
{

	int pin = 0;
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 9; j++)
			if (arr[i][j] == 'o')
				pin++;

	if (pin < minpin) 
	{
		minpin = pin;
		pincnt = cnt;
		if (minpin ==  pin)
			if(pincnt > cnt)
				pincnt = cnt;
	}
	
	int ret = INF; 
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 9; j++)
		{
			if (arr[i][j] == 'o') {
				for (int k = 0; k < 4; k++)
				{
					int next_x = i + dir[k][0];
					int next_y = j + dir[k][1];
					int move_x = i + dir[k][2];
					int move_y = j + dir[k][3];

					if (next_x > 0 && next_x <= 5 && next_y > 0 && next_y <= 9 && arr[next_x][next_y] == 'o'&&
						move_x > 0 && move_x <= 5 && move_y > 0 && move_y <= 9 && arr[move_x][move_y] == '.')
					{
						arr[i][j] = '.';
						arr[next_x][next_y] = '.';
						arr[move_x][move_y] = 'o';
						dfs(cnt + 1);
						arr[move_x][move_y] = '.';
						arr[next_x][next_y] = 'o';
						arr[i][j] = 'o';
					}
				}
			}
		}
	return;
}
int main()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		char str[10];
		for (int i = 1; i <= 5; i++) 
		{	
			cin >> str;
			for (int j = 0; j < 9; j++)
				arr[i][j + 1] = str[j];
		}
		pincnt = INF;
		minpin = INF;
		
		dfs(0);
		cout << minpin << " " << pincnt << endl;
	}
	
}