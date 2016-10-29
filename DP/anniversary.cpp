#include <iostream>
#define MAX 6001
#define INF 987654321
#define max(a,b) a>b?a:b
using namespace std;
int arr[MAX];
int matrix[MAX][MAX];
int cache[MAX][MAX];
int num;

int sol(int index, int pre)
{
	if (index > num)
		return 0;

	int& ret = cache[index][pre];
	if (ret != -1) return ret;
	ret = -INF;


	if (matrix[pre][index] != 1)
		ret = max(ret, arr[index] + sol(index + 1, index));

	ret = max(ret, sol(index + 1, pre));

	return ret;
}
int main()
{

	cin >> num;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	for (int i = 1; i <= num; i++)
		cin >> arr[i];


	while (1)
	{
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0)
			break;
		matrix[x][y] = 1;
		matrix[y][x] = 1;
	}
	cout << sol(1, 0) << endl;
}