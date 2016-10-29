#include <iostream>
#define min(a,b) a<b?a:b
#define MAX 311
#define INF 987654321
using namespace std;
int arr[MAX];
int p_sum[MAX];
int cache[MAX][MAX][MAX];
int n, p;

//int sol(int start,int num, int post[]) // 거리의 최소합, 현재 인덱스, 선택한 우체국 개수, pre 이전 우체국
//{
//	
//	if (num == p) {
//		int total = 0;
//		for (int i = 0; i < p; i++)
//		{
//			if (i == 0) {
//				for (int j = 1; j < post[i]; j++)
//					total += (arr[post[i]] - arr[j]);
//			} else {
//				for (int k = post[i - 1] + 1; k < post[i]; k++) 
//					total += min(arr[k] - arr[post[i - 1]], arr[post[i]] - arr[k]);
//			}
//		}
//		if (post[p - 1] < n) {
//			for (int j = post[p-1]+1; j <= n; j++)
//				total += (arr[j] - arr[post[p-1]]);
//		}
//			return total;
//	}
//	if (start > n )
//		return INF;
//	
//	int& ret = cache[start][num];
//	//if (ret != -1) return ret;
//	ret = INF;
//	
//	post[num] = start;
//	ret = min(ret,sol(start + 1, num+1, post));
//	ret = min(ret,sol(start + 1, num, post));
//	return ret;
//}
int sol(int start,int num, int pre) // 거리의 최소합, 현재 인덱스, 선택한 우체국 개수, pre 이전 우체국
{
	
	if (num == p) {
		int total = 0;
		if (pre < n) {
				for (int j = pre+1; j <= n; j++)
				total += (arr[j] - arr[pre]);
		}
		return total;
	}
	if (start > n )
		return INF;
	
	int& ret = cache[start][num][pre];
	if (ret != -1) return ret;
	ret = INF;
	int total = 0;
	if (pre == 0)
	{
		for (int i = 1; i < start; i++)
			total += arr[start] - arr[i];
		ret = min(ret, sol(start + 1, num + 1, start)+total);
	}
	else {
		for (int k = pre + 1; k < start; k++)
			total += min(arr[k] - arr[pre], arr[start] - arr[k]);
		ret = min(ret, sol(start + 1, num + 1, start) + total);
	}
	ret = min(ret,sol(start + 1, num,pre));
	return ret;
}

int main()
{
	cin >> n >> p;
	arr[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX;k++)
			cache[i][j][k] = -1;

	cout << sol(1, 0, 0) << endl;
}