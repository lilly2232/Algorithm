#include <iostream>
#define MAX 102

using namespace std;
int arr[MAX][MAX] = { 0, };
int visit[MAX][MAX] = { 0, };
int t;
struct MyQueue{
	int x;
	int y;
	int total;
};
MyQueue queue[10000];
int front = 0;
int rear = 0;
int cnt = 0;

void bfs()
{
	while (front != rear)
	{
		MyQueue here = queue[front++];
		int x = here.x;
		int y = here.y;
		int total = here.total;

		if (total == t)
			cnt++;

		MyQueue next;

		if (arr[x - 1][y] == 0 && visit[x- 1][y] != 1){
			visit[x-1][y] = 1;
			next.x = x - 1;
			next.y = y;
			next.total = total + 1;
			queue[rear++] = next;
		}
		if (arr[x + 1][y] == 0 && visit[x + 1][y] != 1)
		{ 
			visit[x+1][y] = 1;
			next.x = x + 1;
			next.y = y;
			next.total = total + 1;
			queue[rear++] = next;
		}
		if (arr[x][y - 1] == 0 && visit[x][y - 1] != 1) {
			visit[x][y -1] = 1;
			next.x = x;
			next.y = y - 1;
			next.total = total + 1;
			queue[rear++] = next;
		}
		if (arr[x][y + 1] == 0 && visit[x][y + 1] != 1)
		{
			visit[x][y + 1] = 1;
			next.x = x;
			next.y = y + 1;
			next.total = total + 1;
			queue[rear++] = next;
		}
	}
}
void init(int n)
{
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
					arr[i][j] = 1;
}
int main()
{
	int n;
	int x, y;

	cin >> n;
	init(n);
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			cin >> arr[i][j];
	cin >> y >> x;
	MyQueue start_point;
	start_point.x = x;
	start_point.y = y;
	start_point.total = 0;

	visit[x][y] = 1;
	queue[rear++] = start_point;


	cin >> t;
	bfs();
	if (cnt == 0)
		cout << "OH, MY GOD" << endl;
	else
		cout << cnt << endl;
}