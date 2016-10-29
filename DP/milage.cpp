#include <iostream>

#define MAX 101
#define max(a,b) a>b?a:b
using namespace std;
int num;
int k;
int arr[MAX][MAX];
int cache[MAX][MAX];
int sol(int start, int n)
{
	if (n == k)
		return 0;
	int& ret = cache[start][n];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = start+1; i <= num; i++)
		ret = max(ret, sol(i, n + 1) + arr[start][i]);
	return ret;
}
int main()
{
	cin >> num >> k;
	for (int i = 1; i < num; i++)
		for (int j = i + 1; j <= num; j++) 
			cin >> arr[i][j];	
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	cout << sol(1,0) << endl;
}