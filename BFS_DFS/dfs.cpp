#include <iostream>
#define MAX 11
using namespace std;
int arr[MAX][MAX];
int visit[MAX];
int num;
void dfs(int v)
{
	cout << v << " ";
	visit[v] = 1;
	for (int i = 1; i <= num; i++)
		if (visit[i] == 0 && arr[v][i] == 1)
			dfs(i);

}
int main()
{
	int start;
	cin >> num >> start;
	while (!cin.eof())
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int i = 1; i <= num; i++)
		visit[i] = 0;
	dfs(start);
	cout << endl;
}