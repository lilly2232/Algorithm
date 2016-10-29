#include <iostream>
#define MAX 111
#define max(a,b) a>b?a:b
#define INF 987654321
using namespace std;
int n, m;
int arr[MAX];
int cache[MAX][MAX];

int ninterval(int index, int start)	// 현재 구간의 합 , index 몇번째 구간, 시작 지점 
{
	if (start == n && index == m + 1)
		return 0;
	if (start >= n || index > m ) 
		return -INF;

	int min_v = INF;
	int max_v = -INF;
	int& ret = cache[index][start];
	if (ret != -1) return ret;

	for (int i = start; i < n; i++)
	{
		if (arr[i] < min_v)
		{
			min_v = arr[i];
		}
		if (arr[i] > max_v)
		{
			max_v = arr[i];
		}
		ret = max(ret, ninterval(index + 1, i + 1) + (max_v - min_v));
	}

	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	cout << ninterval(1,0) << endl;
}