#include <iostream>
#define MAX 1001
#define INF 98765432
#define max(a,b)a>b?a:b
using namespace std;
int minute, change;
int arr[MAX];
int cache[MAX][31][3];
int catching(int time, int ch, int tree)
{
	if (ch > change || time > minute)
		return -INF;
	int& ret = cache[time][ch][tree];
	if (ret != -1) return ret;
	ret = 0;
	if (arr[time] == tree)
		ret = max(ret, catching(time + 1, ch, tree) + 1);
	else
	{
		int next = -1;
		if (tree == 1)
			next = 2;
		else
			next = 1;
		ret = max(ret, catching(time + 1, ch + 1, next) + 1);
	}
	ret = max(ret, catching(time + 1, ch, tree));

	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 31; j++)
			for (int k = 0; k < 3; k++)
				cache[i][j][k] = -1;

	cin >> minute >> change;
	for (int i = 0; i < minute; i++)
		cin >> arr[i];

	cout << catching(0, 0, 1) << endl;
}