#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > arr; 
vector<int> visit;

// N의 크기가 100,000  --> 2차원 배열로 사용하기엔 한계가 있음, vector 사용하기  조건 : (2 ≤ N ≤ 100,000, 1 ≤ M ≤ 500,000)
// List로 vector // List로 탐색하는  문제 

void dfs(int here)
{
	visit[here] = 1;
	cout << here << " ";

	for (int i = 1; i < arr[here].size(); i++)
	{
		int next = arr[here][i];
		if (visit[next] == 0) {
			dfs(next);
		}
	
	}
	
}
int main()
{
	int n;
	int m;

	cin >> n >> m;
	arr = vector<vector<int> >(n+1, vector<int>(1, 0));
	visit = vector<int>(n+1, 0);

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		arr[x].push_back(y);
		arr[y].push_back(x);

	}
	for (int i = 1; i < n+1; i++)
		sort(arr[i].begin(), arr[i].end());

	dfs(1);
	cout << endl;
}

