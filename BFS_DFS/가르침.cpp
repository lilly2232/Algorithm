#include <iostream>
#define MAX 51
using namespace std;
int n, k;
int arr[MAX][27];
int totalarr[27] = { 0, };
int max_value = 0;
int v[27] = { 0, };
int count()
{
	int val = 0;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		flag = true;
		for (int j = 1; j < 27 && flag == true; j++) 
		{
			if (arr[i][j] == 1 && v[j] == 0) {
				flag = false; 
			}
		}
		if (flag == true)
			val++;
	}
	return val;
}
void dfs(int pos, int cnt)
{
	if (cnt <= k - 5)
	{
		int val = count();
		if (max_value < val)
			max_value = val;
	}

	if (pos > 26 || cnt == k-5)
		return;
	int next = 0; 
	for (int i = pos+1; i < 27; i++)
		if (totalarr[i] == 1) 
		{
			v[i] = 1;
			dfs(i, cnt + 1);
			v[i] = 0;	
	//		dfs(i, cnt); 이미 선택 안한상태에서 다음꺼 선택하기가 됨 
		}

}
int main()
{
	cin >> n >> k;

	if (k < 5) {
		cout << "0" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		char str[20];
		cin >> str;
		int len = 0;
		for (len = 0; str[len] != '\0'; len++) {};
		for (int j = 4; j < len - 4; j++)
		{
			int x = str[j] - 96;
			arr[i][x] = 1;
			totalarr[x] = 1;
		}
	}


	v[1] = 1; v[3] = 1; v[9] = 1; v[14] = 1; v[20] = 1;

	totalarr[1] = 0; totalarr[3] = 0; totalarr[9] = 0; totalarr[14] = 0; totalarr[20] = 0;
	dfs(0, 0);
	
	cout << max_value << endl;

}