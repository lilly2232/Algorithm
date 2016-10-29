#include <iostream>
using namespace std;
char arr[5][5];
int visit[25];
int v[5][5];
int checkarr[5][5];
int total;
int leecnt;
int dir[4][2] =
{
	-1,0,
	1,0,
	0,-1,
	0,1
};
void dfs(int x, int y)
{
	total++;
	if (arr[x][y] == 'S')
		leecnt++;
	for (int i = 0; i < 4; i++)
	{
		int next_x = dir[i][0] + x;
		int next_y = dir[i][1] + y;
		if (next_x >= 0 && next_y >= 0 && next_x < 5 && next_y < 5 && v[next_x][next_y] == 1 && checkarr[next_x][next_y] == 0)
		{
			checkarr[next_x][next_y] = 1;
			dfs(next_x, next_y);
		}
	}
}
int check()
{
	int cnt = 0; 
	int x, y;
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++)
				v[i][j]  = 0;

	for (int i = 0; i < 25; i++)
		if (visit[i] == 1)
		{
			x = i / 5;
			y = i % 5;
			v[x][y] = 1;
			cnt++;
		}

	if (cnt == 7) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
					checkarr[i][j] = 0;
		total = 0; 
		leecnt = 0; 
		checkarr[x][y] = 1;
		dfs(x, y);
	
		if (total == 7 && leecnt >= 4)
			return 1;
	}
		return 0;
}

int main()
{
	char str[6];
	for (int i = 0; i < 5; i++)
	{
		cin >> str;
		for (int j = 0; j < 5; j++)
			arr[i][j] = str[j];
	}
	int ret = 0; 
	for (int a = 0; a < 25; a++)
		for (int b = a+1; b < 25; b++)
			for (int c = b+1; c < 25; c++)
				for (int d = c+1; d < 25; d++)
					for (int e = d+1; e < 25; e++)
						for (int f = e+1; f < 25; f++)
							for (int g = f+1; g < 25; g++) {
								visit[a] = 1;
								visit[b] = 1;
								visit[c] = 1;
								visit[d] = 1;
								visit[e] = 1;
								visit[f] = 1;
								visit[g] = 1;
								//Å½»ö 
								// check
								ret += check();
								visit[a] = 0;
								visit[b] = 0;
								visit[c] = 0;
								visit[d] = 0;
								visit[e] = 0;
								visit[f] = 0;
								visit[g] = 0;
							}
	
		cout << ret << endl;
}