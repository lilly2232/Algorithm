#include <iostream>
#define MAX 50001
#define max(a,b)a>b?a:b
using namespace std;
int num;
int lim;
int arr[MAX];
int cache[MAX][4];
int sol(int pos, int cnt)	// 최대로 운송할 수 있는 손님 수 
{
	if (pos > num) return 0;
	if (cnt == 0) return 0;
	int& ret = cache[pos][cnt];
	if (ret != -1) return ret;

	int val = 0;
	for (int i = 0; i < lim && pos+i <= num; i++)	// 배열 초과 (예외) 
		val += arr[pos + i];
	
	ret = max(ret,(val + sol(pos + lim, cnt - 1)));
	ret = max(ret,sol(pos + 1, cnt));
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 4; j++)
			cache[i][j] = -1;
	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> arr[i];
	cin >> lim;
	cout << sol(1,3) << endl;
}