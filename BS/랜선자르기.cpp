#include <iostream>
#include <algorithm>
#define MAX 10001
#define ll long long int
using namespace std;
ll k, n;
ll arr[MAX];
ll ret = 0;
ll sol(ll mid) {
	ll ret = 0;
	for (int i = 0; i < k; i++)
		if (arr[i] >= mid)
			ret += (arr[i]/mid);
	return ret;
}
ll bs(ll left, ll right)
{

	if (left > right)
		return 0;
	 
	ll mid = (left + right) / 2;
	ll val = sol(mid);
	if (val >= n) {
		ret = max(ret, mid);
		bs(mid + 1, right);
	}else if (val < n)
		bs(left, mid-1);
	return ret;
}
int main()
{
	ll max_value = 0;
	scanf("%lld", &k);
	scanf("%lld", &n);
	for (int i = 0; i < k; i++)
	{
		scanf("%lld", &arr[i]);
		if (arr[i] > max_value)
			max_value = arr[i];
	}
	cout << bs(1, max_value) << endl;
}