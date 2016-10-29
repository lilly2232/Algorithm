#include <iostream>
#define MAX 51
#define INF 987654321
using namespace std;

// 플로이드 외샬로 풀어보장
int dis[MAX][MAX];
int result[MAX];
int index = 0;

int main()
{
	int num;
	cin >> num;
	for (int i = 0; i <= num; i++)
		for (int j = 0; j <= num; j++) 
			dis[i][j] =INF;

	for (int i = 0; i <= num; i++)
		dis[i][i] = 0;

	while (1)
	{
		int x, y;
		cin >> x >> y;
		if (x == -1 && y == -1)
			break;
		dis[x][y] = 1;
		dis[y][x] = 1;
	}
	for (int k = 1; k <= num; k++)
		for (int i = 1; i <= num; i++)
			for (int j = 1; j <= num; j++)
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];

	for (int i = 1; i <= num; i++)
	{
		dis[i][0] = dis[i][1];
		for (int j = 2; j <= num; j++)
			if (dis[i][0] < dis[i][j])
				dis[i][0] = dis[i][j];
	}
	int max_value = INF;
	for (int i = 1; i <= num; i++)
	{
		if (dis[i][0] < max_value)
		{
			index = 0;
			result[index++] = i;
			max_value = dis[i][0];
		}
		else if (dis[i][0] == max_value)
		{
			result[index++] = i;
		}
	}
	cout << max_value << " " << index << endl;
	for (int i = 0; i < index; i++)
		cout << result[i] << " ";
	cout << endl;
}