// ���� Ÿ�� ���� long long 2^32 ����~
#include <iostream>
#define MAX 1000
using namespace std;
int n;
long long cache[40][MAX];
int make_num = 0;


long long subset(int index, int total) // return : ����� �ִ� ��� �ΰ�, index ���� ���� �� ��ġ, total ���� ��
{
	if (total == make_num)
		return 1;
	if (total > make_num || index > n)
		return 0;

	long long& ret = cache[index][total];
	if (ret != -1)
		return ret;

	ret = subset(index + 1, total + index) + subset(index + 1, total);
	return ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < 40; i++)
		for (int j = 0; j < MAX; j++)
			cache[i][j]= -1;

	for (int i = 1; i <= n; i++)
		make_num += i;

	if (make_num % 2 == 0) {
		make_num /= 2;
		cout << subset(1, 0)/2 << endl;
	}
	else
		cout << "0" << endl;


}