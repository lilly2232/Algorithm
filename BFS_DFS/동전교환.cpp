#include <iostream>
#define MAX 11
#define MMAX 64001
#define INF 987654321
#define min(a,b) a<b?a:b
using namespace std;
int arr[MAX];
int n;
int cache[MMAX];

int sol(int m)	// m을 만드는 동전의 최소 가지 수 m(0~64001)
{
	if (m == 0)
		return 0;
	if (m < 0)
		return INF;
	int& ret = cache[m];
	if (ret != INF) return ret;

	for (int i = 0; i < n; i++)
			ret = min(1 + sol(m - arr[i]), ret);
	
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int m;
	cin >> m;
	for (int j = 0; j <= m; j++)
		cache[j] = INF;
	int val = sol(m);
	if (val == INF)
		cout << "impossible" << endl;
	else
		cout << val << endl;
	return 0;

}