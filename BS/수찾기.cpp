#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
int arr[MAX];
int testarr[MAX];
int n;
int bs(int s,int e, int key)
{
	if (s > e)
		return 0;
	int mid = (s + e) / 2;

	if (arr[mid] == key)
		return 1;
	else if (arr[mid] < key)
		return bs(mid + 1, e, key);
	else if (arr[mid] > key)
		return bs(s, mid-1, key);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
		scanf("%d", &testarr[i]); 

	for (int i = 0; i < test; i++)
		printf("%d\n",bs(0,n-1,testarr[i]));

}