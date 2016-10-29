#include <iostream>
#define MAX 101		// 1~100
using namespace std;
int people[MAX][MAX];
int visit[MAX];
int final_cnt = -1;
int num;

void dfs(int x, int y, int cnt)
{
	visit[x] = 1;
	if (x == y) {
		final_cnt = cnt;
		return;
	}
	for (int i = 1; i <= num; i++)
	{
		if (people[x][i] == 1 && visit[i] == 0)
			dfs(i, y, cnt + 1);
	}
}
int main()
{
	cin >> num;
	
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++) {
			people[i][j] = 0;
		}
	for (int i = 1; i <= num; i++)
		visit[i] = 0;

	int x, y;
	cin >> x >> y;
	int k;
	cin >> k;
	while (k--)
	{
		int a, b;
		cin >> a >> b;
		people[a][b] = 1;
		people[b][a] = 1;
	}
	dfs(x, y, 0);
	cout << final_cnt << endl;
}