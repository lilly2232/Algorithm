#include <iostream>
#include <algorithm>

using namespace std;
int target;
int broken[10] = { 0, };
int tarr[6];

int main()
{
	cin >> target;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		broken[x] = 1;
	}

	int ret = abs(target - 100);

	if (broken[0] == 0) ret = min(ret,1+abs(target - 0));
	
	for (int i = 1; i < 1000000; i++)
	{
		int mod = i;
		int size = 0; 
		for (int j = 100000; j > 0; j /= 10)
		{
			tarr[size++] = mod / j;
			mod = mod%j;
		}
		bool temp = true;
		int start;
		for (start = 0; start < 6; start++)
			if (tarr[start] != 0)
				break;
		for (int i = start; i < 6; i++)
			if (broken[tarr[i]] == 1)
				temp = false;
		if (temp == true)
			ret = min(ret, 6-start+ abs(target-i));
	}
	cout << ret << endl;

}