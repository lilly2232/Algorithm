#include <iostream>
using namespace std;
int n;

char* my_copy(char *str, int len)
{
	char* cpstr = new char[100];

	for (int i = 0; i < len; i++)
		cpstr[i] = str[i];
	return cpstr;
}

int my_pow(int a, int b)
{
	int total = 1;
	for (int i = 0; i < b; i++)
	{
		total *= a;
	}
	return total;
}

bool iszerosum(char *str, int len)
{
	char cpstr[100];
	int strlen = 0, cplen = 0;
	int num = 0;
	int total = 0;
	int index = 0;
	int cnt = 0;
	int flag = 0;			// 0 : +, 1 : -


	while (strlen < len)
	{
		if (str[strlen] == ' ')
			strlen++;
		else
			cpstr[cplen++] = str[strlen++];
	}

	while (index < cplen) {

		if (cpstr[index] == '-')
			flag = 1;
		else if (cpstr[index] == '+')
			flag = 0;
		else
			cnt++;

		if (cpstr[index + 1] == '-' || cpstr[index + 1] == '+' || index + 1 == cplen)
		{
			num = 0;
			while (cnt > 0)
			{
				
					num += (cpstr[index + 1 - cnt] - 48)* (my_pow(10, --cnt));		// dovelet 에서는 앞에서 부터 수행 
																					// 여기서는 -- 먼저 수행 
					//num += (my_pow(10, --cnt)*(cpstr[index + 1 - cnt] - 48));
			
			}

			if (flag == 1)
				num *= -1;
			total += num;

		}
		index++;
	}

	if (total == 0)
		return true;
	else
		return false;

}
void dfs(int num, char* str, int len)
{

	char* cp = my_copy(str, len);

	if (num == n) {
		cp[len++] = char(num + 48);
		if (iszerosum(cp, len)){
			for (int i = 0; i < len; i++)
				cout << cp[i];
			cout << '\n';
		}
		return;
	}
	cp[len++] = char(num + 48);
	cp[len] = ' ';
	dfs(num + 1, cp, len + 1);
	cp[len] = '+';
	dfs(num + 1, cp, len + 1);
	cp[len] = '-';
	dfs(num + 1, cp, len + 1);
}
int main()
{
	char str[100];
	cin >> n;
	dfs(1, str, 0);	// + : 0
}