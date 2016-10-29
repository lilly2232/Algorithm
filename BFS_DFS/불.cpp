#include <iostream>
#define max(a,b) a>b?a:b
#include <queue>

#define MAX 1002
using namespace std;
int w, h;	// �ʺ� , ����
char arr[MAX][MAX];
int visit[MAX][MAX];
struct pos
{
	int fire ; int x; int y; int cnt;		// 1-> ��� , 2 -> ��
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
		int who = q.front().fire;	// ó������ �� 
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

				if (arr[next_x][next_y] == '.' && visit[next_x][next_y] < who)	// ����� �����浵 ���Ǳ� 
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
						pos p = { 2, i, j, 0 };	// ���� ť�� ���� �ִ´�.
						visit[i][j] = 2;
						q.push(p);
					}
				}
		}
		pos p = { 1, start_x, start_y, 0 };
		visit[start_x][start_y] = 1;		// �������� ��� �ֱ� 
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