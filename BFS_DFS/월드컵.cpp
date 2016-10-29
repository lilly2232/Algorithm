#include <iostream>
using namespace std;
int arr[6][3];
int result[6][3];
bool flag = false;
void check(int a, int b)	// vic : 0 무승부, 1 비김
{
	if (flag == true)
		return;
	if (a == 4 && b == 6)
	{
		flag = true;
		return;
	}
	if (b == 6) {
		if(a+2 < 6)
			check(a + 1, a+2);
		return;
	}
		// a:b를 이긴경우
	if (arr[a][0] > 0 && arr[b][2] > 0) {
		arr[a][0]--;
		arr[b][2]--;
		check(a, b + 1);
		arr[a][0]++;
		arr[b][2]++;
	} 
	//	 a:b에게 진경우
	if (arr[a][2] > 0 && arr[b][0] > 0) {
		arr[a][2]--;
		arr[b][0]--;
		check(a, b + 1);
		arr[a][2]++;
		arr[b][0]++;
	}
	if (arr[a][1] > 0 && arr[b][1] > 0) {
		// a:b 비긴경우
		arr[a][1]--;
		arr[b][1]--;
		check(a, b + 1);
		arr[a][1]++;
		arr[b][1]++;
	}
}
int main()
{
	int testcase = 4;
	while (testcase--) {
		int sum = 0;
		for (int i = 0; i < 6; i++)
		{
			int win, same, lose;
			cin >> win >> same >> lose;
			arr[i][0] = win;
			arr[i][1] = same;
			arr[i][2] = lose;
			sum += (win + same + lose);
		}

		flag = false;
		if(sum == 30)
			check(0, 1);
		
		if (flag == true)
			cout << "1 ";
		else
			cout << "0 ";
	}
	cout << endl;
}