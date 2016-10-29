#include <iostream>
#define MAX 101
using namespace std;
int num;
int arr[MAX][MAX];
int visit[MAX];
void dfs(int v)
{
	visit[v] = 1;
	for (int i = 1; i <= num; i++)
		if (arr[v][i] == 1 && visit[i] == 0)
			dfs(i);
} 
int main()
{
	cin >> num;
	int n,x,y;
	cin >> n;
	while (n--)
	{
		cin >> x >> y; 
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int i = 1; i <= num; i++)
		visit[i] = 0;
	dfs(1);
	int cnt = 0; 
	for (int i = 2; i <= num; i++)
		if (visit[i] == 1)
			cnt++;
	cout << cnt<< endl;
}