#include <iostream>
#define MAX 101
#define ll long long
using namespace std;
int n;
int fac[11];
ll cache[11][MAX][MAX][MAX];
ll sol(int level, int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0)
		return 0;
	if (level == 0)
		return 1;
	ll& ret = cache[level][r][g][b];
	if (ret != -1)
		return ret;
	ret = 0;
	int div = 0;
	int val = 0;

	// 한 색
	ret += sol(level - 1, r - level, g, b);
	ret += sol(level - 1, r, g - level, b);
	ret += sol(level - 1, r, g, b - level);

	// 두 색
	if (level % 2 == 0) {	// 짝수
		div = level / 2;
		val = fac[level] / (fac[div] * fac[div]);
		ret += sol(level - 1, r - div, g - div, b)*val;
		ret += sol(level - 1, r, g - div, b - div)*val;
		ret += sol(level - 1, r - div, g, b - div)*val;

	}
	// 세가지 색
	if (level % 3 == 0) {
			div = level / 3;
			val = fac[level] / (fac[div] * fac[div] * fac[div]);
			ret += sol(level - 1, r - div, g - div, b - div)*val;
	}

	return ret;
}
int main()
{
	fac[1] = 1;
	for (int i = 2; i < 11; i++)
		fac[i] = i*fac[i - 1];

	for (int i = 0; i < 11; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
				for (int l = 0; l < MAX; l++)
					cache[i][j][k][l] = -1;
	cin >> n;
	int red, green, blue;
	cin >> red >> green >> blue;
	cout << sol(n, red, green, blue)<< endl;
}