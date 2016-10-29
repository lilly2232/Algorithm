#include <iostream>
#define MAX 101
#define ll long long int	// type Çü Á¶½É!
using namespace std;

ll arr[MAX];
int main()
{
	for (int i = 0; i < MAX; i++)
		arr[i] = 0;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4; i < MAX; i++)
		arr[i] = arr[i - 3] + arr[i - 2];
	
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		int n;
		cin >> n;
		cout << arr[n] << endl;
	}
}