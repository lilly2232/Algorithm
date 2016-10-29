#include <iostream>
#define MAX 501
#define INF 987654321
#define max(a,b)a>b?a:b
using namespace std;
int len;
char str[MAX];
int cache[MAX][MAX];
int sol(int s, int e)
{
	if (s > e) return 0;
	int& ret = cache[s][e];
	if (ret != -1) return ret;
	ret = 0; 
	if (str[s] == 'a')
	{
		for (int i = s + 1; i <= e; i++)
			if (str[i] == 't')
				ret = max(ret,sol(s + 1, i-1) + sol(i+1, e) + 2);
	}
	if (str[s] == 'g')
	{
		for (int i = s + 1; i <= e; i++)
			if (str[i] == 'c')
				ret = max(ret,sol(s + 1, i-1) + sol(i+1, e) + 2);
	}
	ret = max(ret, sol(s + 1, e));
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	cin >> str;
	for (len = 0; str[len] != '\0'; len++) {}
	cout << sol(0, len-1) << endl;
}