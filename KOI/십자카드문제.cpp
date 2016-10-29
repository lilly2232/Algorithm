#include <iostream>
using namespace std;

int is_num(int x)
{
	int arr[4];
	arr[0] = x;
	for (int i = 1; i < 4; i++)
	{
		arr[i] = (arr[i-1] / 1000) + (arr[i-1] % 1000) * 10;
	}
	int min = x;
	for (int i = 0; i < 4; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}
int main()
{
	int arr[4];
	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	int num = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
	num = is_num(num);
	int cnt = 1;
	while (1)
	{
		if (num == 1111) { break; }
		num--;
		if (is_num(num) == num && num % 10 != 0) {
			cnt++;
		}
	
	}
	cout << cnt << endl;
}