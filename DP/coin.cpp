#include <iostream>
using namespace std;
double arr[5] = {1, 5, 10, 25,50};
double coin_total;

int coin(int index, double total)
{
	if (total == coin_total) {
		return 1;
	}
	if (index > 4)
		return 0;

	int ret = 0;
	if (total + arr[index] <= coin_total) 
		ret += coin(index, total + arr[index]);
	ret += coin(index+1, total);

	return ret;
}
int main()
{
	cin >> coin_total;
	coin_total *= 100;
	cout << coin(0, 0) << endl;
}
