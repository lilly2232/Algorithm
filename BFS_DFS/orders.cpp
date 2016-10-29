#include <iostream>
using namespace std;
int arr[30] = { 0, };
int str_len = 0;
struct value
{
	char c;
	int n;
};
value values[30];


void orders(char c, char* order_str, int order_len, char *str, int n)
{

	if (n == 0) {
		for (int i = 0; i < order_len; i++)
			cout << order_str[i];
		cout << c << endl;
		return;
	}

	char my_order_str[200] = { 0, };   // 이미 정렬된거 복사하기 
	if (c != '\0')
	{
		for (int i = 0; i < order_len; i++)
			my_order_str[i] = order_str[i];
		my_order_str[order_len++] = c;
	}

	for (int l = 0; l < n; l++)
	{
		char cp_str[200] = { 0, };

		for (int i = 0; i < n; i++)
		{
			int j = 0;
			int k = 0;

			while (k != n) {
				if (k == l)
					k++;
				else {
					cp_str[j] = str[k];
					j++;
					k++;
				}
				// 재귀 할 문자열 만들기 
			}

		}
		if (str[l + 1] != str[l])
			orders(str[l], my_order_str, order_len, cp_str, n - 1);   // 재귀로 보내기 
	}
}
int main()
{
	char str[201];
	char order_str[201];
	int total = 0;

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		arr[str[i] - 97]++;
	}

	for (int i = 0; i < 30; i++)
		if (arr[i] > 0) {
			values[total].c = char(i) + 97;
			values[total].n = arr[i];
			total++;
		}
	// make string

	for (int i = 0; i < total; i++)
	{
		while (values[i].n > 0)
		{
			str[str_len++] = values[i].c;
			values[i].n--;
		}
	}
	orders('\0', order_str, 0, str, str_len);
}