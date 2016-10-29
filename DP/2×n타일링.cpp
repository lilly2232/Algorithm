#include <iostream>
#define MAX 1001
#define lld long long int
using namespace std;
lld  cache[MAX];

lld tile(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;

	lld ret = cache[n];
	if (ret != -1)
		return ret;
	ret = (tile(n - 1) + tile(n - 2)) % 10007;		// (a+b)% MOD == (a % MOD + b% MOD); 동일 저 자체의 값이 깨진당..
	cache[n] = ret;
	return ret;
}
int main()
{
	int num;
	cin >> num;

	for (int i = 0; i < MAX; i++)
		cache[i] = -1;
	
	cout << tile(num) << endl;
}