#include <iostream>
#define MAX 1000001
using namespace std;
int min_total = 1000000;
int cache[MAX];
int num;

int make_one(int n)
{
	if (n == 1)	return 0;

	int ret = cache[n];
	if (ret != MAX) return ret;

	int a = MAX; int b = MAX; int c = MAX;
	if (n % 3 == 0) 
		a = (make_one(n / 3) + 1);
	if (n % 2 == 0)
		 b = (make_one(n / 2) + 1);
	c = (make_one(n - 1) + 1);

	if (ret > a)
		ret = a;
	if (ret > b)
		ret = b;
	if (ret > c)
		ret = c;

	cache[n] = ret;

	return ret;
}

//void make_one(int n, int total)
//{
//	if (n == 1) {
//		if (min_total > total)
//			min_total = total;
//		return;
//	}
//	if (total > min_total)
//		return;
//
//	if (n % 3 == 0)
//		make_one(n / 3, total + 1);
//	if (n % 2 == 0)
//		make_one(n / 2, total + 1);
//	make_one(n - 1, total + 1);
//}
int main()
{
	cin >> num;
	for (int i = 0; i < MAX; i++)
		cache[i] = MAX;
	cout << make_one(num);
// make_one(num, 0);
//	cout << min_total << endl;
}