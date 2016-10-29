#include <iostream>
#define MAX 32
#define lld long long int
using namespace std;
lld n, limit, find_num;
lld cnt = 0;


void stringsobits(int index, int total, int arr[])
{
	if (cnt > find_num || total > limit)
		return;

	if (index == n)
	{
		if (total <= limit)
			cnt++;
		if (cnt == find_num)
		{
			for (int i = 0; i < n; i++)
				cout << arr[i];
			cout << endl;
			cnt++;
		}
		return;
	}


	arr[index] = 0;
	stringsobits(index + 1, total, arr);
	arr[index] = 1;
	stringsobits(index + 1, total + 1, arr);
} 
int main()
{
	cin >> n >> limit >> find_num;
	int arr[MAX] = { 0, };

	stringsobits(0, 0, arr);
	return 0;
}