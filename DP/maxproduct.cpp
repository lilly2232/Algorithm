#include <iostream>
#define MAX 10001
#define max(a,b) a>b?a:b
using namespace std;
double arr[MAX];
double cache[MAX];
int num;
double max_value = 0;
double maxproduct(int start)
{
	if (start > num)
		return 1;
	double& ret = cache[start];
	if (ret != -1)
		return ret;
	ret = 1;
	ret = max(arr[start] * maxproduct(start + 1),ret);
	if (max_value < ret)
		max_value = ret;
	return ret;

}
int main()
{
	for (int i = 0; i < MAX; i++)
		cache[i] = -1;
	cin >> num;
	for (int i = 0; i < num; i++)
		cin >> arr[i];
	for (int i = 0; i < num; i++)
		maxproduct(i);
	printf("%.3lf\n",max_value);
}