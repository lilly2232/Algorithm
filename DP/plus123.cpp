#include <iostream>
#define MAX 11
using namespace std;
int cache[MAX];

int fun_plus(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;

	int ret = cache[n];
	if (ret != -1)
		return ret;
	ret = fun_plus(n - 1) + fun_plus(n - 2) + fun_plus(n - 3);
	cache[n] = ret;
	return ret;
}
int main()
{
	int testcase;
	int n;
	cin >> testcase;

	for (int i = 0; i < MAX; i++)
		cache[i] = -1;

	while (testcase--)
	{
		cin >> n;
		cout << fun_plus(n) << endl;
	}
}