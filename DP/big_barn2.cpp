#include <iostream>
#define MAX 1111
#define INF 987654321
#define min(a,b)a<b?a:b
#define max(a,b)a>b?a:b
using namespace std;
int arr[MAX][MAX];
int n;
int max_v = -1;
int cache[MAX][MAX];

int big_barn(int x, int y)//  f(x, y) = x, y에서 시작하는 가장 큰 정사각형의 길이
{
	int& ret = cache[x][y];
	if (ret != -1)return ret;

	if (x > n || y > n || arr[x][y] == 1)
		return 0;

	ret = INF;

	ret = min(ret, big_barn(x + 1, y) + 1);
	ret = min(ret, big_barn(x, y + 1) + 1);
	ret = min(ret, big_barn(x + 1, y + 1) + 1);
	
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	int t_num;
	cin >> n >> t_num;
	for (int i = 0; i < t_num; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}

	int max_value = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			max_value = max(max_value, big_barn(i, j));
		}
	cout << max_value << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	for (int i = 1; i <= n ; i++) {
		for (int j = 1; j <= n ; j++)
			cout << cache[i][j] << " ";
		cout << endl;
	}
}

#include <iostream>
#define MAX 1111
#define INF 987654321
#define min(a,b)a<b?a:b
#define max(a,b)a>b?a:b
using namespace std;
int arr[MAX][MAX];
int n;
int max_v = -1;
int cache[MAX][MAX];

int big_barn(int x, int y)//  f(x, y) = x, y에서 시작하는 가장 큰 정사각형의 길이
{
	int& ret = cache[x][y];
	if (ret != -1)return ret;

	if (x > n || y > n || arr[x][y] == 1)
		return 0;

	ret = INF;

	ret = min(ret, big_barn(x + 1, y) + 1);
	ret = min(ret, big_barn(x, y + 1) + 1);

	if (arr[x + ret - 1][y + ret - 1] == 0)
		return ret;
	else
		return ret = ret - 1;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;
	int t_num;
	cin >> n >> t_num;
	for (int i = 0; i < t_num; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}

	int max_value = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			max_value = max(max_value, big_barn(i, j));
		}
	cout << max_value << endl;
}