#include <iostream>
#define MAX 100000
using namespace std;
char arr[27] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char ch_str[27][5] = { "4","|3", "(","|)","3","|=","6","#","|","_|","|<","|_","|\\/|","|\\|","0","|0","(,)","|?","5","7", "|_|","\\/","\\/\\/","><","-/","2"};
int ch_size[27] = {1,2,1,2,1,2,1,1,1,2,2,2,4,3,1,2,3,2,1,1,3,2,4,2,2,1};
int len = 0;
char new_str[MAX];
int cache[MAX];
int spam(int index)
{
	if (index == len)
		return 1;
	if (index > len)
		return 0;
	int& ret = cache[index];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 26; i++)
	{
		int k = 0;
		for (k = 0; k < ch_size[i]; k++)
			if (new_str[index + k] != ch_str[i][k])
				break;
		if (k == ch_size[i]) {
			ret += spam(index + k);
		}
	}
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		cache[i] = -1;
 	char str[MAX];
	cin >> str;
	for (; str[len] != '\0'; len++) {};

	int index = 0;
	for (int k = 0; k < len; k++)
	{
		for (int i = 0; i < 26; i++)
			if (arr[i] == str[k])
			{
				for (int j = 0; ch_str[i][j] != '\0'; j++)
					new_str[index++] = ch_str[i][j];
				break;
			}
	}
	len = index;
	cout << spam(0)<< endl;
}
