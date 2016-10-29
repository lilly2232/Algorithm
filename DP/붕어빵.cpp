#include <iostream>
#define MAX 1001
#define lld long long int
using namespace std;
lld price[MAX];
lld max_price[MAX] = { 0, };
int num;
// ��ü : n���� ���� ������ �ִ� ���� 
// ù��° �ؾ�� ��� ���� ���� (���� ����)
lld make_bread(int n)
{

	if (n == 1) return price[1];
	if (n == 0) return 0;

	if (max_price[n] != -1)
		return max_price[n];

	for (int i = 1; i <= n; i++)
	{
		lld ret = price[i] + make_bread(n - i);
		if (max_price[n] < ret)
				max_price[n] = ret;
	}
	return max_price[n];
}
int main()
{
	cin >> num;

	for (int i = 1; i <= num; i++)
		cin >> price[i];
	for (int i = 1; i <= num; i++)
		max_price[i] = -1;

	cout << make_bread(num) << endl;
}