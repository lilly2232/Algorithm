#include <iostream>
#define MAX 52
#define max(a,b)a>b?a:b
#define INF 98765432
using namespace std;
char arr[MAX][MAX];
int visit[MAX][MAX];
int max_v = 0;
int dir[4][2] =
{
	1,0,
	-1,0,
	0,1,
	0,-1
};
void dfs(int x, int y, int cnt)
{
	int next_x; int next_y;
	visit[x][y] = cnt;

	for (int i = 0; i < 4; i++)
	{
		next_x = x + dir[i][0];
		next_y = y + dir[i][1];
		if (arr[next_x][next_y] == 'L' && (visit[next_x][next_y] == INF || visit[next_x][next_y] > cnt+1))
			dfs(next_x, next_y,cnt+1);
	}
	return;
}
int main()
{
	int l, w;
	cin >> l >> w;
	for (int i = 0; i <= l + 1; i++)
		for (int j = 0; j <= w + 1; j++)
			if (i == 0 || j == 0 || i == l + 1 || j == w + 1)
				arr[i][j] = 'W';
			else
				cin >> arr[i][j];

	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= w; j++)
			visit[i][j] = INF;

	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= w; j++) 
		{
			if (arr[i][j] == 'L')
			{
				dfs(i, j, 0);
				for (int i = 1; i <= l; i++)
					for (int j = 1; j <= w; j++) 
					{
						if (visit[i][j] != INF && visit[i][j] > max_v)
							max_v = visit[i][j];
						visit[i][j] = INF;
					}
			}
		}
	cout << max_v << endl;
}