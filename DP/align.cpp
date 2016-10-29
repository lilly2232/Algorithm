#include <iostream>
#define MAX 201
#define max(a,b)a>b?a:b
using namespace std;
int n;
int arr[MAX];
int cache[MAX];

int align(int start)
{
	int& ret = cache[start + 1];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i = start + 1; i < n; i++)
		if (start == -1 || arr[start] < arr[i])
			ret = max(ret, 1 + align(i));
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		cache[i] = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << n - (align(-1) - 1) << endl;
}