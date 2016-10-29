#include <iostream>
#include <math.h>

using namespace std;
int arr[8];
int sosu[100];
int index = 0; 
int n;

int pow(int a, int b)
{
	int total = 1;
	for (int i = 0; i < b; i++)
		total *= a;
	return total;
}
void test_num(int* arr)
{
	int sqrn;
	for (int i = 1; i < n; i++) {
		if (arr[i] % 2 == 0)
			return;
		for (int j = 0; j < index; j++)
			if (arr[i] % sosu[j] == 0)
				return;
	}
	for (int i = 0; i < n; i++)
	{
		sqrn = (int)sqrt(arr[i]);

		for (int j = 3; j <= sqrn; j = j+2) {
			if (arr[i] % j == 0)
				return;
		}
	}
	sosu[index++] = arr[n - 1];
	cout << arr[n - 1] << endl;
}
int main()
{

	int s_n;

	cin >> n;
	s_n = pow(10, n - 1);
	for (int i = (2 * s_n ); i < pow(10, n); i++)
	{
		if (i / s_n == 4 || i / s_n == 6 || i / s_n == 8 || i / s_n == 9)
			i += s_n;
		else
		{
			int k = i;
			int m = n-1;

			for (int j = 0; j < n; j++)
			{
				arr[j] = (k / pow(10, m));
				m--;
			}
			test_num(arr);
		}	
	}
}