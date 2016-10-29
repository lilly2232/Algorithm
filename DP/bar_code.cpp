#include <iostream>
#define MAX 34
using namespace std;
int cache[MAX][MAX][MAX][2];
int n, k, m;
int sol(int b_cnt, int index, int iter,int pre)	// pre ���� ������ ���� , iter �ݺ���, index �� ��ġ, b_cnt ���ڵ� ���а���
{
	if (b_cnt == 1 && index == 1)
		return 1;
	if (index < 1 || b_cnt < 1)
		return 0;
	int& ret = cache[b_cnt][index][iter][pre];
	if (ret != -1) return ret;
	ret = 0;
	if (iter == m)
		 ret = sol(b_cnt-1, index-1,1, 1-pre);
	else 
		 ret = sol (b_cnt-1, index-1,1, 1-pre) + sol(b_cnt, index - 1, iter + 1, pre);
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++) 
				for (int l = 0; l < 2; l++)
					cache[i][j][k][l] = -1;
	cin >> n >> k >> m;	// n �� �ڸ��� , k : ���� ���ڵ� , m : �ִ����
	cout << sol(k,n,1,1) << endl; //������, ���� ���� ���� ���ڿ�, ���� �ݺ��� ����, ���� ������ ����
	int num;

	cin >> num;
	while (num--)
	{
		char str[MAX];
		cin >> str;
		int cnt = 0;
		int chg = 0;
		int ret = 0;

		for (int i = 1; str[i] != '\0'; i++)
		{
			chg = 0;
			if (str[i] == '0')
				cnt++;
			for (int j = 1; j < i; j++)
			{
				if (str[j] != str[j - 1])
					chg++;
			}
			if (str[i] == '1') {
				if (str[i - 1] == '0' && cnt < m) {
					ret += sol(k - chg, n - i, cnt + 1, 0);
				}
				else if (str[i - 1] == '1') {
					ret += sol(k - chg - 1, n - i, 1, 0);
				}
				cnt = 0;
			}
		}
		cout << ret << endl;
	}
}