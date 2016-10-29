#include <iostream>
#define MAX 102
using namespace std;
int n, m;
int arr[MAX][MAX];
int copyarr[MAX][MAX];
int visit[MAX][MAX];
int dir[4][2] =
{
	0,1,
	0,-1,
	1,0,
	-1,0
};
void dfs(int x, int y)
{
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int next_x = dir[i][0] + x;
		int next_y = dir[i][1] + y;
		if ( next_x >= 0 && next_y >= 0 && next_x <= n && next_y <= m && arr[next_x][next_y] != 1 && visit[next_x][next_y] == 0) {
			dfs(next_x, next_y);
			arr[next_x][next_y] = 2;
		}
			
	}

	return;
}
int acount(int x, int y)
{
	int cnt = 0; 
	for (int i = 0; i < 4; i++)
	{
		int next_x = dir[i][0] + x;
		int next_y = dir[i][1] + y;
		if (next_x >= 0 && next_y >= 0 && next_x <= n && next_y <= m && arr[next_x][next_y] == 2) {
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	int time = 0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	while (1) {
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				visit[i][j] = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				copyarr[i][j] = arr[i][j];

		dfs(0, 0);
		int chee = 0; 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				if (arr[i][j] == 1)
				{
					int ret = acount(i, j);
					if (ret >= 2)
						copyarr[i][j] = 2;
					chee++;
				}
		}

		if (chee == 0)
			break;
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++)
				arr[i][j] = copyarr[i][j];
		time++;
	}
	cout << time << endl;
}