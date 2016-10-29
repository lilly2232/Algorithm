#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int arr[MAX];
int cache[MAX];
int n;

int sol(int pos)	// 최대로 마실 수 있는 포도주 값
{

	if (pos > n)
		return 0;
	int& ret = cache[pos];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, sol(pos + 1));
	ret = max(ret, sol(pos + 2) + arr[pos]);
	ret = max(ret, sol(pos + 3) + arr[pos] + arr[pos + 1]);

	return ret;
}
int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 0; i < n + 1; i++)
		cache[i] = -1;
	cout << sol(1) << endl;
}