//#include <iostream>
//using namespace std;
//int dir[4][2] =
//{ 
//	1,0,
//	-1,0,
//	0,1,
//	0,-1 
//};
//char arr[7][7];
//bool visit[1 << 27];
//int dfs(int cnt, int lee, int index)// total수, 이다솜파수 'S'	
//{	
//	if (cnt == 7)
//	{
//		if (lee >= 4)
//			return 1;
//		else
//			return 0;
//	}
//	int ret = 0; 
//	for (int k = 0; k < 25; k++) {
//		if (index & (1 << k))
//		{
//			int x = k / 5;
//			int y = k % 5;
//			if (k == 0) {
//				x = 0; y = 0;
//			} else {
//				 x = k / 5;
//				 y = k % 5;
//			}
//	
//			for (int i = 0; i < 4; i++)
//			{
//				int next_x = dir[i][0] + x;
//				int next_y = dir[i][1] + y;
//
//				int next = (1 << ((next_x) * 5 + next_y));
//
//				if (next_x >= 0 && next_y >= 0 && next_x < 5 && next_y < 5 && visit[next | index] == false)
//				{
//
//					visit[next | index] = true;
//					if (arr[next_x][next_y] == 'S')
//						ret += dfs(cnt + 1, lee + 1, next | index);
//					else if (arr[next_x][next_y] == 'Y')
//						ret += dfs(cnt + 1, lee, next | index);
//				}
//			}
//		}
//	}
//	return ret;
//}
//int main()
//{
//	for (int i = 0; i < 5; i++)
//	{
//		char str[6];
//		cin >> str;
//		for (int j = 0; j < 5; j++)
//			arr[i][j] = str[j];
//	}
//	int ret = 0; 
//	for (int i = 0; i < 5; i++)
//		for (int j = 0; j < 5; j++)
//		{
//			int idx = (1 << (i*5 + j));
//			visit[idx] = true;
//			if (arr[i][j] == 'S')
//				ret += dfs(1, 1, idx);
//			else
//				ret+= dfs( 1, 0, idx);
//
//		}
//
//	cout << ret << endl;
//}

#include <iostream>
using namespace std;

int dir[4][2] =
{
	1,0,
	-1,0,
	0,1,
	0,-1
};
char arr[6][6];
bool visit[1 << 26];
int dfs(int cnt, int lee, int index) 
{
	if (cnt == 7)
	{
		if (lee >= 4)
			return 1;
		else
			return 0;
	}

	int ret = 0;
	for (int i = 1; i < 26; i++)
	{
		if (index & (1 << i)) {
			int x = (i/5) +1;
			int y = i%5;
			if (y == 0) // 좌표변환의 문제 
			{
				y = 5;
				x = x - 1;
			}

			for (int i = 0; i < 4; i++) {
				int next_x = dir[i][0] + x;
				int next_y = dir[i][1] + y;
		
				int next = ((next_x - 1)*5 + next_y);
			
				if (next_x > 0 && next_y > 0 && next_x < 6 && next_y < 6 && visit[(1<<next)| index] == 0)
				{
					visit[(1 << next) | index] = true;
					if (arr[next_x][next_y] == 'S')
						ret += dfs(cnt + 1, lee + 1, ((1 << next) | index));
					else if (arr[next_x][next_y] == 'Y')
						ret += dfs(cnt + 1, lee, ((1 << next) | index));
				}
			}
		}
	}
	return ret;
}
int main()
{
	for (int i = 1; i < 6; i++)
	{
		char str[7];
		cin >> str;
		for (int j = 0; j < 5; j++)
			arr[i][j+1] = str[j];
	}
	int ret = 0;
	for (int i = 1; i < 6; i++)
		for (int j = 1; j < 6; j++)
		{
			int idx = (i-1)*5 +j;

			visit[1 << idx] = 1;
			if (arr[i][j] == 'S')
				ret += dfs(1, 1, 1 << idx);
			else
				ret += dfs(1, 0, 1 << idx);
		}
	cout << ret << endl;
}