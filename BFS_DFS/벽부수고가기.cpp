// bfs ¿ÏÀü Å½»öÀÌ ¾ÈµÊ
#include <iostream>
#define SIZE 1000000
#define MAX 1002
using namespace std;
int arr[MAX][MAX];
int visit[MAX][MAX];
int n, m;

int Dir[4][2] = {
	0,1,
	0,-1,
	-1,0,
	1,0
};
struct MyQueue
{
	int x;
	int y;
	int cnt;
	bool b;
};
MyQueue queue[SIZE];
int sol(int x, int y)
{

	int front = 0; int rear = 0;
	visit[x][y] = 1;
	queue[rear].x = x;
	queue[rear].y = y;
	queue[rear].cnt = 1;
	queue[rear].b = 1;
	rear++;

	while (front != rear)
	{
		int here_x = queue[front].x;
		int here_y = queue[front].y;
		int h_cnt = queue[front].cnt;
		int h_flag = queue[front].b;
		front++;

		if (here_x == n && here_y == m)
		{
			return h_cnt;
		}
		for (int i = 0; i < 4; i++)
		{
			int next_x = here_x + Dir[i][0];
			int next_y = here_y + Dir[i][1];
			int cnt = h_cnt + 1;
			int b_flag = h_flag;


			if (visit[next_x][next_y]== 0) {
			
				if (arr[next_x][next_y] == 0 )
				{
					visit[next_x][next_y] = 1;
					queue[rear].x = next_x;
					queue[rear].y = next_y;
					queue[rear].cnt = cnt;
					queue[rear].b = b_flag;
					rear++;
				}
				if (arr[next_x][next_y] == 1) {
					visit[next_x][next_y] = 1;
					queue[rear].x = next_x;
					queue[rear].y = next_y;
					queue[rear].cnt = cnt;
					queue[rear].b = b_flag+1;
					cout << b_flag << endl;
					rear++;
				}
			}
		}
	}
	return -1;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
				arr[i][j] = 2;


	char str[MAX];
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++)
			arr[i][j + 1] = str[j] - 48;
	}
	cout << sol(1, 1) << endl;
	return 0;

}