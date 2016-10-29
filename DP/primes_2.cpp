#include <iostream>
#define MAX 20000
using namespace std;
int sosu_arr[MAX];
int arr[MAX] = { 0, };
int index = 0;
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
			index++;
		}
	}
}

int main()
{
	make_sosu();

	for (int i = 0; i < index; i++)
		arr[sosu_arr[i]] = 1;

	for (int j = 2; j < index; j++)
		for (int i = 0; i <= index - j; i++)
		{
			int n = 0;
			for (int k = 0; k < j && n + sosu_arr[i + k] <10001; k++) {
				n += sosu_arr[i + k];
			}
			if (n > 10001)
				n = 0; 
			arr[n]++;
		}

	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		int ret = 0;
		cout << arr[n] << endl;
	}
}