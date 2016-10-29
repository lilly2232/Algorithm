#include <iostream>
#define max(a,b)a>b?a:b
#define MAX 50001
using namespace std;
int arr[MAX];
int cache[MAX][4];
int num;
int max_num;

int sol(int index, int limit) // 최대 손님수, 현재 위치
{
	if (index >= num || limit >= 3)
		return 0;
	int& ret = cache[index][limit];
	if (ret != -1) return ret;
	int val = 0;
	for (int i = index; i < index + max_num; i++)
		val += arr[i];
	ret = max(ret, sol(index + max_num, limit + 1)+val);
	ret = max(ret, sol(index + 1, limit));
	return ret;

}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 4; j++)
			cache[i][j] = -1;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	cin >> max_num;
	cout << sol(0,0) << endl;
}