#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 81
#define max(a,b) a>b?a:b
using namespace std;

int m;
vector<pair<int, int> > arr;
int make_lse;
int cache_max[MAX][MAX];
int cache[MAX][MAX][MAX];

int max_lse(int index, int end)
{
	if (index >= m)
		return 0;
	int& ret = cache_max[index][end];
	if (ret != -1)
		return ret;

	if (end > arr[index].first)
		ret = max(ret,max_lse(index + 1, end));
	else 
		ret = max(max_lse(index + 1, arr[index].second)+1, max_lse(index + 1, end));
	return ret;
}
int lse(int index, int end, int num)
{
	if (num == make_lse)
		return 1;

	if (index >= m)
		return 0;
	int& ret = cache[index][end][num];
	if (ret != -1)
		return ret;
	
	if (end > arr[index].first)
		ret = lse(index + 1, end, num);
	else
		ret = lse(index + 1, arr[index].second ,num+1) + lse(index + 1, end, num);
	return ret;
}
int main()
{

	cin >> m;
	arr = vector< pair<int, int> >(m);
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache_max[i][j] = -1;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			for (int k = 0; k < MAX; k++)
				cache[i][j][k] = -1;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (x < y) {
			arr[i].first = x; arr[i].second = y;
		}
		else {
			arr[i].first = y; arr[i].second = x;
		}
	
	}
	sort(arr.begin(), arr.end());

	make_lse = max_lse(0, 0);
	cout << m - make_lse << " ";
	cout << lse(0, 0, 0) << endl; 

}