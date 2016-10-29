#include <iostream>
#define MAX 101
using namespace std;
char arr[MAX][MAX];
int visit[MAX][MAX];
int n;
int dir[4][2] =
{
	-1,0,
	1,0,
	0,1,
	0,-1,
};
void dfs(int x, int y, char alpa)
{
	for (int i = 0; i < 4; i++)
	{
		int next_x = dir[i][0] + x;
		int next_y = dir[i][1] + y;

		if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < n && arr[next_x][next_y] == alpa && visit[next_x][next_y] == 0)
		{
			visit[next_x][next_y] = 1;
			dfs(next_x, next_y, alpa);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char str[MAX];
		cin >> str;
		for (int j = 0; j < n; j++)
			arr[i][j] = str[j];
	}
	int cnt = 0; 
	int difcnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (visit[i][j] == 0) {
				dfs(i, j, arr[i][j]);
				cnt++;
			}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (arr[i][j] =='R') 
				arr[i][j] = 'G';
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visit[i][j] = 0; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (visit[i][j] == 0) {
				dfs(i, j, arr[i][j]);
				difcnt++;
			}
	}
	cout << cnt <<" "<<difcnt<< endl;
}