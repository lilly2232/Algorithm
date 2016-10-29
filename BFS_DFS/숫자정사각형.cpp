#include <iostream>
#define MAX 52
#define min(a,b)a<b?a:b
using namespace std;
int n, m;
char arr[MAX][MAX];
int visit[MAX][MAX];
int max_v = 0; 
int dir[4][2] =
{
	1,0,
	-1,0,
	0,-1,
	0,1
};
void dfs(int x, int y, int k)
{
	char val = arr[x][y];
	visit[x][y] = 1;
	if (x + k < n && y + k < m && arr[x + k][y] == val && arr[x][y + k] == val && arr[x + k][y + k] == val) {
		max_v = (k+1)*(k+1);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int next_x = dir[i][0] + x;
		int next_y = dir[i][1] + y;

 		if (next_x >= 0 && next_x+k < n && next_y >= 0 && next_y+k < m && visit[next_x][next_y] == 0) {
			dfs(next_x, next_y, k);
		}
	}
}
int main()
{
	cin >> n >> m;
	int max_k = min(n, m);
	for (int i = 0; i < n; i++)
			cin >> arr[i];

	for (int k = max_k-1; k >= 0; k--)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				visit[i][j] = 0;
		if(max_v == 0)
			dfs(0, 0, k);
	}
	cout << max_v << endl;
}