#include <iostream>
using namespace std;
int arr[101][101];

int main()
{
	int total = 0;
	for (int i = 0; i < 4; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++)
				arr[i][j] = 1;
	}
	
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (arr[i][j] == 1)
				total++;
	cout << total << endl;
}

