//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <set>
//using namespace std;
//int dir[4][2] =
//{ 1,0,
//-1,0,
//0,1,
//0,-1 };
//char arr[6][6];
//int visit[6][6]; 
//set <vector<vector<bool> > > op;
//set<vector<pair<int, int > > > ans;
//vector<vector<bool > > visited;
//
//void dfs(int x, int y, int total, int lee , vector<pair<int,int>>& sel)// total수, 이다솜파수 'S'	
//{
//	visit[x][y] = true;
//	if (op.count(visited)) {
//		return;
//	}
//	else {
//		op.insert(visited);
//	}
//	if (total == 7)
//	{
//		/*if (lee >= 4)
//			ans.insert(sel);*/
//		int tmp = 0;
//		for (int i = 0; i < sel.size(); i++) {
//			int th = sel[i].first;
//			int tw = sel[i].second;
//			if (arr[th][tw] == 'S')
//				tmp++;
//		}
//		if (tmp >= 4) {
//			ans.insert(sel);
//		}
//		return;
//	}
//	for (int k = 0; k < sel.size(); k++)
//	{
//		for (int i = 0; i < 4; i++)
//		{
//			int next_x = dir[i][0] + sel[k].first;
//			int next_y = dir[i][1] + sel[k].second;
//			if (next_x > 0 && next_y > 0 && next_x < 6 && next_y < 6 && visited[next_x][next_y] == false)
//			{
//					sel.push_back({ next_x,next_y });
//					//visited[next_x][next_y] = 1;
//					dfs(next_x, next_y, total + 1, lee + 1, sel);
//				/*	if (arr[next_x][next_y] == 'S')
//						dfs(next_x, next_y, total + 1, lee + 1, sel);
//					else if (arr[next_x][next_y] == 'Y')
//						dfs(next_x, next_y, total + 1, lee, sel);*/
//					visited[next_x][next_y] = false;
//					sel.pop_back();
//
//			}
//		}
//	}
//	return;
//}
//
//int main()
//{
//	for (int i = 1; i < 6; i++)
//	{
//		char str[6];
//		cin >> str;
//		for (int j = 0; j < 5; j++)
//			arr[i][j + 1] = str[j];
//	}
//
//	vector<pair<int,int>> sel;
//	visited.resize(6, vector<bool>(6, false));
//
//	for (int i = 1; i < 6; i++)
//		for (int j = 1; j < 6; j++)
//		{
//			sel.push_back(make_pair(i, j));
//			dfs(i, j, 1,0, sel);
//		//	visited[i][j] = 1;
//		/*	if (arr[i][j] == 'S')
//				dfs(i, j, 1, 1, sel);
//			else
//				 dfs(i, j, 1, 0, sel);*/
//			sel.pop_back();
//			visit[i][j] = false;
//		}
//	cout << ans.size()<< endl;
//}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n = 5;
char board[5][5];
set <vector<vector<bool> > > op;
set<vector<pair<int, int > > > ans;
vector<vector<bool > > visited;

int mmove[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };


void dfs(int h, int w, int cnt, int sel, vector<pair<int, int > >& trail) {

	if (op.count(visited)) {
		return;
	}
	else {
		op.insert(visited);
	}
	if (cnt == 7) {

		if (sel >= 4) {
			ans.insert(trail);
		}
		return;
	}
	for (int k = 0; k < trail.size(); k++) {
		for (int i = 0; i < 4; i++) {

			int nextH = trail[k].first + mmove[i][0];
			int nextW = trail[k].second + mmove[i][1];
			if (nextH >= 0 && nextW >= 0 && nextH < 5 && nextW < 5 && visited[nextH][nextW] == false) {
				visited[nextH][nextW] = true;
				trail.push_back({ nextH, nextW });
				if (board[nextH][nextW] == 'S')
					dfs(nextH, nextW, cnt + 1, sel + 1, trail);
				else
					dfs(nextH, nextW, cnt + 1, sel, trail);
				visited[nextH][nextW] = false;
				trail.pop_back();
			}
		}
	}
}

int main() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}
	vector<pair<int, int > > trail;
	visited.resize(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = true;
			trail.push_back({ i,j });
			if (board[i][j] == 'S')
				dfs(i, j, 1, 1, trail);
			else
				dfs(i, j, 1, 0, trail);
			visited[i][j] = false;
			trail.pop_back();
		}
	}
	cout << ans.size() << endl;
}