#include <iostream>
#define MAX 1111
#define max(a,b) a>b?a:b
using namespace std;
int arr[MAX][MAX];
int cache[MAX][MAX];
int num;
int sol(int x, int y)
{
	if (x > num || y > num)
		return 0;
	int& ret = cache[x][y];
	if (ret != -1) return ret;
	ret = max(ret, sol(x + 1, y)+ arr[x][y]);
	ret = max(ret, sol(x + 1, y + 1) + arr[x][y]);
	return ret;
}
int main()
{
	cin >> num;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
				cache[i][j] = -1;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= i; j++)
			cin >> arr[i][j];
	cout << sol(1, 1) << endl;
}