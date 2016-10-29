#include <iostream>
#define INF 987654321
#define min(a,b)a<b?a:b
using namespace std;

int arr[100][1001] = { 0, };
int sale = 0;
int buy_code[5][3] = { 0, };
int buy = 0;
int cache[100][6][6][6][6][6];

int bargain(int index, int a, int b, int c, int d, int e)
{
	if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0)
		return INF;

	if (index >= sale) {
		return a * buy_code[0][2] + b * buy_code[1][2] + c * buy_code[2][2] + d * buy_code[3][2] + e * buy_code[4][2];
	}
	int& ret = cache[index][a][b][c][d][e];
	if (ret != -1) return ret;
	ret = INF;
	ret = min(ret, bargain(index + 1, a, b, c, d, e));
	ret = min(ret, bargain(index, a - arr[index][buy_code[0][0]], b - arr[index][buy_code[1][0]], c - arr[index][buy_code[2][0]], d - arr[index][buy_code[3][0]], e - arr[index][buy_code[4][0]])+arr[index][1000]);

	return ret;
}
int main()
{
	int sale_num;
	cin >> sale_num;

	for (int i = 0; i < 100; i++)
		for (int a = 0; a < 6; a++)
			for (int b = 0; b < 6; b++)
				for (int c = 0; c < 6; c++)
					for (int d = 0; d < 6; d++)
						for (int e = 0; e < 6; e++)
							cache[i][a][b][c][d][e] = -1;

	for (int i = 0; i < sale_num; i++)
	{
		int num, p;
		cin >> num;
		while (num--)
		{
			int c, k;
			cin >> c >> k;
			arr[sale][c] = k;
		}
		cin >> p;
		arr[sale][1000] = p;
		sale++;
	}

	int buy_num;
	cin >> buy_num;

	
	for (int i = 0; i < buy_num; i++)
		cin >> buy_code[i][0] >> buy_code[i][1] >> buy_code[i][2];	// 0: 코드 1: 개수 2: 가격

	cout << bargain(0, buy_code[0][1], buy_code[1][1], buy_code[2][1], buy_code[3][1], buy_code[4][1]) << endl;

}