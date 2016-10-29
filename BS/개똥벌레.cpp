#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 500001
#define INF 987654321
#define lld long long 
int up[MAX];
int down[MAX];
int n;
int h;
lld cnt = 0;
lld sum[MAX];
lld key = 0;
//lld sol(int m)
//{
//	lld ret = 0;
//	for (int i = 0; i < n; i++)
//		if (i == 0 || i % 2 == 0)
//		{
//			if (arr[i] >= m)
//				ret += 1;
//		}
//		else
//		{
//			if (arr[i] > (h - m))
//				ret += 1;
//		}
//	return ret;
//}
void bs(int left, int right)
{
	if (left > right)
		return;
	int mid = (left + right) / 2;

	if (sum[mid] == key) {
		cnt++;
		bs(mid + 1, right);
		bs(left, mid - 1);
	}
	else if (sum[mid] < key)
		bs(mid + 1, right);
	else
		bs(left, mid - 1);
}
int main()
{
	scanf("%d %d", &n, &h);
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (i % 2 == 0)
			down[x]++;
		else
			up[x]++;
	}

	for (int i = h - 1; i > 0; i--) {
		down[i] = (down[i] + down[i + 1]);
		up[i] = (up[i] + up[i + 1]);
	}

	for (int i = 1; i <= h ; i++) 
		sum[i] = down[i] + up[h-i+1];
	
	sort(sum+1, sum + h + 1);
	
	key = sum[1];
	bs(1, h);

	cout << key << " " << cnt << endl;
}