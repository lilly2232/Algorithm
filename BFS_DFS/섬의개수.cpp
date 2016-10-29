#include <iostream>
#define MAX 52
using namespace std;
int arr[MAX][MAX];
int visit[MAX][MAX];
int Direction[8][2] =
{
	-1,0,
	1,0,
	0,-1,
	0,1,
	-1,-1,
	1,-1,
	-1,1,
	1,1
};
int num_s = 0;
void init(int w, int h)
{
	num_s = 0;
	for (int i = 0; i <= h+1; i++)
		for (int j = 0; j <= w + 1; j++) {
			arr[i][j] = 0;
			visit[i][j] = 0;
		}
}
void dfs(int x, int y)
{
	visit[x][y] = 1;
	for (int i = 0; i < 8; i++) {
		int here_x = x + Direction[i][0];
		int here_y = y + Direction[i][1];

		if (visit[here_x][here_y] == 0 && arr[here_x][here_y] == 1)
			dfs(here_x, here_y);
	}

}
int main()
{
	while (1)
	{
		int w, h;
		cin >> w >> h;
		if (w == 0 && h == 0)
				break;
		init(w,h);
		for (int i = 1; i <= h; i++) 
			for (int j = 1; j <= w; j++)
				cin >> arr[i][j];
		
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
				if (visit[i][j] == 0 && arr[i][j] == 1) {
					dfs(i,j);
					num_s++;
				}
		cout << num_s << endl;
	}
}