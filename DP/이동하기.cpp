#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;
int col;
int row;
int arr[MAX][MAX];
int cache[MAX][MAX];
int sol(int i, int j)
{
	if (i > col || j > row)
		return 0;
	int& ret = cache[i][j];
	if (ret != -1)return ret;

	ret = max(ret, sol(i+1, j) + arr[i][j]);
	ret = max(ret, sol(i, j+1) + arr[i][j]);
	ret = max(ret, sol(i+1, j+1) + arr[i][j]);
	return ret;
}
int main()
{
	cin >> col >> row;
	for (int i = 1; i <= col; i++)
		for (int j = 1; j <= row; j++) {
			cin >> arr[i][j];
			cache[i][j] = -1;
		}
	cout << sol(1, 1) << endl;
}