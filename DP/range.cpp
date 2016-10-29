#include <iostream>
#define min(a,b)a<b?a:b
#define MAX 255
#define  INF 987654321
using namespace std;
int arr[MAX][MAX];
int cache[MAX][MAX];

int range_arr[MAX] = { 0, };
int n;
int range(int x, int y)
{
	if (x > n || y > n || arr[x][y] == 0)
		return 0;
	int& ret = cache[x][y];
	if (ret != -1)   return ret; 
	
	ret = INF;
	
	ret = min(ret, range(x, y+1)+1);
	ret = min(ret,range(x+1, y)+1);

	if (arr[x + ret - 1][y + ret - 1] == 1)
		return ret;
	else 
			return ret = ret -1;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char str[MAX];
		cin >> str;
		for (int k = 0; str[k] != '\0'; k++) 
			arr[i][k+1] = str[k] - 48;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			if (arr[i][j] != 0) 
				 range(i, j);			
	bool cnt = false;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int ret = cache[i][j];
			for (int k = 2; k <= ret; k++) {
				range_arr[k]++;
				cnt = true;
			}
		}
	if (cnt == true) {
		for (int i = 2; i <= n; i++)
			if (range_arr[i] != 0)
				cout << i << " " << range_arr[i] << endl;
	} else
		cout << "0" << endl;
}
