#include <iostream>
#include <queue>
#define MAX 152
using namespace std;
int n;
char arr[MAX][MAX];
int visit[MAX][MAX][3];
int dst_x;
int dst_y;
int dst_flag;
struct mytype
{
	int x;
	int y; 
	int flag;
	int cnt;
};
queue<mytype> q;
int bfs(int i,int j, int flag)
{
	// flag = 1 (세로), 2(가로) 
	q.push(mytype{ i,j,flag,0 });
	visit[i][j][flag] = 1;
	while (!q.empty())
	{
		mytype here = q.front();
		int count = here.cnt;
		int x = here.x;
		int y = here.y;
	
		if (here.x == dst_x && here.y == dst_y && dst_flag == here.flag)
			return here.cnt;

		if (here.flag == 1)	// 세로 
		{
			int cnt = 0;
		
			cnt = 0; 
			for (int i = 0; i < 3; i++)	// 오른쪽 
			{
				if (x + i <= n && y + 1 <= n && arr[x + i][y + 1] != '1')
					cnt++;
			}
			if (y + 1 <= n && cnt == 3 && visit[x][y + 1][1] == 0) {
				visit[x][y + 1][1] = 1;
				q.push(mytype{ x, y + 1, 1 ,count + 1 });
			}

			cnt = 0;
			for (int i = 0; i < 3; i++)	// 왼쪽
			{
				if (x+i <= n && y-1> 0 && arr[x + i][y - 1] != '1')
					cnt++;
			}
			if (y - 1 > 0 && cnt == 3 && visit[x][y - 1][1] == 0) {
				visit[x][y - 1][1] = 1;
				q.push(mytype{ x, y - 1, 1,count + 1 });
			}
			if (x + 3 <= n && x + 1 <= n && arr[x + 3][y] != '1' &&visit[x + 1][y][1] == 0) {	// 아래
				visit[x + 1][y][1] = 1;
				q.push(mytype{ x + 1, y, 1,count + 1 });
			}

			if (x - 1 > 0 && arr[x - 1][y] != '1' && visit[x - 1][y][1] == 0) {	// 위 
				q.push(mytype{ x - 1, y, 1,count + 1 });
				visit[x - 1][y][1] = 1;
			}

			cnt = 0; 
			for (int i = 0; i < 3; i++)
			{
				if (x+i <= n && y+1 <= n && arr[x + i][y + 1] != '1')
					cnt++;

				if (x+i <=n && y-1 > 0 && arr[x + i][y - 1] != '1')
					cnt++;
			}
			if (x + 1 <= n && y - 1 > 0 && cnt == 6 && visit[x + 1][y - 1][2] == 0) {
				visit[x + 1][y - 1][2] = 1;
				q.push(mytype{ x + 1, y - 1, 2,count + 1 });
			}

		}
		else if (here.flag == 2)	//  가로
		{
			int cnt = 0;
			for (int i = 0; i < 3; i++)
			{
				if (x+1 <=n && y+i <= n && arr[x + 1][y + i] != '1')
					cnt++;
			}
			if (x + 1 <= n && cnt == 3 && visit[x + 1][y][2] == 0) {
				visit[x + 1][y][2] = 1;
				q.push(mytype{ x + 1, y, 2 ,count + 1 });
			}

			cnt = 0;
			for (int i = 0; i < 3; i++)
			{
				if (x-1> 0 && y+i <= n && arr[x - 1][y + i] != '1')
					cnt++;
			}
			if (x - 1 > 0 && cnt == 3 && visit[x - 1][y][2] == 0) {
				visit[x - 1][y][2] = 1;
				q.push(mytype{ x - 1, y, 2 ,count + 1 });
			}

			if (y + 3 <= n && y + 1 <= n && arr[x][y + 3] != '1' && visit[x][y + 1][2] == 0) {
				visit[x][y + 1][2] = 1;
				q.push(mytype{ x, y + 1, 2 ,count + 1 });
			}

			if (y - 1 > 0 && arr[x][y - 1] != '1' && visit[x][y - 1][2] == 0) {
				visit[x][y - 1][2] = 1;
				q.push(mytype{ x, y - 1, 2,count + 1 });
			}

			cnt = 0;
			for (int i = 0; i < 3; i++)
			{
				if (x+1 <=n && y+i <= n && arr[x + 1][y + i] != '1')
					cnt++;

				if (y + i <= n && x-1 > 0 && arr[x - 1][y + i] != '1')
					cnt++;
			}
			if (x - 1 > 0 && y + 1 <= n && cnt == 6 && visit[x - 1][y + 1][1] == 0) {
				visit[x - 1][y + 1][1] = 1;
				q.push(mytype{ x - 1, y + 1, 1,count + 1 });
			}
		}

		q.pop();
	}
	return 0; 
}
int main()
{
	bool flag = true;
	bool dst_f = true;
	cin >> n;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= n + 1; j++)
			arr[i][j] = '1';

	for (int i = 1; i <= n; i++)
	{
		char str[MAX];
		cin >> str;
		for (int j = 1; j <= n; j++)
			arr[i][j] = str[j-1];
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			 if (arr[i][j] == 'E' && dst_f == true) {
				dst_f = false;
				dst_x = i; 
				dst_y = j;
				if (arr[i + 1][j] == 'E')
					dst_flag = 1; 
				if (arr[i][j + 1] == 'E')
					dst_flag = 2;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		if (arr[i][j] == 'B' && flag == true) {
			flag = false;
			if (arr[i + 1][j] == 'B')
				cout << bfs(i, j, 1) << endl;
			if (arr[i][j + 1] == 'B')
				cout << bfs(i, j, 2) << endl;
	}
}