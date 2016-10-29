#include <iostream>
#define MAX 32
using namespace std;
int n, m;
int cache[MAX][MAX];

int bits(int num, int total)
{
	if (num == n && total <= m)
		return 1;
	int& ret = cache[num][total];
	if (ret != -1) return ret;
	ret = 0;
	ret = bits(num + 1, total) + bits(num+1, total+1);
	return ret;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	cout << bits(0, 0) << endl;
}