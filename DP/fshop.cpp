#include <iostream>
#define MAX 111
#define INF 98765432
#define max(a,b) a>b?a:b
using namespace std;
int b_num;
int f_num;
int arr[MAX][MAX] = { 0, };
int cache[MAX][MAX];

int fshop(int f_start, int b_start)
{
	if (f_num == f_start)
		return 0;
	if (f_start > f_num || b_start >= b_num)
		return -INF;

	int& ret = cache[f_start][b_start];
	if (ret != -1) return ret;
	ret = -INF;
	ret = max(ret, fshop(f_start + 1, b_start +1) + arr[f_start][b_start]);
	ret = max(ret, fshop(f_start, b_start + 1));
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;

	cin >> f_num >> b_num;
	for (int i = 0; i < f_num; i++)
		for (int j = 0; j < b_num; j++)
			cin >> arr[i][j];

	cout << fshop(0,0) << endl;
}