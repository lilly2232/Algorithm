#include <iostream>
#define MAX 1001
using namespace std;
int num;
int arr[MAX][MAX];
int visit[MAX];
int cnt = 0;
struct rect
{
	int x1;
	int y1;
	int x2;
	int y2;
};
rect rec[MAX];

bool check(int a,int b)
{
	if (rec[a].x2 < rec[b].x1 || rec[a].x1 > rec[b].x2 || rec[a].y2 < rec[b].y1 || rec[a].y1 > rec[b].y2)
		return false;
	if (rec[a].x1 < rec[b].x1 && rec[a].x2 > rec[b].x2 && rec[a].y1 < rec[b].y1 && rec[a].y2 > rec[b].y2)
		return false;
	if (rec[b].x1 < rec[a].x1 && rec[b].x2 > rec[a].x2 && rec[b].y1 < rec[a].y1 && rec[b].y2 > rec[a].y2)
		return false;
	return true;
}
void draw(int x)
{
	// °ãÄ¡³ª È®ÀÎ 
	visit[x] = 1;
	for (int v = 0; v <= num; v++)
	{
		if (check(x, v) == true && visit[v] == 0) {
			draw(v);
		}
	}
	return;
}
int main()
{
	bool flag = false;
	cin >> num;

	int x1, y1, x2, y2;
	rec[0] = { 0,0,0,0 };

	for (int k = 1; k <= num; k++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
	
		rec[k].x1 = x1;
		rec[k].y1 = y1;
		rec[k].x2 = x2;
		rec[k].y2 = y2;
	}

	int ret = 0;

	for (int i = 0; i <= num; i++)
		if (visit[i] == 0) 
		{
			draw(i);
			cnt++;
		}
		cout << cnt-1 << endl;
}