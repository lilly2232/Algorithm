#include <iostream>
#include <math.h>

using namespace std;
int n;
int sosu_arr[100];
int index = 0;

int pow(int a, int b)
{
	int total = 1;
	for (int i = 0; i < b; i++)
		total *= a;
	return a;
}
bool isPrime(int num)
{
	int squrn = sqrt(num);

	for (int i = 0; i < index; i++)
		if (num % sosu_arr[i] == 0)
			return false;
	for (int i = 2; i <= squrn; i++)
		if (num % i == 0)
			return false;
	return true;
}
void dfs(int num, int digit)
{

	if (digit == n)
	{
		if (isPrime(num))
			cout << num << endl;
	}

	if (isPrime(num))
	{
		sosu_arr[index++] = num;
		num = (num * pow(10, digit));
		for (int i = 1; i < 10; i++)
			dfs(num + i, digit + 1);
	}
}
int main()
{
	cin >> n; 
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
}