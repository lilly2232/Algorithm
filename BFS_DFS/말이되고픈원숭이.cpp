#include <iostream>
#include <queue>
#define MAX 201
using namespace std;
int arr[MAX][MAX];
int k,w,h;
struct mytype
{
	int x;
	int y;
	int k;
	int cnt;
};
int visit[MAX][MAX][31];
int dir[4][2] =
{	 0,1,
	0,-1,
	1,0,
	-1,0
};
int kdir[8][2] = 
{
	-2,1,
	-2,-1,
	-1,2,
	-1,-2,
	1,2,
	1,-2,
	2,-1,
	2,1
};
int bfs()
{
	queue<mytype> q;
	// (1,1,k) start
	q.push(mytype{ 1,1,k,0 });
	while (!q.empty())
	{
		
		mytype p = q.front();

		if (p.x == h && p.y == w)
			return p.cnt;

		for (int i = 0; i < 4; i++)
		{
			int next_x = dir[i][0] + p.x;
			int next_y = dir[i][1] + p.y;
			int cnt = p.cnt;
			int next_k = p.k;
			if (next_x > 0 && next_x <= h && next_y > 0 && next_y <= w && 
				arr[next_x][next_y] == 0 && visit[next_x][next_y][next_k] == 0)
			{
				visit[next_x][next_y][next_k] = 1;
				q.push(mytype{ next_x,next_y, next_k, cnt + 1 });

			}
		}
		if (p.k > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int next_x = kdir[i][0] + p.x;
				int next_y = kdir[i][1] + p.y;
				int cnt = p.cnt;
				int next_k = p.k-1;
				if (next_x > 0 && next_x <= h && next_y > 0 && next_y <= w &&
					arr[next_x][next_y] == 0 && visit[next_x][next_y][next_k] == 0)
				{
					visit[next_x][next_y][next_k] = 1;
					q.push(mytype{ next_x,next_y, next_k,cnt + 1, });

				}
			}
		}
		q.pop();
	}
	return -1;
}
int main()
{
	cin >> k;
	cin >> w >> h;

	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> arr[i][j];
	cout << bfs() << endl;
}