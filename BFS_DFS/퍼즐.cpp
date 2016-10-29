#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;
#define INF 987654321
set <vector<vector<int> >> state;
vector<vector<int>> s;
struct mytype 
{
	int x;
	int y;
	int cnt;
	vector<vector<int>> arr;
};
vector<vector<int>> ans;
int dir[4][2] = {
	0,1,
	0,-1,
	1,0,
	-1,0
};
int total = INF;
bool check(vector<vector<int>> test)
{

	for (int i = 0; i < test.size(); i++)
		for (int j = 0; j < test[i].size(); j++)
			if (test[i][j] !=ans[i][j] )
				return false;
	return true;
}
//void dfs(int x, int y, int cnt)
//{
//	////cout << cnt << endl;
//	//for (int i = 0; i < 3; i++){
//	//	for (int j = 0; j < 3; j++) 
//	//		cout << arr[i][j] << " ";
//	//	cout << endl;
//
//	//	}
//	//cout << endl;
//	//if (x == 2 && y == 2)
//	//{
//	//	if (check() == true && total > cnt) 
//	//	{
//	//		total = cnt;
//	//		return;
//	//	}
//
//	//}
//	//if (state.find(arr))
//	//	return;
//	//else
//	//	state.insert(arr,cnt);
//
//	//for (int i = 0; i < 4; i++)
//	//{
//	//	int next_x = dir[i][0] + x;
//	//	int next_y = dir[i][1] + y;
//
//	//	
//	//	if (next_x > 0 && next_y > 0 && next_x < 3 && next_y < 3)
//	//	{ 
//	//		int temp; 
//	//		temp = arr[next_x][next_y];
//	//		arr[next_x][next_y] = arr[x][y];
//	//		arr[x][y] = temp;
//	//		dfs(next_x, next_y, cnt + 1);
//
//	//		temp = arr[next_x][next_y];
//	//		arr[next_x][next_y] = arr[x][y];
//	//		arr[x][y] = temp;
//	//	}
//	//}
//}
int bfs(int sx, int sy)
{

	queue<mytype> q;
	q.push(mytype{ sx,sy,0,s });
	state.insert(s);

	while (!q.empty())
	{
	
		mytype p = q.front();

		if (check(p.arr) == true)
			return p.cnt;

		int x = p.x;
		int y = p.y;
		int cnt = p.cnt;
	
		vector<vector<int>> temparr = vector<vector<int>>(3, vector<int>(3));

		for (int i = 0; i < 4; i++) {
			int next_x = dir[i][0] + x;
			int next_y = dir[i][1] + y;
			vector<vector<int>> temparr = vector<vector<int>>(3, vector<int>(3));

			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					temparr[i][j] = p.arr[i][j];

 			if (next_x >= 0 && next_y >= 0 && next_x < 3 && next_y < 3){
				int temp;
				temp = temparr[next_x][next_y];
				temparr[next_x][next_y] = temparr[x][y];
				temparr[x][y] = temp;

				if (!state.count(temparr)) 
				{
					state.insert(temparr);
					q.push(mytype{ next_x,next_y,cnt + 1, temparr });
				}
			}
		}
		q.pop();
	}
	return -1;
}
int main()
{
	s = vector<vector<int>>(3, vector<int>(3));
	ans = vector<vector<int>>(3, vector<int>(3));
	int cnt = 1; 
	int start_x, start_y;
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++)
		{
			ans[i][j] = cnt++;
			cin >> s[i][j];
			if (s[i][j] == 0)
			{
				start_x = i;
				start_y = j;
			}
		}
	ans[2][2] = 0;
	cout << bfs(start_x, start_y) << endl;

}