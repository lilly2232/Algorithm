#include <iostream>
#define MAX 10001
#define min(a,b)a<b?a:b
#define INF 98765432
using namespace std;
int num;
int arr[MAX];
int cache[MAX];

int pongdang(int start)	// return : 최소 비용, start : 현재 위치 
{
	if (start > num)
		return 0; 
	int& ret = cache[start];
	if (ret != INF) return ret;
	for (int i = start+1; i < start+4; i++)
	{
		ret = min(ret, arr[start] + pongdang(i));
	}
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		cache[i] = INF;
	cin >> num;
	arr[0] = 0;
	for (int i = 1; i <= num; i++)
		cin >> arr[i];
	cout << pongdang(0) << endl;
}