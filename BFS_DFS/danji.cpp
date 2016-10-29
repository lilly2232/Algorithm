#include <iostream>
#define MAX 27
using namespace std;
int arr[MAX][MAX];
int housenum[MAX*MAX];
int num;
int cnt = 2;
int dir[4][2] = 
{
	-1,0,
	1,0,
	0,-1,
	0,1
};
int val = 0;
void dfs(int x, int y, int cnt)
{
	arr[x][y] = cnt;
	val++;
	for (int i = 0; i < 4; i++)
	{
		int next_x = dir[i][0] + x;
		int next_y = dir[i][1] + y;
		if (next_x > 0 && next_y > 0 && next_x < num + 1 && next_y < num + 1 && arr[next_x][next_y] == 1)
			dfs(next_x, next_y, cnt);
	}
}
int main()
{
	cin >> num; 
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			if (arr[i][j] == 1) {
				val = 0; 
				dfs(i, j, cnt);
				housenum[cnt] = val;
				cnt++;
			} 

	for (int i = 2; i < cnt-1; i++)
		for (int j = i + 1; j < cnt; j++)
			if (housenum[i] > housenum[j])
			{
				int temp = housenum[j];
				housenum[j] = housenum[i];
				housenum[i] = temp;
			}
	cout << cnt - 2 << endl;
	for (int i = 2; i < cnt; i++)
		cout << housenum[i] << endl;
}