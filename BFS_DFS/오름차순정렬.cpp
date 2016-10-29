#include <iostream>
using namespace std;

int main(void)
{
	// 여기서부터 작성

	int num;
	int arr[5001];
	cin >> num;
	for (int i = 0; i < num; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < num-1; i++)
		for (int j = i + 1; j < num; j++)
			if (arr[i]>arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
	for (int i = 0; i < num; i++)
		printf("%d ", arr[i]);
	cout << endl;
	return 0;
}
