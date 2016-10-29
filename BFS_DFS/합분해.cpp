#include <iostream>
#define MOD 1000000000
#define MAX 205
#define ll long long int 
using namespace std;
// 0~N���� ���� K�� �� ���ؼ� �� ���� N�� �Ǵ� ����� ���� ���ϴ� ���α׷� �ۼ�
int n;
ll cache[MAX][MAX];
int k;
ll sol(int cnt, int total)	// K���� ���� N�̵Ǵ� ����� �� 
{
	if (total == n && cnt == k)
		return 1;

	ll& ret = cache[cnt][total];
	if(ret != -1) return ret;

	ret = 0;
	for (int i = n; i >= 0; i--)
		if (total + i <= n && cnt + 1 <= k) 
			ret += sol(cnt + 1, total + i)%MOD;
	return ret;
}

int main()	
{
	cin >> n >> k;

	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= n; j++)
				cache[i][j] = -1;

	cout << sol(0, 0)%MOD << endl;
}