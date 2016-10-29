#include <iostream>
#define INF 987654321
using namespace std;
int n;
int arr[10][10];
int maxv = -INF;
//bool check(int x, int y )
//{
//	for (int i = 1; x - i >= 0 && y + i < n; i++)
//		if (arr[x - i][y + i] == 2)
//			return false;
//	for (int i = 1; x + i < n && y - i >= 0; i++)
//		if (arr[x + i][y - i] == 2)
//			return false;
//	for (int i = 1; x + i < n && y + i < n; i++)
//		if (arr[x + i][y + i] == 2)
//			return false;
//	for (int i = 1; x - i >= 0 && y - i >= 0; i++)
//		if (arr[x - i][y - i] == 2)
//			return false;
//	return true;
//}
bool check(int x, int y){
	for (int i = 1; x + i < n && y + i < n;i++)
		if (arr[x + i][y + i] == 2)
			return false;

	for (int i = 1; x - i >= 0 && x - i >= 0; i++)
		if (arr[x - i][y - i] == 2)
			return false;
	return true;
}
void sol(int cnt, int sop)
{
	if (sop + (2 * n - 1 - cnt) < maxv) return;
	if (cnt == n * 2 - 1)
	{
		if (maxv < sop) {
			maxv = sop;
		}
		return;
	}

	if (cnt < n) {
		for (int i = 0; i < cnt + 1; i++) {
			if (arr[i][cnt - i] == 1 && check(i, cnt - i) == true)
			{
				arr[i][cnt - i] = 2;
				sol(cnt + 1, sop + 1);
				arr[i][cnt - i] = 1;
			}
		}
		sol(cnt + 1, sop);
	}
	else
	{
		for (int i = cnt - n + 1; i < n; i++) {
			if (arr[i][cnt - i] == 1 && check(i, cnt - i) == true)
			{
				arr[i][cnt - i] = 2;
				sol(cnt + 1, sop + 1);
				arr[i][cnt - i] = 1;
			}
		}
		sol(cnt + 1, sop);
	}

	return;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	sol(0,0);
	cout << maxv << endl;
}