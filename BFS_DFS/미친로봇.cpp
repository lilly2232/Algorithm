#include <iostream>
#define MAX 31
using namespace std;
int Direction[4][2] =
{
	0,1,		// 동
	0,-1,       // 서
	1,0,        // 남
	-1,0        // 북
};
int num;
int visit[MAX][MAX];
double score[4];
double f_total = 0.0;

void dfs(int x, int y, int cnt, double total)
{
	if (cnt == num) {
		f_total += total;
		visit[x][y] = 0;
		return;
	}
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int here_x = x + Direction[i][0];
		int here_y = y + Direction[i][1];

		if (visit[here_x][here_y] == 0)
			dfs(here_x, here_y, cnt + 1, total*score[i]);
	}
	visit[x][y] = 0;
}

int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			visit[i][j] = 0;
	cin >> num;
	for (int i = 0; i < 4; i++) {
		double a;
		cin >> a;
		score[i] = (a / 100.0);
	}
	dfs(15, 15, 0, 1.0);

	//cout << f_total << endl;
	printf("%.10lf\n", f_total);	// 절대 / 상대 오차는 10 - 9 까지 허용한다. ->printf로 출력
}