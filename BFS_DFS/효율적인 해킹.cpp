#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
#define MAX 10001
//int arr[MAX][MAX];	// 2���� �迭?? 
vector<vector<int> > arr;
int visit[MAX];
int ret[MAX];
void dfs(int v)
{
	visit[v] = 1; 
	
	for (int i = 0; i < arr[v].size(); i++)
	{
		int next = arr[v][i];
		if (visit[next] == 0)
			dfs(next);
	}
}
void init()
{
	for (int i = 1; i <= n; i++)
		visit[i] = 0; 
}
int main()
{
	int m;
	cin >> n >> m; 
	arr = vector<vector<int> >(n+1);
	while (m--)
	{
		int x, y; 
		cin >> x >> y;	// A�� B�� �ŷ��Ѵ�. B��ŷ�ϸ� A ��ŷ
		arr[y].push_back(x);
		//arr[y][x] = 1;
	}
	
	int max_v = 0; 
	for (int i = 1; i <= n; i++)
	{
		init();
		dfs(i);
		int cnt = 0; 
		for (int k = 1; k <= n; k++)
			if (visit[k] == 1)
				cnt++;
	
		ret[i]= cnt;
		if (max_v < cnt)
			max_v = cnt;
	}
	
	for (int i = 1; i <= n; i++)
		if(ret[i] == max_v)
		cout << i << " ";
	cout << endl;
}