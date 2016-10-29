#include <iostream>
#define MAX 22
#define INF 987654321
#define min(a,b) a<b?a:b

using namespace std;
int num;
int cnt;
int arr[MAX];
int cache[MAX][MAX][MAX];
int sol(int pos, int f, int s)
{
	if (pos == cnt)
		return 0;

	int& ret = cache[pos][f][s];
	if (ret != -1)
		return ret;
	ret = INF;
	int loc = arr[pos];

	if (loc == f || loc == s)
		ret = sol(pos + 1, f, s);
	if (loc < f && loc < s)
	{
			ret = min(ret, (s - loc) + sol(pos + 1, loc, f));
			ret = min(ret, (f - loc) + sol(pos + 1, loc, s));
	}
	if (loc > f && loc > s)
	{
			ret = min(ret, (loc - f) + sol(pos + 1, loc, s));
			ret = min(ret, (loc - s) + sol(pos + 1, loc, f));
	}

	if (loc > f && loc < s) {
	
			ret = min(ret, (loc - f ) + sol(pos + 1, loc, s));
			ret = min(ret, (s - loc) + sol(pos + 1, loc, f));
	} 
	if (loc > s && loc < f)
	{
		ret = min(ret, (loc - s) + sol(pos + 1, loc, f));
		ret = min(ret, (f - loc) + sol(pos + 1, loc, s));

	}
	return ret;
}
int main()
{
	cin >> num;
	int first, sec;
	cin >> first >> sec;
	cin >> cnt;
	for (int i = 0; i < cnt; i++)
		cin >> arr[i];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
				cache[i][j][k] = -1;
	cout << sol(0, first, sec) << endl;
}