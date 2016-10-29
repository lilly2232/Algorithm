#include <iostream>
using namespace std;
#define MAX 302
#define INF 9876534321
int n, m;
int arr[MAX][MAX];
int cache[MAX][MAX];
int sol(int pos, int cnt)
{
	if (cnt > m)
		return -INF;
	if (pos == n)
		return 0;

	int& ret = cache[pos][cnt];
	if (ret != -1)
		return ret;
	for (int i = pos + 1; i <= n; i++)
		if (arr[pos][i] > 0) 
		{
			int val = sol(i, cnt + 1) + arr[pos][i];
			if (val > ret)
				ret = val;
		}
	return ret;
}
int main()
{
	int k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cache[i][j] = -1;
	int from, to, w;
	while (k--)
	{
		cin >> from >> to >> w;
		if (arr[from][to] < w)
			arr[from][to] = w;
	}
	cout << sol(1, 1) << endl;
}