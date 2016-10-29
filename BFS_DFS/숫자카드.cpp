#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;
int arr[MAX];
int key;
bool bs(int left, int right)
{
	if (left > right)
		return false;
	int mid = (left + right) / 2;
	if (arr[mid] == key)
		return true;
	else if (arr[mid] < key)
		return bs(mid + 1, right);
	else
		return bs(left, mid - 1);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &key);
		printf("%d ", bs(0, n - 1));
	}
	cout << endl;
}