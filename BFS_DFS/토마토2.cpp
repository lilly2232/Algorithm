#include <iostream>
#include <queue>
#define MAX 102
using namespace std;
int arr[MAX][MAX][MAX];
int visit[MAX][MAX][MAX];
int m, n, h; // m : 가로 n: 세로 h: 높이 
struct tom
{
	int h; int x; int y; int cnt;
};
int dir[6][3] = {
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1,
};
queue<tom> q;
bool check()
{
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= m; k++)
				if (visit[i][j][k] == 0)
						return false;
	return true;
}
int bfs()
{
	int cnt;
	while (!q.empty())
	{
		tom t = q.front();
		for (int i = 0; i < 6; i++)
		{
			int next_h = t.h + dir[i][0];
			int next_x = t.x + dir[i][1];
			int next_y = t.y + dir[i][2];
			cnt = t.cnt;
	
			if (visit[next_h][next_x][next_y] == 0 && arr[next_h][next_x][next_y] == 0)
			{
				visit[next_h][next_x][next_y] = 1;
				tom x = { next_h,next_x,next_y,cnt+1 };
				q.push(x);

			}
		}
		q.pop();
	}
	return cnt;
}
int main()
{
	cin >> m >> n >> h;

	for (int i = 0; i <= h + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			for (int k = 0; k <= m + 1; k++)
				if (i == 0 || i == h + 1 || j == 0 || j == n + 1 || k == 0 || k == m + 1)
					arr[i][j][k] = 2;
				else {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == -1 || arr[i][j][k] == 1)
						visit[i][j][k] = 1;
				}

	if (check())
	{
		cout << "0" << endl;
	}
	else {
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= m; k++)
					if (arr[i][j][k] == 1)
					{
						tom t = { i,j,k,0 };
						q.push(t);
					}
		int ret = bfs();
		if (check())
			cout << ret << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}

