#include <iostream>
#define MAX 111
#define max(a,b)a>b?a:b
using namespace std;
int str[MAX];
int m_str[MAX];
int len;
int m_len;
int cache[MAX][MAX][MAX][2];

int crossed(int start, int end, int pre, int flag)	// 최대선분의 개수, 시작 선, 이전 연결한 점, 한개인가 두개인가
{
	if (start >= len || end >= m_len)
		return 0;
	int& ret = cache[start][end][pre][flag];
	if (ret != -1) return ret;
	
	ret = 0;
	if (str[start] == m_str[end])
	{
		if (flag == 0) {
			ret = max(ret, crossed(start + 1, pre, end, 1));
		} else {
			if (flag == 1 && end < pre && m_str[end] != m_str[pre])
				ret = max(ret, crossed(start + 1, pre + 1, pre+1 ,0) + 2);
		}
	}
	ret = max(ret, crossed(start, end + 1, pre,flag));
	ret = max(ret, crossed(start + 1, end, pre,flag));
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
				for (int l = 0; l < 2;l++)
					cache[i][j][k][l] = -1;
	cin >> len >> m_len;
	for (int i = 0; i < len; i++)
		cin >> str[i];
	for (int i = 0; i < m_len; i++)
		cin >> m_str[i];
	cout << crossed(0, 0 ,0,0) << endl;
}