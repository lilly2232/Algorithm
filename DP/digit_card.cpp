#include <iostream>
#define MAX 41
using namespace std;
int arr[MAX];
int visit[35];
int len = 0;
int cache[MAX];
int digit_card(int index)
{
	if (index == len)
		return 1;
	if (index > len || arr[index] == 0)
		return 0;

	int& ret = cache[index];
	if (ret != -1)return ret;
	ret = 0;
	int next = arr[index] * 10 + arr[index + 1];
	if (next <= 34) 
		ret += digit_card(index + 2);
	ret += digit_card(index + 1);

	return ret;
	
}
int main()
{
	for (int i = 0; i < MAX; i++)
		cache[i] = -1;
 	char str[MAX];
	cin >> str;
	for (; str[len] != '\0'; len++)
		arr[len] = str[len] - 48;
	cout << digit_card(0) << endl;
}