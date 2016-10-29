#include <iostream>
#define MAX 16
using namespace std;
int arr[MAX][MAX];
int n;
bool check(int x, int y)
{
	for (int i = 0; i < n; i++) 
		if (i != x && arr[i][y] == 1)
			return false;
	
	for (int i = 1; x - i >= 0 && y - i >= 0; i++)
		if (arr[x - i][y - i] == 1)
			return false;

	for (int i = 1; x + i < n && y + i < n; i++)
		if (arr[x + i][y + i] == 1)
			return false;


	for (int i = 1; x - i >= 0 && y + i < n; i++)
		if (arr[x - i][y + i] == 1)
			return false;


	for (int i = 1; x + i < n && y - i>= 0; i++)
		if (arr[x + i][y - i] == 1)
			return false;

	return true;
}
int sol(int x)
{
	if (x == n) 
		return 1;

	int ret = 0; 
	for (int i = 0; i < n; i++)
		if (check(x, i) == true) 
		{
			arr[x][i] = 1;
			ret += sol(x + 1);
			arr[x][i] = 0;
		}
	return ret;
}
int main()

{
	cin >> n;
	cout << sol(0) << endl;
}