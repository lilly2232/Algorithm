#include <iostream>
#define MAX 41
using namespace std;
int set_arr[MAX] = { 0, };
int cache[MAX][MAX];

int num;

int seat(int n,int next)
{
	if (next > num || n > num)
		return 0;
	if (n != next)
		if (set_arr[n] == 1 || set_arr[next] == 1) 
			return 0;
	if (n == num)
		return 1;

	int& ret = cache[n][next];
	if (ret != -1)
		return ret;
	if (n < next)
		ret = seat(n + 1, n);
	else
		ret = seat(n + 1, n + 1) + seat(n + 1, n + 2);
	return ret;
}
//int seat(int n, int next)
//{
//	if (next > num || n > num)
//		return 0;
//	if (n != next)
//		if (set_arr[n] == 1 || set_arr[next] == 1)
//			return 0;
//	if (n == num)
//		return 1;
//	if (n < next)
//		return  seat(n + 1, n);
//	else
//		return  seat(n + 1, n + 1) + seat(n + 1, n + 2);
//}

int main()
{
	int set;
	cin >> num;
	cin >> set;
	for (int i = 0; i <= num; i++)
		for (int j = 0; j <= num; j++)
			cache[i][j] = -1;
	for (int i = 0; i < set; i++) {
		int set_seat;
		cin >> set_seat;
		set_arr[set_seat] = 1;
	}
	cout << seat(1,1) + seat(1,2)<< endl;
}