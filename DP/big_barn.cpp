#include <iostream>
#define MAX 1001
using namespace std;
int arr[MAX][MAX];
int n;
int max_v = -1;
int cache[MAX][MAX];

int big_barn(int x, int y, int k)
{
	for (int i = x; i <= x+k; i++)
		if (arr[i][y+k] == 1 || i > n || y+k > n)
			return  k;

	for (int i = y; i < y+k; i++)
		if (arr[x+k][i] == 1 || i > n || x + k > n)
			return k;

   big_barn(x, y, k + 1);
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
				cache[i][j] = -1;
	int t_num;
	cin >> n >> t_num;
	for (int i = 0; i < t_num; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;;
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != 1) {
				int ret = big_barn(i, j, 0);
				if (max_v < ret)
					max_v = ret;
			}
		}
	cout << max_v << endl;
}