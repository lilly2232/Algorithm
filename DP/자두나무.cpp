#include <iostream>
#define MAX 1001
#define INF 987654321
#define max(a,b) a>b?a:b
using namespace std;
int t, w;
int arr[MAX];
int cache[MAX][3][31];
int sol(int pos,int pre, int limit)
{
	if (pos > t)
		return 0;

	int& ret = cache[pos][pre][limit];
	if (ret != -1) return ret;
	ret = 0;
	if (arr[pos] == pre) {
		ret = max(ret, 1 + sol(pos + 1, pre, limit));
	}
	if (arr[pos] != pre) {
		if(limit < w)	//  
			ret = max(ret,1 + sol(pos + 1, arr[pos], limit + 1));
		ret = max(ret,sol(pos + 1, pre, limit));
	}
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 31; k++)
				cache[i][j][k] = -1;
	cin >> t >> w;
	for (int i = 1; i <= t; i++)
		cin >> arr[i];
	cout << sol(1, 1, 0) << endl;
}  