#include <iostream>
#define MAX 102
#define INF 987654321
using namespace std;

int arr[MAX][MAX];
int visit[MAX];
int fin;
int num;
int min_value = INF;
void dfs(int v, int cnt)
{
	if (cnt > min_value)	// 가지치기 
		return;
	if (v == fin) {
		if (cnt < min_value)
			min_value = cnt;
		return;
	}
	visit[v] = 1; // 위치가 중요하다 
	for (int i = 1; i <= num; i++)
	{
		if (visit[i] == 0) {
			if (arr[v][i] == 1)
				dfs(i, cnt);
			else if(arr[v][i] == 2)
				dfs(i, cnt + 1);
		}
	}
	visit[v] = 0;
}


int main()
{
	int start;
	int n, val;
	cin >> num >> start >> fin;

	for (int i = 1; i <= num; i++)
	{
		cin >> n; 
		for (int j = 1; j <= n; j++)
		{
			cin >> val;
			if (j == 1)
				arr[i][val] = 1;
			else
				arr[i][val] = 2;
		}
	}
	dfs(start, 0);
	if (min_value == INF)
		cout << "-1" << endl;
	else
		cout << min_value<< endl;
}