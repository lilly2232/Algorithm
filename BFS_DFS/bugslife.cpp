#include <iostream>
#define MAX 2001
using namespace std;
int arr[MAX][MAX] = { 0, };
int visit[MAX] = { 0, };
bool sup = false;
int n, m;

void dfs(int here)
{
	if (visit[here] == 0)
		visit[here] = 1;
	for (int i = 1; i < n+1; i++)
	{

		if (arr[here][i] == 1)
		{
 			if (visit[i] == 0)
			{
				if (visit[here] == 1)
					visit[i] = -1;
				else if (visit[here] == -1)
					visit[i] = 1;
				dfs(i);
			}
			else if (visit[here] == visit[i]) 
			{
				sup = true;
			}
		}
	}
}
int main()
{
	int x, y;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int i = 1; i < n+1; i++)
		if (visit[i] == 0)
			dfs(i);

	if (sup == true)
		cout << "Suspicious bugs found!" << endl;
	else
		cout << "No suspicious bugs found!" << endl;
}


