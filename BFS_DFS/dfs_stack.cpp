#include <iostream>
using namespace std;

int arr[11][11] = { 0, };
int visit[11] = { 0, };
int stack[11] = { 0, };
int pnt = -1;

void init(){

	pnt = -1;
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			arr[i][j] = 0;
	for (int i = 0; i < 11; i++)
		visit[i] = 0;
}
/*
void dfs(int num)
{
	visit[num] = 1;
	cout << num << " ";
	for (int i = 1; i < 11; i++)
		if (arr[num][i] == 1 && visit[i] != 1)
			dfs(i);
}
*/
void dfs(int num)
{
	int temp; 

	stack[++pnt] = num;

	while (pnt > -1)
	{
		temp = stack[pnt--];
		if (visit[temp] != 1)
		{
			cout << temp << " ";
			visit[temp] = 1;
		}

		for (int i = 10; i > 0; i--) {
			if (arr[temp][i] == 1){
				stack[++pnt] = i;
				arr[temp][i] = 0;
				arr[i][temp] = 0;
			}
		}
	}
}
int main()
{
	int n, start;
	int x, y;

	init();
	cin >> n >> start;

	while (!cin.eof())
	{
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(start);
}