#include <iostream>

#define MAX 255
#define lld unsigned long long int
using namespace std;
int num;
lld cache[MAX];
lld tiling(int rest)
{
	if (rest == 0 || rest == 1)
		return 1;
	lld& ret = cache[rest];
	if (ret != -1) return ret;
	ret = 0;
	ret = tiling(rest - 1) + tiling(rest-2) * 2;
	return ret;
	
}
int main()
{
	for (int i = 0; i < MAX; i++)
		cache[i] = -1;

	cin >> num;
	cout << tiling(num) << endl;
}