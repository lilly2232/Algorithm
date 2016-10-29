#include <iostream>

#include <queue>
#define MAX 52
#define max(a,b)a>b?a:b
using namespace std;
char arr[MAX][MAX];
int visit[MAX][MAX];

int dir[4][2] =
{
	1,0,
	-1,0,
	0,1,
	0,-1
};
struct pos
{
	int x; int y; int cnt;
};
int bfs(int x, int y)
{
	queue<pos> q;
	pos p = { x,y,0 };
	visit[x][y] = 1;
	q.push(p);
	int here_cnt = 0;
	while (!q.empty())
	{
		int here_x = q.front().x;
		int here_y = q.front().y;
		here_cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = here_x + dir[i][0];
			int next_y = here_y + dir[i][1];
			int next_cnt = here_cnt + 1;
			if (arr[next_x][next_y] == 'L' && visit[next_x][next_y] == 0)
			{
				pos p = { next_x, next_y, next_cnt };
				visit[next_x][next_y] = 1;
				q.push(p);
			}
		}
	}
	return here_cnt;
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


	int ret = 0;
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= w; j++)
			if (arr[i][j] == 'L')
			{
				for (int i = 1; i <= l; i++)
					for (int j = 1; j <= w; j++)
						visit[i][j] = 0;
		//		cout << bfs(i, j) << endl;
				ret = max(ret, bfs(i,j));
			}
	cout << ret << endl;
}