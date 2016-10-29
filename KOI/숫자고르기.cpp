#include <iostream>
using namespace std;
int arr[101];
int visit[101];
int h_visit[101];

int main()
{
	for (int i = 0; i < 101; i++)
	{
		arr[i] = 0;
	}
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= num; i++)
	{
		if (visit[arr[i]] == 0) {
			visit[arr[i]] = 1;
		}
	}
	bool f = true;
	int cnt = 0;
	while (f)
	{
		cnt = 0;
		f = false;
		for (int i = 1; i <= num; i++)
			h_visit[i] = 0;
		for (int i = 1; i <= num; i++)
			if (visit[i] == 1)
				h_visit[arr[i]] = 1;
		for (int i = 1; i <= num; i++)
			if (visit[i] != h_visit[i]) {
				f = true;
				visit[i] = 0;
			}
			else if (visit[i] == 1 && h_visit[i] == 1)
				cnt++;
	}
	cout << cnt << endl;
	for (int i = 0; i <= num; i++)
		if (visit[i] == 1)
			cout << i << endl;
	
}