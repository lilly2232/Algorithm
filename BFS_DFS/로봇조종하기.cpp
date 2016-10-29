#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001
#define INF 987654321
int n, m;
int arr[MAX][MAX];
int visit[MAX][MAX];
int cache[MAX][MAX][3];
int dir[3][2] =
{
	0,-1,
	0,1,
	1,0,
	
};
int dfs(int x, int y, int k )
{

	if (x == n && y == m) {
		visit[x][y] = 0; 
		return arr[n][m];
	}
	int& ret = cache[x][y][k];
	if (ret != -INF) return ret;

	for (int i = 0; i < 3; i++) {
		int next_x = x + dir[i][0];
		int next_y = y + dir[i][1];
		if (next_x > 0 && next_y > 0 && next_x <= n && next_y <= m && visit[next_x][next_y] == 0) {
			visit[x][y] = 1;
			ret = max(ret, arr[x][y] + dfs(next_x, next_y, i));
			visit[x][y] = 0;
		}

	}
	
	return ret;
}
int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k < 3; k++)
			cache[i][j][k] = -INF;


	cout << dfs(1,1,0)<< endl;

}