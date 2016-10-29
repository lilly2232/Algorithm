#include <iostream>
#define MAX 102
using namespace std;
int arr[MAX][MAX];
int copyarr[MAX][MAX];
int visit[MAX][MAX];
int h, w;
void dfs(int x, int y, int k)
{
	arr[x][y] = k;
	visit[x][y] = 1;

	if (x+1 <= h && arr[x + 1][y] != 1 && visit[x + 1][y] == 0) {
		dfs(x + 1, y,k);
	}
	if (x-1 >= 0 && arr[x - 1][y] != 1&& visit[x - 1][y] == 0) {
		dfs(x - 1, y,k);
	}
	if (y + 1 <= w && arr[x][y+1] != 1 && visit[x][y+1] == 0) {
		dfs(x, y+1,k);
	}
	if (y - 1 >= 0 && arr[x][y-1] != 1 && visit[x][y - 1] == 0) {
		dfs(x, y-1,k);
	}
	return;
}
void erase(int x, int y)
{
	if (x + 1 <= h && arr[x + 1][y] == 1) {
		copyarr[x + 1][y] = 2; 
	}
	if (x - 1 >= 0 && arr[x - 1][y] == 1) {
		copyarr[x - 1][y] =2;
	}
	if (y + 1 <= w && arr[x][y + 1] == 1) {
		copyarr[x][y + 1] = 2;
	}
	if (y - 1 >= 0 && arr[x][y - 1] == 1) {
		copyarr[x][y - 1] = 2;
	}
	return;
}

int main()
{
	cin >> h >> w;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			cin >> arr[i][j];


	dfs(0, 0, 2);
	int k = 3;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (arr[i][j] == 0)
			{
				dfs(i, j, k);
				k++;
			}
	bool flag = true;
	int time = 0; 
	int pre = 0;
	while (1)
	{
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				copyarr[i][j] = arr[i][j];

		int cnt = 0; 
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				if (arr[i][j] == 2) 
					erase(i,j);

		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				arr[i][j] = copyarr[i][j];

		for (int i = 0; i <= h; i++)
			for (int j = 0; j <= w; j++)
				visit[i][j] = 0;

		dfs(0, 0, 2);
		time++;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++)
				if (arr[i][j] == 1)
					cnt++;
		}
		if (cnt == 0)
			break;
		pre = cnt;
	}
	cout << time << endl;
	cout << pre << endl;

}