#include <iostream>
#define MAX 301
using namespace std;
int arr[MAX][MAX];
int visit[MAX][MAX];
int copy_arr[MAX][MAX];
int cnt = 0;
int height, width;
int dir[4][2] =
{
	1,0,
	-1,0,
	0,1,
	0,-1
};
int acount(int x, int y)
{
	int total = 0;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dir[i][0];
		int next_y = y + dir[i][1];

		if (arr[next_x][next_y] == 0)
			total++;
	}
	return total;
}
void dfs(int x, int y)
{
	visit[x][y] = acount(x, y);
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dir[i][0];
		int next_y = y + dir[i][1];

		if (arr[next_x][next_y] > 0 && visit[next_x][next_y] == -1)
			dfs(next_x, next_y);
	}
	return;
}
void init()
{
	for (int i = 1; i <= width; i++)
		for (int j = 1; j <= height; j++)
			visit[i][j] = -1;
	cnt = 0; 
}
int main()
{
	int year = 0;
	int zero = 0; 
	int all = 0;

	cin >> width >> height;
	for (int i = 1; i <= width; i++)
		for (int j = 1; j <= height; j++)
			cin >> arr[i][j];

	while (1) {
		init();
		for (int i = 1; i <= width; i++)
			for (int j = 1; j <= height; j++)
				if (visit[i][j] == -1 && arr[i][j] > 0)
				{
					visit[i][j] = acount(i, j);
					dfs(i, j);
					cnt++;
					all++;
				}
		year++;
		if (cnt == 0)
		{
			year = 0; 
			break;
		}
		else if (cnt > 1) {
			year = year - 1;
			break;
		}

		for (int i = 1; i <= width; i++)
			for (int j = 1; j <= height; j++)
				if (visit[i][j] != -1 && arr[i][j] - visit[i][j] > 0)
					arr[i][j] = arr[i][j] - visit[i][j];
				else
					arr[i][j] = 0;
	
	}
	cout << year << endl;
}