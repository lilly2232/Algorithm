#include <iostream>
#define MAX 10001
#define max(a,b)a>b?a:b
using namespace std;
int arr[MAX][7];
int num;
int max_value = -1;
int cache[7][MAX];
int dice_arr[7] = { 0,6,4,5,2,3,1 };
int dice(int next, int index)	// index 몇 번째 주사위, next 현재 index의 밑면
{
	if (index >= num)
		return 0;
	int& ret = cache[next][index];
	if (ret != -1) return ret;
	int max_v = 0;
	for (int j = 1; j <= 6; j++)
		if (j != next && dice_arr[next] != j && max_v < arr[index][j])
			max_v = arr[index][j];

	int val = arr[index][dice_arr[next]];
	int i = 1;
	for (; i <= 6; i++)
		if (val == arr[index + 1][i])
			break;
	return ret = max_v + dice(i, index + 1);

}
int main()
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	cin >> num;
	for (int i = 0; i < num; i++) 
		for (int j = 1; j <= 6; j++)
			cin >> arr[i][j];
	
	for (int i = 1; i <= 6; i++)
		max_value = max(max_value,dice(i, 0));
	cout << max_value << endl;
}