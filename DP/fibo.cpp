#include <stdio.h>
#define lld long long int
// 1. i 번째에 대한 정의를 세운다.
// 2. 점화식
// 3. base case 0번째, 1번째
// 재귀 caching ==> DP
// 변수의 범위 보기 , 논리적 범위 , 변수의 표현 범위 (int -> long long int)

lld cache[1000];
//i 번째 피보나치 수를 구하는 함수
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