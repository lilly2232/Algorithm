#include <iostream>
#define MAX 122

using namespace std;
int arr[MAX][MAX] = { 0, };
int n;
int f_total = 0;

struct Point
{
	int x;
	int y;
};
int pow(int a, int b)
{
	int total = 1;
	for (int i = 0; i < b; i++)
		total *= a;
	return total;
}
Point pt[4];
void dfs(int x, int y, Point dir, int total)
{
	arr[x][y] = 2;
	total++;
	
	if (arr[x + dir.x][y + dir.y] == 2)		// 이미 왔던 길
	{
		if (total > f_total) 
			f_total = total;
		arr[x][y] = 0;
		return;
	}
	if (arr[x + dir.x][y + dir.y] == 0)		// 갈 수 있으면 그 방향으로 직진 
		dfs(x + dir.x, y + dir.y, dir, total);
	else if (arr[x + dir.x][y + dir.y] == 1)	// 장애물 혹은 벽 , 방향 전환 
	{
		if (dir.x == 0)   // 좌, 우
		{
			if (arr[x + pt[0].x][y + pt[0].y] == 0)		// 상
				dfs(x + pt[0].x, y + pt[0].y, pt[0], total);
			if (arr[x + pt[1].x][y + pt[1].y] == 0)		// 하 
				dfs(x + pt[1].x, y + pt[1].y, pt[1], total);
			if (arr[x + pt[2].x][y + pt[2].y] == 2 || arr[x + pt[3].x][y + pt[3].y] == 2)
			{
				if (total > f_total)
					f_total = total;
				arr[x][y] = 0;
				return;
			}
		}
		else if (dir.y == 0)	// 상, 하
		{
			if (arr[x + pt[2].x][y + pt[2].y] == 0)	// 좌 
				dfs(x + pt[2].x, y + pt[2].y, pt[2], total);
			if (arr[x + pt[3].x][y + pt[3].y] == 0)	// 우 
				dfs(x + pt[3].x, y + pt[3].y, pt[3], total);
			if (arr[x + pt[0].x][y + pt[0].y] == 2 || arr[x + pt[1].x][y + pt[1].y] == 2)
			{
				if (total > f_total)
					f_total = total;
				arr[x][y] = 0;
				return;
			}
		}
	}

	arr[x][y] = 0;
}
int main()
{
	pt[0].x = -1;	// 상
	pt[0].y = 0;
	pt[1].x = 1;	// 하 
	pt[1].y = 0;
	pt[2].x = 0;
	pt[2].y = -1;	// 좌	
	pt[3].x = 0;
	pt[3].y = 1;	// 우 

	int b;
	cin >> n >> b;

	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++)
		{
			if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	for (int i = 0; i < b; i++)
	{
		char str[120];
		cin >> str;

		int m = str[0] - 64;
		int n = 0;
		int len;
		int j;

		for (j = 1; str[j] != '\0'; j++) {};
		len = j - 1;
		for (int j = 1; j <= len; j++)
			n += ((str[j] - 48) *pow(10, len - j));

		arr[n][m] = 1;
	}

	if (arr[1+ pt[3].x][1+pt[3].y] == 0)
		dfs(1, 1, pt[3], 0);
	if (arr[1 + pt[1].x][1 + pt[1].y] == 0)
		dfs(1, 1, pt[1], 0);

	cout << f_total << endl;
}