#include <iostream>
using namespace std;
int arr[20][20];
int visit[20][20];
int cnt = 0; 
int dfs(int x, int y)// 시작 좌표, 검은 흰, 
{
	int i;
	for (i = 0; y + i < 20 && arr[x][y + i] == arr[x][y]; i++) {}
	if (i == 5) {
		if (y - 1 == 0)
			return i;
		if (y - 1 > 0 && arr[x][y - 1] != arr[x][y])
			return i;
	}
	for (i = 0; x + i < 20 && arr[x + i][y] == arr[x][y]; i++) {}
	if (i == 5) {
		if (x - 1 == 0)
			return i;
		if (x - 1 > 0 && arr[x - 1][y] != arr[x][y])
			return i;
	}
	for (i = 0; x + i < 20 && y + i < 20 && arr[x + i][y + i] == arr[x][y]; i++) {}
	if (i == 5)
	{
		if (x - 1 == 0 || y - 1 == 0)
			return i;
		if (x - 1 > 0 && y - 1 > 0 && arr[x - 1][y - 1] != arr[x][y])
			return i;

	}

	for (i = 0; x - i > 0 && y + i < 20 && arr[x - i][y + i] == arr[x][y]; i++) {}
	if (i == 5 && x+1 < 20 && y-1 > 0 && arr[x+1][y-1] != arr[x][y])
		if (i == 5)
		{
			if ( x+1 == 20 || y-1 == 0)
				return i;
			if (x - 1 > 0 && y - 1 > 0 && arr[x - 1][y - 1] != arr[x][y])
				return i;

		}
	return -1;
}
int main()
{
	bool flag = false;
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= 19; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= 19 && flag == false; i++)
		for (int j = 1; j <= 19 && flag == false; j++)
		{
			if (arr[i][j] == 1 || arr[i][j] == 2) 
			{
				int ret = dfs(i, j);
				if (ret == 5) 
				{
					flag = true;
					cout << arr[i][j] << endl;
					cout << i << " " << j << endl;	// 가로 세로 
				}
			}
		}
	if (flag == false)
		cout << "0" << endl;
}