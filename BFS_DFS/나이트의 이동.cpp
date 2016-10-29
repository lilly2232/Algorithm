#include <iostream>
#include <queue>
using namespace std;
#define MAX 301
int dir[8][2] =
{
	2,1,
	2,-1,
	1,2,
	1,-2,
	-2,1,
	-2,-1,
	-1,2,
	-1,-2
};
int arr[MAX][MAX];
int end_x, end_y;
int num;
struct point
{
	int x;
	int y;
	int cnt;
};
int bfs(int x, int y)
{
	int visit[MAX][MAX];
	for (int i = 0; i <= num; i++)
		for (int j = 0; j <= num; j++)
			visit[i][j] = 0;
	visit[x][y] = 1;
	queue<point> q;
	q.push(point{ x, y, 0 });

	while (!q.empty())
	{
		if (q.front().x == end_x && q.front().y == end_y)
			return q.front().cnt;
		for (int i = 0; i < 8; i++)
		{
			int next_x = dir[i][0] + q.front().x;
			int next_y = dir[i][1] + q.front().y;
			int cnt = q.front().cnt;

			if (next_x >= 0 && next_y >= 0 && next_x < num && next_y < num && visit[next_x][next_y] == 0) {
				q.push(point{ next_x, next_y, cnt + 1 });
				visit[next_x][next_y] = 1;
			}
		}
		q.pop();
	}
	return 0;
}
int main()
{
	int testcase;

	cin >> testcase;
	while (testcase--) {
		cin >> num;
		int s, e;
		cin >> s >> e;
		cin >> end_x >> end_y;
		cout << bfs(s, e) << endl;
	}
}