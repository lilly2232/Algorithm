#include <iostream>
#define MAX 2001
#define max(a,b) a>b?a:b
using namespace std;
int n;
int arr[MAX];
int cache[MAX][MAX];
//int treat(int index, int day)	// 최대값 출력
//{
//	if (index >= n || index < 0 )
//		return 0;
//	int& ret = cache[index][day];
//	ret = 0;
//	if (visit[index] != 1) {
//		visit[index] = 1;
//		ret = max(ret, day * arr[index] + treat(index + 1, day + 1));
//		visit[index] = 0;
//	}
//	for (int i = n-1; i >= index; i--)
//		if (visit[i] == 0) {
//			visit[i] = 1;
//			ret = max(ret, day * arr[i] + treat(index, day + 1));
//			visit[i] = 0;
//			break;
//	}
//	return ret;
//}

int treat(int start,int end)	// 최대값 출력 (현재 앞으로갈 위치, 뒤에서 앞으로 갈 위치)
{
	if (start > end)
		return 0;
	int& ret = cache[start][end];
	if (ret != -1) return ret;		// 캐싱을 안하다니.. 
	ret = 0;
	int day = start - 0 + n - end;
	ret = max(ret, day * arr[start] + treat(start + 1, end));
	
	ret = max(ret, day * arr[end] + treat(start, end-1));

	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	for (int i = 0; i < n; i++)
		cin >> arr[i]; 
	cout << treat(0, n-1) << endl;
}