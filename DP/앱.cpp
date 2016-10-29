#include <iostream>
#include <algorithm>
#define MAX 101
#define max(a,b)a>b?a:b
#define INF 987654321
using namespace std;
int n, m;
int mem[MAX];
int cost[MAX];
int cache[MAX][MAX*MAX];
int sol(int pos, int rest)	// 최소비용 , i 번째 배터리
{
	if (rest == 0) return 0;
	if (pos > n || rest < 0) return -INF;

	int& ret = cache[pos][rest];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, sol(pos + 1, rest));
	ret = max(ret, mem[pos] + sol(pos + 1, rest - cost[pos]));
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX*MAX; j++)
			cache[i][j] = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> mem[i];
	for (int i = 1; i <= n; i++)
		cin >> cost[i];
	int i;
	for (i = 0; i < 10001; i++)
	{
		int ret = sol(1, i);
		if (ret >= m)
			break;
	}
	cout << i << endl;
}