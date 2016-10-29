#include <iostream>
using namespace std;
int arr[27][27];
int visit[27][27];
int result[1000];
int index = 0;
int dir[4][2] =
{
	0,1,
	0,-1,
	1,0,
	-1,0
};
int dfs(int x, int y)
{
	visit[x][y] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dir[i][0];
		int next_y = y + dir[i][1];
		if (arr[next_x][next_y] == 1 && visit[next_x][next_y] == 0)
			ret += dfs(next_x, next_y);
	}
	return ret;
}
void sort()
{
	for (int i = 0; i < index; i++)
		for (int j = i + 1; j < index; j++)
			if (result[i] > result[j])
			{
				int temp = result[i];
				result[i] = result[j];
				result[j] = temp;
			}
}
int main()
{
	int num;
	cin >> num;

	for (int i = 0; i <= num + 1; i++)
		for (int j = 0; j <= num + 1; j++) {
			visit[i][j] = 0;
			arr[i][j] = 0;
		}
	for (int i = 1; i <= num; i++)
	{
		char str[27];
		cin >> str;
		for (int j = 0; j < num; j++)
			if (str[j] == '0')
				arr[i][j+1] = 0;
			else
				arr[i][j+1] = 1;

	}
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			if ( visit[i][j] == 0 && arr[i][j] == 1) 
			{
				result[index++] =  dfs(i, j) ;
			}

	sort();
	cout << index << endl;
	for (int i = 0; i < index; i++)
		cout << result[i] << endl;
}