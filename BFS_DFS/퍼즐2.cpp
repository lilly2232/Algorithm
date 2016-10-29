#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
set <vector<int> > state;
vector<int>  start;
vector<int>  ans;

struct mytype
{
	int x;
	int y;
	int cnt;
	vector<int> arr;
};
int dir[4][2] = {
	0,1,
	0,-1,
	1,0,
	-1,0
};
int total = INF;
bool check(vector<int> test)
{
	for (int i = 0; i < 9; i++)
		if (test[i]!= ans[i])
			return false;
	return true;
}

int bfs()
{

	queue<mytype> q;
	int sx = 0;
	int sy = 0;
	for (int i = 0; i < 9; i++)
		if (start[i] == 0){ sx = i / 3; sy = i % 3;}

	q.push(mytype{ sx,sy,0,start});
	state.insert(start);

	while (!q.empty())
	{
		mytype p = q.front();

		if (check(p.arr) == true)
			return p.cnt;

		int x = p.x;
		int y = p.y;
		int cnt = p.cnt;
		int temp[3][3];

		for (int i = 0; i < 4; i++) {
			int next_x = dir[i][0] + x;
			int next_y = dir[i][1] + y;
			int idx = 0;

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					temp[i][j] = p.arr[idx++];

		if (next_x >= 0 && next_y >= 0 && next_x < 3 && next_y < 3) {
				int t;
				t = temp[next_x][next_y];
				temp[next_x][next_y] = temp[x][y];
				temp[x][y] = t;

				vector<int> onearr = vector<int>(9);
				idx = 0; 
				for (int i = 0; i < 3; i++)
					for (int j = 0; j < 3; j++)
						onearr[idx++] = temp[i][j];

				if (!state.count(onearr))
				{
					state.insert(onearr);
					q.push(mytype{ next_x,next_y,cnt+1, onearr });
				}
			}
		}
		q.pop();
	}
	return -1;
}
int main()
{
	start = vector<int>(9);
	ans = vector<int>(9);
	int cnt = 1;

	for (int i = 0; i < 9; i++)
		cin >> start[i];

	for (int i = 0; i < 8; i++)
		ans[i] = i + 1;
	ans[8] = 0;	
	cout << bfs() << endl;

}