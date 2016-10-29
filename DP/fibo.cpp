#include <stdio.h>
#define lld long long int
// 1. i ��°�� ���� ���Ǹ� �����.
// 2. ��ȭ��
// 3. base case 0��°, 1��°
// ��� caching ==> DP
// ������ ���� ���� , ���� ���� , ������ ǥ�� ���� (int -> long long int)

lld cache[1000];
//i ��° �Ǻ���ġ ���� ���ϴ� �Լ�
lld f(int i)
{
	if (i == 0) return 0;
	if (i == 1) return 1;
	
	lld ret = cache[i];
	if (ret != -1) return ret;

	ret = f(i - 1) + f(i - 2);
	cache[i] = ret;

	return ret;
}

int main()
{
	for (int i = 0; i < 1000; i++) cache[i] = -1;


	printf("%lld\n", f(100));
}