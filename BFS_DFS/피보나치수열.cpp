#include <iostream>
using namespace std;
int n;

int main()
{
	cin >> n;
	
	int arr[41];
	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i < n; i++)
	{
		arr[i] = arr[i-1] + arr[i - 2];
	}
	cout << arr[n - 1] << endl;
}