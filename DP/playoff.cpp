#include <iostream>
#define MAX 50
using namespace std;
int n;
int a, b;
int arr[MAX];
int rate[MAX];
int limit;
int pow(int a, int b)
{
	int total = 1;
	for (int i = 0; i < b; i++)
		total *= a;
	return total;
}
int playoff(int win, int lose, int cnt)	// 이겨야하는 수, 져야하는 경우
{ 
	if (win == n - a && cnt == limit)
		return 1;
	if (win == n - a && cnt < limit)
		return 0;
	int ret = 0;
	if (lose < limit)
		ret += playoff(win, lose + 1,cnt+1);
	ret += playoff(win + 1, lose,cnt);
	return ret;
}
int main()
{

	cin >> n >> a >> b;
	int value = pow(2, n - a + n - b - 1);
	int total = 0;
	for (int i = 0; i < n - b; i++)
	{
		limit = i;
		rate[i] = playoff(0, 0, 0) * value/ pow(2, n - a + i);
		total += rate[i];
	}
	for (int i = 2; i < value; i++) {
		if (total%i == 0 && value%i == 0)
		{
			total = total / i;
			value = value / i;
		}

	}
	cout << total << " " << value << endl;
	cout << value - total << " " << value << endl;
}