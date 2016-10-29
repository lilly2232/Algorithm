#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int n, m, k;
int arr[MAX][MAX];
int visit[MAX][MAX];
int dir[4][2] =
{
	1,0,
	-1,0,
	0,1,
	0,-1
};
int sortarr[MAX] = { 0, };
int cnt = 0; 
void dfs(int x,int y)
{
	visit[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int next_x = dir[i][0] + x;
		int next_y = dir[i][1] + y;

		if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n && visit[next_x][next_y] == 0 && arr[next_x][next_y] == 0)
			dfs(next_x, next_y);
	}
}
int main()
{
	cin >> m >> n >> k;
	while (k--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++)
			arr[i][j] = 1;
		}
		
	}

	int total = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (visit[i][j] == 0 && arr[i][j] == 0)
			{
				cnt = 0; 
				dfs(i, j);
				sortarr[total] = cnt;
				total++;
			}

	cout << total << endl;
	sort(sortarr, sortarr + total);
	for (int i = 0; i < total; i++)
		cout << sortarr[i] << " ";
	cout << endl;
}
