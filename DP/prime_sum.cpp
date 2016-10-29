#include <iostream>
#define MAX 11111
#define MOD 123456789
using namespace std;
int n;
int cache[2000][MAX];
int sosu_arr[MAX];
int sosu[MAX];
int max_index = 0;
int prime_sum(int index, int total)	// 최대 가지수, index 현재 , total 총합
{
	if (total == n)
		return 1;
	if (index >= max_index || total > n)
		return 0;
	int& ret = cache[index][total];
	if (ret != -1) return ret;
	ret = 0;
	if (total + sosu[index] <= n)
		ret += prime_sum(index + 1, total + sosu[index]);
	ret %= MOD;
	ret += prime_sum(index + 1, total);
	ret%= MOD;
	return ret;
}
void make_sosu()
{
	bool flag = true;
	int next = 0; 
	while (flag) {
		sosu_arr[0] = 1;
		sosu_arr[1] = 1;

		while (1) {
			if (sosu_arr[next] == 0)
				break;
			next++;
		}
		if (next > MAX)
			flag = false;
		for (int i = next *  next; i < MAX; i+= next)
		{
			if (sosu_arr[i] == 0)
				sosu_arr[i] = 1;
		}
		next++;
	}
}
int main()
{
	
	for (int i = 0; i < 2000; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	make_sosu();

	for (int i = 0; i < MAX; i++)
	{
		if (sosu_arr[i] == 0)
			sosu[max_index++] = i;
	}
	cin >> n;
	cout << prime_sum(0, 0)%MOD<< endl;
}