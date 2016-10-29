#include <iostream>
#define MAX 1001
#define MAXVALUE 987654321
#define min(a,b) a<b?a:b
using namespace std;
int arr[MAX][3];
int cache[MAX][3];
int num;

int RGB(int n, int pre)
{
	if (num == n) {
		return arr[n][pre];
	}
	int ret = cache[n][pre];
	if (ret != MAXVALUE) {
		return ret;
	}
	for (int i = 0; i < 3; i++)
		if (pre != i) {
			ret = min(ret, arr[n][pre] + RGB(n + 1, i));
		}
	cache[n][pre] = ret;
	return ret;
}
int main()
{
	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= num; i++)
		for (int j = 0; j < 3; j++)
			cache[i][j] = MAXVALUE;
	int ret = MAXVALUE;
	for (int i = 0; i < 3; i++)
		ret = min(ret, RGB(1,i));
	cout << ret << endl;
}