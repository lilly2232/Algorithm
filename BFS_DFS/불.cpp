#include <iostream>
#define max(a,b) a>b?a:b
#include <queue>

#define MAX 1002
using namespace std;
int w, h;	// 너비 , 높이
char arr[MAX][MAX];
int visit[MAX][MAX];
struct pos
{
	int fire ; int x; int y; int cnt;		// 1-> 사람 , 2 -> 불
};
queue<pos> q;
int start_x;
int start_y;

int dir[4][2] =
{
	1,0,
	-1,0,
	0,1,
	0,-1
};

int bfs()
{
	while (!q.empty())
	{
		int who = q.front().fire;	// 처음에는 불 
		int here_x = q.front().x;
		int here_y = q.front().y;
		int here_cnt = q.front().cnt;
		q.pop();
	
		for (int i = 0; i < 4; i++)
			{
				int next_x = here_x + dir[i][0];
				int next_y = here_y + dir[i][1];
				int next_cnt = here_cnt + 1;

				if (who == 1 && arr[next_x][next_y] == '$')
					return next_cnt;

				if (arr[next_x][next_y] == '.' && visit[next_x][next_y] < who)	// 사람이 갓던길도 지피기 
				{
					visit[next_x][next_y] = who;
					pos next = { who, next_x, next_y, next_cnt};
					q.push(next);
				}
			}
	}
	return -1;
}
int main()
{

	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		cin >> w >> h;
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++)
				if (i == 0 || i == h + 1 || j == 0 || j == w + 1)
					arr[i][j] = '$';
				else {

					cin >> arr[i][j];
					if (arr[i][j] == '@')
					{
						arr[i][j] = '.';
						start_x = i;
						start_y = j;
					}
					else if (arr[i][j] == '*')
					{
						pos p = { 2, i, j, 0 };	// 불을 큐에 먼저 넣는다.
						visit[i][j] = 2;
						q.push(p);
					}
				}
		}
		pos p = { 1, start_x, start_y, 0 };
		visit[start_x][start_y] = 1;		// 마지막에 사람 넣기 
		q.push(p);
		
		int ret = bfs();
		if (ret == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ret << endl;
		for (int i = 0; i <= h + 1; i++)
			for (int j = 0; j <= w + 1; j++)
				visit[i][j] = 0;
		/*while(!q.empty())
			q.pop();*/
		q = queue<pos>();
	}
	
}