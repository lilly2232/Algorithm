#include <iostream>
#include <queue>
#define MAX 55
using namespace std;
char arr[MAX][MAX];
int r, c;
int sx, sy;

int dir[4][2] =
{
	0,1,
	0,-1,
	1,0,
	-1,0
};
struct point
{
	int x;
	int y;
	int cnt;
	int flag; // 1: fire , 2: person 
};
int visit[MAX][MAX];
int bfs()	// x,y 실수 - 문제 잘읽기 
{
	queue<point> q;

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			visit[i][j] = 0;

	arr[sx][sy] = '.';

	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (arr[i][j] == '*') {
				q.push(point{ i,j,0,1 });
				visit[i][j] = 1;
			}
	q.push(point{ sx,sy,0,2 });
	visit[sx][sy] = 1;

	while (!q.empty())
	{
		point p = q.front();
		if (p.flag == 2 && arr[p.x][p.y] == 'D')
			return p.cnt;
	
		if (p.flag == 1) {
			for (int i = 0; i < 4; i++) {
				int next_x = dir[i][0] + p.x;
				int next_y = dir[i][1] + p.y;
				int cnt = p.cnt;
		
				if (next_x > 0 && next_y > 0 && next_x <= r && next_y <= c && arr[next_x][next_y] == '.' && visit[next_x][next_y] == 0 )
				{
					q.push(point{ next_x, next_y, cnt + 1, 1 });
					visit[next_x][next_y] = 1;
					arr[next_x][next_y] = '*';
				}
			}
		} else if (p.flag == 2) {
			for (int i = 0; i < 4; i++)
			{
				int next_x = dir[i][0] + p.x;
				int next_y = dir[i][1] + p.y;
				int cnt = p.cnt;

				if (next_x > 0 && next_y > 0 && next_x <= r && next_y <= c && visit[next_x][next_y] == 0)
				{
					if (arr[next_x][next_y] == '.' || arr[next_x][next_y] == 'D') {
						q.push(point{ next_x, next_y, cnt + 1, 2 });
						visit[next_x][next_y] = 1;
					}
				}
			}
		}
		q.pop();
	}
	return -1;
}
int main()
{
	cin >> r >> c;
	
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				sx = i; sy = j;
			}
		}
	int ret = bfs();
	if (ret != -1)
		cout << ret << endl;
	else
		cout << "KAKTUS" << endl;
}