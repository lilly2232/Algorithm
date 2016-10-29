#include <iostream>
#define INF 987654321
using namespace std;
int n;
char arr[52][52];
int visit[52][52][5];
pair<int, int> sp;
pair<int, int> ep;
int minmir = INF;
void dfs(int x, int y, int dir, int cnt)//x, y, dir, cnt, dir: ╩С(1) го(2) аб(3) ©Л(4)
{
	visit[x][y][dir] = cnt;
	if (x == ep.first && y == ep.second)
	{
		if (minmir > cnt)
			minmir = cnt;
		return;
	}
	if (dir == 1){
		if (x - 1 >= 0 && !(arr[x - 1][y] =='*') && (visit[x - 1][y][1] == 0 || visit[x - 1][y][1] > cnt))
			dfs(x - 1, y, 1, cnt);
		if (x - 1 >= 0 && arr[x - 1][y] == '!')
		{
			if (visit[x - 1][y][3] == 0 || visit[x - 1][y][3] > cnt+1)
				dfs(x - 1, y, 3, cnt + 1);
			if (visit[x - 1][y][4] == 0 || visit[x - 1][y][4] > cnt+1)
				dfs(x - 1, y, 4, cnt + 1);
		}
	}
	else if (dir == 2) {
		if (x + 1 < n && !(arr[x + 1][y] == '*') && (visit[x + 1][y][2] == 0 || visit[x + 1][y][2] > cnt))
			dfs(x + 1, y, 2, cnt);
		if (x + 1 < n && arr[x + 1][y] == '!')
		{
			if (visit[x + 1][y][3] == 0 || visit[x + 1][y][3] > cnt+1)
				dfs(x + 1, y, 3, cnt + 1);
			if (visit[x + 1][y][4] == 0 || visit[x + 1][y][4] > cnt+1)
				dfs(x + 1, y, 4, cnt + 1);
		}
	}
	else if (dir == 3) {
		if (y - 1 >= 0 && !(arr[x][y - 1] == '*') && (visit[x][y - 1][3] == 0|| visit[x][y - 1][3] > cnt))
			dfs(x, y - 1, 3, cnt);
		if (y - 1 >= 0 && arr[x][y - 1] == '!')
		{
			if (visit[x][y - 1][1] == 0 || visit[x][y - 1][1] > cnt+1)
				dfs(x, y - 1, 1, cnt + 1);
			if (visit[x][y - 1][2] == 0 || visit[x][y - 1][2] > cnt+1)
				dfs(x, y - 1, 2, cnt + 1);
		}
	}
	else if (dir == 4) {
		if (y + 1 < n && !(arr[x][y + 1] == '*') && (visit[x][y + 1][4] == 0 || visit[x][y + 1][4] > cnt))
			dfs(x, y + 1, 4, cnt);
		if (y + 1 < n && arr[x][y + 1] == '!')
		{
			if (visit[x][y + 1][1] == 0 || visit[x][y + 1][1] > cnt)
				dfs(x, y + 1, 1, cnt + 1);
			if (visit[x][y + 1][2] == 0 || visit[x][y + 1][2] > cnt)
				dfs(x, y + 1, 2, cnt + 1);
		}
	}
}
int main()
{
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		char str[51];
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == '#') {
				if (cnt == 0) 
				{
					sp = make_pair(i, j);
					cnt++;
				}
				else if (cnt > 0) {
					ep = make_pair(i, j);
				}
			}
		}

	}

	dfs(sp.first, sp.second, 1, 0);
	dfs(sp.first, sp.second, 2, 0);
	dfs(sp.first, sp.second, 3, 0);
	dfs(sp.first, sp.second, 4, 0);

	if (minmir == INF)
		minmir = 0;
	cout << minmir << endl;
}