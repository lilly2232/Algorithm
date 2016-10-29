#include <iostream>
#define max(a,b)a>b?a:b
using namespace std;
int arr[301][21];
int cache[301][21];
int m, n;
int choices[301];

int invest(int money, int index)
{
	if (m <= money || index >= n)
		return 0;
	int& ret = cache[money][index];
	if (ret != -1) return ret;
	ret = 0;
	int val = invest(money + arr[index][0], index) + arr[index][1];
	int bestnext = -1;
	if (ret < val)
	{
		ret = val;
		bestnext = index;
	}
	ret = max(ret, invest(money, index + 1));
	return ret;
}
int main()
{
	for (int i = 0; i < 301; i++)
		for (int j = 0; j < 21; j++)
			cache[i][j] = -1;
	for (int i = 0; i < 301; i++)
		choices[i] = -1;

	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < 301; i++)
		arr[i][0] = i;
	cout << invest(0, 1) << endl;
} 