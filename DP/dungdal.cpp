#include <iostream>
#define MAX 102			// 왜 102 이지?! 1~100 => 101 ...
#define max(a,b)a>b?a:b

using namespace std;
int arr[MAX];
int num;
int cache[MAX];
int dungdal(int start) // return : 최대 합, start 현재 위치 
{
	if (start > num)
		return 0;
	int& ret = cache[start];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, arr[start] + dungdal(start + 2));
	ret = max(ret, arr[start] + arr[start + 1] + dungdal(start + 3));
	ret = max(ret, dungdal(start+1));

	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		cache[i] = -1;

	cin >> num;
	for (int i = 1; i <= num; i++)
		cin >> arr[i];
	arr[0] = 0;

	cout << dungdal(0) << endl;
}
