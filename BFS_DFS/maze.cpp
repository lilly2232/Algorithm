#include <iostream>
using namespace std;
#define MAX 22
#define INF 987654321
int arr[MAX][MAX];
int dir[4][2] = 
{
	1,0,
	-1,0,
	0,1,
	0,-1
};
int n, m;
int min_value = INF;
void dfs(int x, int y, int cnt)
{
	if (x == 1 && y == m)
	{
		if (cnt < min_value)
			min_value = cnt;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int next_x = dir[i][0] + x;
		int next_y = dir[i][1] + y;
		if (next_x > 0 && next_y > 0 && next_x <= n && next_y <= m && (arr[next_x][next_y] == 0|| arr[next_x][next_y] > cnt))
		{
			arr[next_x][next_y] = cnt;
			dfs(next_x, next_y, cnt + 1);
		}
	}
}
int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		char str[MAX];
		cin >> str;
		for (int j = 1; j <= m; j++)
			arr[i][j] = str[j-1]-48;
	}
	dfs(n, 1, 1);

	if (min_value == INF)
		cout << "-1" << endl;
	else
		cout << min_value << endl;
}