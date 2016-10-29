#include <iostream>
#define MAX 5555
#define max(a,b)a>b?a:b
using namespace std;
char str[MAX];
int cache[MAX][MAX];
int len;

int palin(int start, int end)	// 최대 교차하지 않는 개수 , int start, int end (시작 지점 끝지점)
{
	if (start >= len || end < 0)
		return 0;
	int& ret = cache[start][end];
	if (ret != -1) return ret;
	
	ret = 0;
	if (str[start] == str[end])
		ret = max(ret,palin(start + 1, end - 1) + 1);
	ret = max(ret,palin(start, end-1));
	ret = max(ret, palin(start+1, end));
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	cin >> len;
	cin >> str;
	cout << len - palin(0, len-1) << endl;;
}