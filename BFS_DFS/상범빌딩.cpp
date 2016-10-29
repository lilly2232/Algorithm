#include <iostream>
#include <queue>
#define MAX 31
using namespace std;
char arr[MAX][MAX][MAX];
int L, R, C;
struct mytype
{
	int f;
	int x;
	int y;
	int cnt;
};
queue<mytype> q;
int visit[MAX][MAX][MAX];
void init()
{
	for (int i = 0; i < L; i++)
		for (int j = 0; j < R; j++)
			for (int k = 0; k < C; k++)
				visit[i][j][k] = 0;
}
int dir[6][3] =
{
	0,0,1,
	0,0,-1,
	0,-1,0,
	0,1,0,
	1,0,0,
	-1,0,0,
};
int bfs(int floor, int x, int y)
{
	visit[floor][x][y] = 1;
	q.push(mytype{ floor,x,y,0 });

	while (!q.empty())
	{
		mytype p = q.front();

		if (arr[p.f][p.x][p.y] == 'E')
			return p.cnt;
		for (int i = 0; i < 6; i++)
		{
			int floor = dir[i][0] + p.f;
			int next_x = dir[i][1] + p.x;
			int next_y = dir[i][2] + p.y;
			int cnt = p.cnt;

			if (floor >= 0 && next_x >= 0 && next_y >= 0 && floor < L && next_x < R && next_y < C&& 
				visit[floor][next_x][next_y] == 0 && arr[floor][next_x][next_y] !='#')
			{
				visit[floor][next_x][next_y] = 1;
				q.push(mytype{ floor ,next_x, next_y, cnt + 1 });
			}
		}
		q.pop();
	}
	return -1;
}
int main()
{
	int floor, startx, starty; 
	while (1) {

		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		init();
		for (int i = 0; i < L; i++) 
			for (int j = 0; j < R; j++)
				for (int k = 0; k < C; k++) {
					cin >> arr[i][j][k];
					if (arr[i][j][k] == 'S')
					{
						floor = i;
						startx = j;
						starty = k;
					}
				}
		while (!q.empty())
			q.pop();
		int ret =  bfs(floor, startx, starty);
		if (ret == -1)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " << ret << " minute(s)." << endl;

	}
	return 0;
}