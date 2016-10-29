#include <iostream>
#define MAX 1001
#define INF 9876543211
#define min(a,b)a<b?a:b
using namespace std;
int s,n;
int arr[MAX][4] = { 0, };
int cache[MAX][MAX];
int batch(int start, int num)	// �ּҺ��, ���� ���� �ε���, ������ ���� ��ġ , ������ 
{
	if (start >= n) 
		return 0;
	
	int& ret = cache[start][num];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = start + 1; i <= n; i++) {
		int total = 0;
		total += ((arr[i][0] - arr[start][0]) * (arr[i][3] + (num + 1)*s));
		ret = min(ret, batch(i, num + 1) + total);
	}
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
				cache[i][j] = -1;
	cin >> n;
	cin >> s;
	arr[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][1] >> arr[i][2];
		arr[i][0] = arr[i][2] + arr[i-1][0];	// 2, 0 ���
		arr[i][3] = arr[i][1] + arr[i-1][3];	// 1, 3 �ð�
	}
	cout << batch(0, 0) << endl;
}