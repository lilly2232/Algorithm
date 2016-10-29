#include <iostream>
#include <algorithm>
#define MAX 1000001
#define INF 987654321
#define ll long long int 
using namespace std;
int m;
int n;
ll arr[MAX];
ll ans = 0;
ll sol(int mid)
{
	ll ret = 0;
	for (int i = 0; i < n; i++)
		if(arr[i] > mid)
		ret += (arr[i] - mid);
	return ret;
}
ll bs(int left, int right)
{
	if (left > right)
		return 0;

	ll mid = (left + right)/2;
	ll val = sol(mid);
	if (m <= val) 
	{
		ans = max(ans, mid);
		bs(mid + 1, right);
	}
	else {
		bs(left, mid - 1);
	}
	return ans;
}
int main()
{
	
	scanf("%d", &n);
	scanf("%d", &m);
	int max_value = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		if (arr[i] > max_value)
			max_value = arr[i];
	}
	cout << bs(0, max_value) << endl;
}