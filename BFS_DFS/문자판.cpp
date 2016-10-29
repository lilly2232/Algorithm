#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
int n, m, k;
char arr[MAX][MAX];
char dst[MAX];
int len;
int cache[MAX][MAX][MAX];
struct mytype
{
	int x;
	int y;
	int pos;
};
int dir[4][2] =
{
	1,0,
	-1,0,
	0,1,
	0,-1
};
//queue<mytype> q;
//int bfs()
//{
//	int total = 0;
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= m; j++)
//			if (arr[i][j] == dst[0])
//				q.push(mytype{ i,j,1});
//	while (!q.empty())
//	{
//
//		mytype t = q.front();
//	
//		if (t.pos == len)
//			total++;
//
//		for (int i = 0; i < 4; i++)
//		{
//			int next_x = dir[i][0];
//			int next_y = dir[i][1];
//
//			for (int j = 1; j <= k; j++)
//			{
//				int x = t.x + next_x * j;
//				int y = t.y + next_y * j;
//				int pos = t.pos;
//
//				if (arr[x][y] == dst[pos] && pos < len && x > 0 && y > 0 && x <= n && y <= m)
//					q.push(mytype{ x,y,pos+1 });
//
//			}
//		}
//		q.pop();
//		
//	}
//	return total;
//}
int dfs(int x, int y, int pos)	// cache 배열 사이즈 잘 잡기 
{
	if (pos == len)
		return 1;

	int& ret = cache[x][y][pos];
	if (ret != -1)return ret;
	 ret = 0;

	for (int i = 0; i < 4; i++) {
		int next_x = dir[i][0];
		int next_y = dir[i][1];

		for (int j = 1; j <= k; j++)
		{
			int nx = x + next_x * j;
			int ny = y + next_y * j;

			if (arr[nx][ny] == dst[pos] && nx > 0 && ny > 0 && nx <= n && ny <= m)
				ret += dfs(nx, ny, pos + 1);
		}
	}
	return ret;
}
int main()
{
	cin >> n >> m >> k;
	char str[MAX];

	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		for (int j = 0; str[j] != '\0';j++)
			arr[i][j+1] = str[j];
	}

	cin >> dst;

	for (len = 0; dst[len]!= '\0'; len++) {}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= len; k++)
				cache[i][j][k] = -1;

	int cnt = 0; 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (arr[i][j] == dst[0])
				cnt += dfs(i, j, 1);

	cout << cnt << endl;
}