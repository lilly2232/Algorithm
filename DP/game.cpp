#include <iostream>
#define MAX 101
#define max(a,b) a>b?a:b
using namespace std;
int arr[MAX];
int cache[MAX][MAX][2];
int n;
int game(int start, int end, int flag)
{
	if (end < start)
		return 0;
	//int& ret = cache[start][end][flag];
	//if (ret!= -1) return ret;
	int ret = 0;

	if (flag == 1) {
		ret = max(ret, game(start + 1, end, 0) + arr[start]);
		ret = max(ret, game(start, end - 1, 0) + arr[end]);
	} else {
		ret = max(ret, game(start, end - 1, 1) - arr[end]);
		ret = max(ret, game(start + 1, end, 1) -arr[start]);
	
	}
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < 2; k++)
				cache[i][j][k] = -1;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	int ret = game(0,n-1,1);
	if (ret > sum - ret)
		cout << ret << " " << sum - ret << endl;
	else
		cout << sum - ret << " " << ret << endl;
}