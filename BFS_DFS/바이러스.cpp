#include <iostream>
#define MAX 101
using namespace std;
int num;
int arr[MAX][MAX];
int visit[MAX];
int cnt = 0;
void dfs(int v)
{
	cnt++;
	visit[v] = 1;
	
	for (int i = 1; i <= num; i++)
		if (arr[v][i] == 1 && visit[i] == 0)
			 dfs(i);	
}
int main()
{
	cin >> num;
	int edge;
	int x, y;
	
	cin >> edge;
	while (edge--) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(1);
	cout << cnt-1 << endl;
}