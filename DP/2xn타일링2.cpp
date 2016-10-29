#include <iostream>
#define MAX 1001
using namespace std;
int cache[MAX] = { 0, };
int tile(int n)
{
	if (n == 2)
		return 3;
	if (n == 1)
		return 1;
	int ret = cache[n];
	if (ret != -1)
		return ret;
	ret = (tile(n - 2)+ tile(n - 2)+ tile(n - 1))%10007;	// 2*2, 2*1 (가로), 2*1 (세로) 
	cache[n] = ret;
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		cache[i] = -1;

	int num;
	cin >> num;
	cout << tile(num);
}