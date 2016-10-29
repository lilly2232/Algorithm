#include <iostream>
using namespace std;
int num;
int cache[11][100][100];

int tickets(int index, int total, int pre)	// luckey인지 여부 , index 현재, 현재 합, 앞의 반 합
{
	
	if (index >= num)
	{
		if (total == pre)
			return 1;
		else
			return 0;
	}
	int& ret = cache[index][total][pre];
	if (ret != -1)return ret;
	ret = 0;
	if (index == num/2)
	{
		for (int i = 0; i < 10; i++)
			ret+= tickets(index + 1, i, total);
	}
	else {
		for (int i = 0; i < 10; i++)
			ret += tickets(index + 1, total + i, pre);
	}
	return ret;
}
int main()
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++)
				cache[i][j][k] = -1;
	cin >> num;
	
	cout << tickets(0, 0, 0) << endl;
}