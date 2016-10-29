#include <iostream>
#include <queue>
#define MAX 102
#define INF 987654321
using namespace std;
int arr[MAX][MAX];
int visit[MAX][MAX];
int num;

int dir[4][2] =
{
	0,1,
	0,-1,
	1,0,
	-1,0
};
bool bfs(int min, int max)
{
	queue<pair<int, int> > mqueue;
	if (arr[1][1] <= max && arr[1][1] >= min) {
		mqueue.push(pair<int, int> {1, 1});
		visit[1][1] = 1;
	}
	while (!mqueue.empty())
	{
		pair<int,int> val = mqueue.front();
		int x = val.first;
		int y = val.second;
		mqueue.pop();

		if (x == num && y == num)
			return true;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dir[i][0];
			int next_y = y + dir[i][1];
			if (next_x > 0 && next_x <= num
				&& next_y > 0 && next_y <= num
				&& arr[next_x][next_y] >= min && arr[next_x][next_y] <= max && visit[next_x][next_y] == 0) {
				visit[next_x][next_y] = 1;
				mqueue.push(pair<int, int>{next_x, next_y});
			}
		}
	
	}
	return false;
}
void init()
{
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++)
			visit[i][j] = 0;
}
int main()
{
	int min = INF;
	int max = -INF;
	int ret = INF;

	cin >> num;
	for (int i = 1; i <= num; i++)
		for (int j = 1; j <= num; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > max)
				max = arr[i][j];
			if (arr[i][j] < min)
				min = arr[i][j];
		}
	for (int i = min; i <= max; i++)
		for (int j = i; j <= max; j++)
		{
			if (j - i < ret)
			{
				init();
				if (bfs(i, j) == true)
					ret = (j - i);
			}
		}

	cout << ret << endl;

}