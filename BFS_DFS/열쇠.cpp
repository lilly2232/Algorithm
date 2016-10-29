#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
#define MAX 101
int h, w;
char arr[MAX][MAX];
int visit[MAX][MAX];
int key[26];
char str[MAX];
bool flag = false;
int keycnt = 0; 
int dir[4][2] =
{
	0,-1,
	0,1,
	1,0,
	-1,0
};

void init()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			visit[i][j] = 0;
	keycnt = 0;
}
void make_key()
{
	for (int i = 0; i < 26; i++)
		key[i] = 0;
	if (str[0] == 0)
		return;
	for (int i = 0; str[i] != '\0'; i++) 
	{
		int x = str[i] - 97;
		key[x] = 1;
	}
}
void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int next_x = dir[i][0] + x;
		int next_y = dir[i][1] + y;
		if (next_x >= 0 && next_x < h && next_y >= 0 && next_y < w && arr[next_x][next_y] != '*' && visit[next_x][next_y] == 0)
		{
	
			int val = arr[next_x][next_y];
			if (val >= 97 && val <= 122) {
				if (key[val - 97] == 0) {
					key[val - 97] = 1;
					flag = true;
					visit[next_x][next_y] = 1;
					dfs(next_x, next_y);
				}
				else  if (key[val - 97] == 1)
				{
					visit[next_x][next_y] = 1;
					dfs(next_x, next_y);
				}
			}
			if (val >= 65 && val <= 90) {
				if (key[val - 65] == 1) {
					visit[next_x][next_y] = 1;
					dfs(next_x, next_y);
				}
			}

			if (val == 36) {	// ¹®¼­ È¹µæ
				keycnt++;
				visit[next_x][next_y] = 1;
				dfs(next_x, next_y);
			}
			if (val == 46) {
				visit[next_x][next_y] = 1;
				dfs(next_x, next_y);
			}
		}
	}
}
int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		cin >> h >> w;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> arr[i][j];

		cin >> str;

		int maxkey = -INF;
		vector<pair<int, int> > startarr;

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				if ((i == 0 || i == h - 1 || j == 0 || j == w - 1) && arr[i][j] != '*') 
					startarr.push_back(make_pair(i, j));

		make_key();
		flag = true;

		while (flag == true) 
		{
			flag = false;
			init();
			for (int i = 0; i < startarr.size(); i++)
			{
				pair<int, int> here = startarr[i];
				int val = arr[here.first][here.second];
				if (visit[here.first][here.second] == 0) {	// ´Ù¸¥ ÁöÁ¡¿¡¼­ visitÇÑ °÷Àº ¾È°¡µµ·Ï
					if (val >= 97 && val <= 122)
					{
						if (key[val - 97] == 0) {
							key[val - 97] = 1;
							visit[here.first][here.second] = 1;
							dfs(here.first, here.second);
						}
						else  if (key[val - 97] == 1)
						{
							visit[here.first][here.second] = 1;
							dfs(here.first, here.second);
						}
					}

					if (val >= 65 && val <= 90) {
						if (key[val - 65] == 1)
						{
							visit[here.first][here.second] = 1;
							dfs(here.first, here.second);
						}
					}
					if (val == 36) {	// ¹®¼­ È¹µæ
						keycnt++;
						visit[here.first][here.second] = 1;
						dfs(here.first, here.second);
					}
					if (val == 46) {
						visit[here.first][here.second] = 1;
						dfs(here.first, here.second);
					}
					if (maxkey < keycnt)
						maxkey = keycnt;
				}
			}
		}
		if (maxkey == -INF)
			maxkey = 0;
		cout << maxkey << endl;
	}
}