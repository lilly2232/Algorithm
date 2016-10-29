#include <iostream>
#include <stdio.h>
using namespace std;

double v_max = -1;
double arr[10001] = { 1 };
int main()
{
	int num;
	cin >> num;
	cin >> arr[1];

	for (int i = 2; i <= num; i++) {
		double val;
		cin >> val;
		if (val * arr[i - 1] > val)
			arr[i] = val * arr[i - 1];
		else
			arr[i] = val;
	}
	for (int i = 1; i <= num; i++)
		if (v_max < arr[i])
			v_max = arr[i];
	printf("%.3lf\n", v_max);
}