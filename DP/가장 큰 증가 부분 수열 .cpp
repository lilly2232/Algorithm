#include <iostream>
#define MAX 1001
#define max(a,b) a>b?a:b
using namespace std;
int n;
int arr[MAX];
int cache[MAX];
//int lis(int start)
//{
//
//	int ret = 0;
//	for (int i = start + 1; i < n; i++)
//		if (start == -1 || arr[start] < arr[i])
//				ret =  max(ret, 1 + lis(i));
//	return ret;
//}
int lis(int start)
{
	int& ret = cache[start+1];		// "-1" 때문에...ㅠㅠ
	if (ret != 0)
		return ret;
	for (int i = start + 1; i < n; i++)
		if (start == -1 || arr[start] < arr[i])
			ret = max(ret, arr[i] + lis(i));
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < MAX; i++)
		cache[i] = 0;
	cout << lis(-1) << endl;
}

//int lis(int start)
//{
//	int& ret = cache[start + 1];		// "-1" 때문에...ㅠㅠ
//	if (ret != -1)
//		return ret;
//	ret = 1;
//	for (int i = start + 1; i < n; i++)
//		if (start == -1 || arr[start] < arr[i])
//			ret = max(ret, arr[i] + lis(i));
//	return ret;
//}

//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//	for (int i = 0; i < MAX; i++)
//		cache[i] = -1;
//	cout << lis(-1)-1 << endl;
//}