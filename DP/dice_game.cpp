#include <iostream>
#include <vector>
#define max(a,b)a>b?a:b
#define MAX 111
using namespace std;
int num;
int arr[MAX];
int cache[MAX][3];
int choices[MAX];

int dice(int index, int pre)	// 최대 거리, index 현위치, pre 전진횟수
{
	if (index > num)
		return 0;
	int& ret = cache[index][pre];
	if (ret != -1)
		return ret;
	ret = 0;
	if(pre < 2) {
		ret = max(ret, arr[index] + dice(index + 1, pre+1));
	ret = max(ret, dice(index + 1, 0) - arr[index]);
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	cout << dice(0, 0) << endl;
}