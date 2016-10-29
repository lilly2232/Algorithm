#include <iostream>
#define lld long long int
#define MAX 101
#define MOD 1000000000
using namespace std;
int n;
lld s_total = 0;
lld cache[MAX][MAX] = { 0, };

//void stair_num(int total, int pref)
//{
//	if (total == n)
//	{
//		s_total++;
//		return;
//	}
//	if (pref == 9)
//		stair_num(total + 1, pref - 1);
//	else if (pref == 0)
//		stair_num(total + 1, pref + 1);
//	else 
//	{
//		stair_num(total + 1, pref + 1);
//		stair_num(total + 1, pref - 1);
//	}
//}

lld stair_num(int total, int pref)
{
	if (total == n) 
		return 1;

	lld ret = cache[total][pref];

	if (ret != -1)
		return ret;

	if (pref == 0) 
		ret = (stair_num(total + 1, pref + 1)% MOD);
	else if (pref == 9) 
		ret = (stair_num(total + 1, pref - 1)% MOD);
	else 
		ret = (stair_num(total + 1, pref + 1)+stair_num(total + 1, pref - 1))% MOD;
	
	cache[total][pref] = ret;		// 캐시 값에 값 저장 
	return cache[total][pref];
}

int main()
{
	cin >> n;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		cache[i][j] = -1;
	
	for (int i = 1; i < 10; i++)
		s_total = (stair_num(1, i)+ s_total)% MOD;

	cout << s_total << endl;
}