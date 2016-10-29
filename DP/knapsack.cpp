#include <iostream>
#define MAX 11111
#define max(a,b)a>b?a:b
using namespace std;
int weight;
int num;
int arr[101][3];	// 0번호, 1 무게, 2 가격
int cache[MAX][MAX];
int sol(int index, int total)	// 최대 이익, index: 몇번째 가방, total 현재까지 무게 
{
	if (index >= num)
		return 0;

	int& ret = cache[index][total];
	if (ret != -1) return ret;
	ret = 0;
	if(total + arr[index][1] <= weight)
		ret = max(ret, sol(index + 1, total + arr[index][1]) + arr[index][2]);
	ret = max(ret, sol(index + 1, total));

	return ret;
}
int main()
{

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j] = -1;

	cin >> weight;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i][1] >> arr[i][2];
	}
	cout << sol(0, 0) << endl;
}