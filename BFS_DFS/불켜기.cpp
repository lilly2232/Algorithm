#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<pair<int, int> > arr[111][111];
int map[111][111];
int visit[111][111];
int lightmap[111][111];
int dir[4][2] =
{
	0,1,
	0,-1,
	1,0,
	-1,0
};
bool flag = true;
void light(int x, int y)
{
	for (int i = 0; i < arr[x][y].size(); i++) 
		map[arr[x][y][i].first][arr[x][y][i].second] = 1;
		
	flag = true;
}
void dfs(int x, int y)	// Å½»öÇÏ±â 
{
	
 	for (int i = 0;  i < 4; i++)
	{
		int next_x = x + dir[i][0];
		int next_y = y + dir[i][1];

		if (next_x > 0 && next_y > 0 && next_x <= n && next_y <= n && map[next_x][next_y] == 1)
		{
			if(lightmap[next_x][next_y] == 0)
			{
				lightmap[next_x][next_y] = 1;
				if (arr[next_x][next_y].size() > 0) 
					light(next_x, next_y);
				dfs(next_x, next_y);
			}
			else if (visit[next_x][next_y] == 0) {
				visit[next_x][next_y] = 1;
				dfs(next_x, next_y);
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		arr[x1][y1].push_back(make_pair(x2, y2));
	}

	map[1][1] = 1;
	light(1, 1);
	lightmap[1][1] = 1;
	while (1) {
		if (flag == true) {
			flag = false;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					visit[i][j] = 0;
			dfs(1, 1);
		} else
			break;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j] == 1)
				cnt++;
	cout << cnt << endl;
}