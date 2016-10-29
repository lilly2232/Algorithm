#include <iostream>
using namespace std;
int target;
int prt_total;
char arr[20];
int max_arr[20000];
int maxv = 0;

int len;
bool doub = false;

int pow(int a, int b)
{
	int total = 1;
	for (int i = 1; i < b; i++)
		total *= a;
	return total;
}
void dfs(char * sh_arr, int sh_len, int total, char * given_arr, int given_len)
{
	char cp_sh_arr[100] = { 0, };
	char cp_given_arr[100] = { 0, };

	if (total > target)
		return;

	if (given_len == 0)
	{
		if (prt_total <= total) {
			prt_total = total;
			int i = 0;
			for (i = 0; i < sh_len; i++)
				arr[i] = sh_arr[i];
			len = i;
			max_arr[maxv++] = prt_total;
		}

	}
	for (int i = 0; i < sh_len; i++)   // 지금까지 분쇄한 부분 copy
		cp_sh_arr[i] = sh_arr[i];

	for (int k = 1; k <= given_len; k++)
	{
		int size = k;
		int j = 0;
		int sh_index = sh_len;
		int local_total = total;
		for (int l = 0; l < k; l++) {
			cp_sh_arr[sh_index] = given_arr[l];
			local_total += ((pow(10, size - l) * (int(cp_sh_arr[sh_index]) - 48)));
			sh_index++;
		}
		cp_sh_arr[sh_index++] = ' ';
		int cp_len = given_len - size;
		for (j = 0; j < cp_len; j++)
			cp_given_arr[j] = given_arr[(j + size)];
		dfs(cp_sh_arr, sh_index, local_total, cp_given_arr, cp_len);
	}

}
int main()
{
	char parti[7] = { 0 };
	char sh_arr[100] = { 0, };

	len = 0;
	prt_total = -1;
	cin >> target;
	cin >> parti;

	for (; parti[len] != '\0'; len++) {};

	dfs(sh_arr, 0, 0, parti, len);
	if (prt_total == -1) {
		cout << "error" << endl;
		return 0;
	}
	int cnt = 0;

	for (int i = 0; i < maxv; i++)
		if (max_arr[i] == prt_total)
			cnt++;

	if (cnt == 1)
	{
		cout << prt_total << " ";
		for (int i = 0; i < len; i++)
			cout << arr[i];
	} else
		cout << "rejected" << endl;

	/*if (!doub) {
	cout << prt_total << " ";
	for (int i = 0; i < len; i++)
	cout << arr[i];
	}
	else
	cout << "rejected" << endl;*/

	return 0;
}