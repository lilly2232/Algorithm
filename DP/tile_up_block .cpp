#include <iostream>
#define MAX 10001
#define max(a,b) a>b?a:b
using namespace std;
int arr[MAX][3];
int cache[MAX];
int n;

int tile_up(int start)
{
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < n; i++)
		if (start == -1 || (arr[i][2] == -1 &&arr[start][0] <= arr[i][0] && arr[start][1] <= arr[i][1])) {
			arr[i][2] = 1;
			ret = max(ret, 1 + tile_up(i));
			arr[i][2] = -1;
		}
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 0; i < MAX; i++) {
		arr[i][2] = -1;
		cache[i] = -1;
	}
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];

	cout << tile_up(-1) - 1 << endl;

}