#include <iostream>
using namespace std;
int num;
int max_value = 0;

void dfs(int n)
{
	if (n > num)
		return;
	if (max_value < n)
		max_value = n;
	dfs(n * 10 + 4);
	dfs(n * 10 + 7);
}
int main()
{
	cin >> num;
	dfs(0);
	cout << max_value;
}