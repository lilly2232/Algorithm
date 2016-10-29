#include <iostream>
#include <stdio.h>

using namespace std;
int arr[2001];
int cache[2001][2001];
int n;

int sol(int start, int end)
{
	if (start > end)
		return 0;

	int &ret = cache[start][end];
	if (ret != -1) return ret;

	if (arr[start] == arr[end]) {
		if (start == end || start + 1 == end)
			return 1;
		ret = sol(start + 1, end - 1);
	}
	else
		ret = 0;
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				cache[i][j] = 1;
			else
				cache[i][j] = -1;
		}


	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		int start, end;
		scanf("%d %d", &start,&end);
		printf("%d\n", sol(start,end));
	}
}