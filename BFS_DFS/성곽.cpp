#include <iostream>
#define MAX 52
#define INF 987654321
using namespace std;
int n, m;
int arr[MAX][MAX];
int visit[MAX][MAX];
int max_value = -INF;
void dfs(int x, int y, int cnt)
{
	int v = arr[x][y];

	int bin[4] = { 0,0,0,0 };
	int idx = 0;
	while (v != 0)
	{
		bin[idx++] = v % 2 ;
		v = v/2;
	}
	visit[x][y] = 1;
	max_value++;

	if (bin[0] == 0 && y - 1 > 0 && visit[x][y-1] == 0)
		dfs(x, y-1, cnt + 1);
	if (bin[1] == 0 && x - 1 > 0 && visit[x-1][y] == 0)
		dfs(x-1, y, cnt + 1);
	if (bin[2] == 0 && y + 1 <= n && visit[x][y+1] == 0)
		dfs(x, y+1, cnt + 1);
	if (bin[3] == 0 && x + 1 <= m && visit[x+1][y] == 0)
		dfs(x+1, y, cnt + 1);

}
void initv()
{
	max_value = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			visit[i][j] = 0;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	int count = 0;
	int max = -INF;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n;j++)
			if (visit[i][j] != 1)
			{
				max_value = 0;
				dfs(i, j, 0);		
				count++;
				if (max < max_value)
					max = max_value;

			}
	cout << count << endl;
	cout << max << endl;
	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
		
			int temp = arr[i][j];
			if (arr[i][j] - 8 > 0) {
				arr[i][j] = temp - 8;
				initv();
				dfs(i, j, 0);
				if (max < max_value)
					max = max_value;
				
			}
			if (arr[i][j] - 4 > 0)
			{
				arr[i][j] = temp - 4;
				initv();
				dfs(i, j, 0);
				if (max < max_value)
					max = max_value;
			}
			if (arr[i][j] - 2 > 0)
			{
				arr[i][j] = temp - 2;
				initv();
				dfs(i, j, 0);
				if (max < max_value)
					max = max_value;
			}
			if (arr[i][j] - 1 > 0)
			{
				arr[i][j] = temp - 1;
				initv();
				dfs(i, j, 0);
				if (max < max_value)
					max = max_value;
			}
			arr[i][j] = temp;
		}
			cout << max << endl;
}