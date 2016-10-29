//#include <iostream>
//#define INF 987654321
//#define MAX 6*6*6*6*6
//#define min(a,b)a<b?a:b
//using namespace std;
//
//int arr[100][1001] = { 0, };
//int sale = 0;
//int buy_code[5][3] = { 0, };
//int buy = 0;
//int cache[100][MAX];
//
//int pow(int a, int b)
//{
//	int total = 1;
//	for (int i = 1; i < b; i++)
//		total *= a;
//	return total;
//}
//int bargain(int index, int buy[5][3])
//{
//	for (int i = 0; i < 5; i++)
//		if (buy[i][1] < 0)
//			return INF;
//
//	if (index >= sale) {
//		int total = 0;
//		for (int i = 0; i < 5; i++)
//			total += (buy[i][2] * buy[i][1]);
//		return total;
//	}
//	int value = 0;
//
//	for (int i = 0; i < 5; i++)
//		value += (buy[i][1]) * pow(6,5-i);
//
//	int& ret = cache[index][value];
//	if (ret != -1) return ret;
//	ret = INF;
//	ret = min(ret, bargain(index + 1, buy));
//
//	int new_buy[5][3];
//	for (int i = 0; i < 5; i++)
//		for (int j = 0; j < 3; j++)
//			new_buy[i][j] = buy[i][j];
//
//	for (int i = 0; i < 5; i++)
//	{
//		new_buy[i][1] -= arr[index][new_buy[i][0]];
//	}
//	ret = min(ret, bargain(index, new_buy) + arr[index][1000]);
//
//	return ret;
//}
//int main()
//{
//	int sale_num;
//	cin >> sale_num;
//
//	for (int i = 0; i < 100; i++)
//		for (int j = 0; j < MAX; j++)
//			cache[i][j] = -1;
//
//	for (int i = 0; i < sale_num; i++)
//	{
//		int num, p;
//		cin >> num;
//		while (num--)
//		{
//			int c, k;
//			cin >> c >> k;
//			arr[sale][c] = k;
//		}
//		cin >> p;
//		arr[sale][1000] = p;
//		sale++;
//	}
//
//	int buy_num;
//	cin >> buy_num;
//
//
//	for (int i = 0; i < buy_num; i++)
//		cin >> buy_code[i][0] >> buy_code[i][1] >> buy_code[i][2];	// 0: 코드 1: 개수 2: 가격
//
//	cout << bargain(0, buy_code) << endl;
//
//}

#include <iostream>
#define INF 987654321
#define MAX 6*6*6*6*6
#define min(a,b)a<b?a:b
	using namespace std;

int arr[100][1001] = { 0, };
int sale = 0;
int buy_code[5][3] = { 0, };
int buy = 0;
int cache[100][MAX];

int pow(int a, int b)
{
	int total = 1;
	for (int i = 1; i < b; i++)
		total *= a;
	return total;
}
int bargain(int index, int buy[][3])
{
	if (index >= sale) {
		int total = 0;
		for (int i = 0; i < 5; i++)
			total += (buy[i][2] * buy[i][1]);
		return total;
	}
	for (int i = 0; i < 5; i++)
		if (buy[i][1] < 0)
			return INF;

	int value = 0;

	for (int i = 0; i < 5; i++)
		value += (buy[i][1]) * pow(6, 5 - i);

	int& ret = cache[index][value];
	if (ret != -1) return ret;
	ret = INF;
	ret = min(ret, bargain(index + 1, buy));
	
    for (int i = 0; i < 5; i++)
    {
		buy[i][1] -= arr[index][buy[i][0]];
    }

	ret = min(ret, bargain(index, buy) + arr[index][1000]);
	for (int i = 0; i < 5; i++)
	{
		buy[i][1] += arr[index][buy[i][0]];
	}
	return ret;
}
int main()
{
	int sale_num;
	cin >> sale_num;

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;

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
		cin >> buy_code[i][0] >> buy_code[i][1] >> buy_code[i][2];    // 0: 코드 1: 개수 2: 가격

	cout << bargain(0, buy_code) << endl;

}
