#include <iostream>
#define MAX 10001
using namespace std;
int sosu_arr[MAX];
int p_sum[MAX];
int index = 1;
int n;
int n_index;
void make_sosu()
{
	for (int i = 2; i < 10001; i++)
	{
		int j;
		for (j = 2; j < i; j++)
			if (i % j == 0)
				break;
		if (j == i) {
			sosu_arr[index] = i;
			p_sum[index] = p_sum[index - 1] + i;
			index++;
		}
	}
}
int primes(int start, int end)	// return 경우의 수 , idx 시작 인덱스 , 끝인덱스 
{
 	if (p_sum[end] - p_sum[start] == n)
		return 1;
	else
		return 0;
}
int main()
{
	make_sosu();
	p_sum[0] = 0;

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		int ret = 0;
		for (n_index = 1;; n_index++) {
			if (sosu_arr[n_index] >= n)
				break;
		}
		for (int i = 0; i <= n_index; i++)
			ret += (primes(n_index - i,n_index) + primes(0,i));
		cout << ret << endl;
	}
}