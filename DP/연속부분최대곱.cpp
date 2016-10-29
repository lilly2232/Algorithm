#include <iostream>
#include <stdio.h>
#define max(a,b) a<b?b:a
#define MAX 10001
using namespace std;

double arr[MAX];
double cache[MAX][MAX];
double max_value = -1;
int main()
{
	int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
		cin >> arr[i];

	for (int i = 0; i <= num; i++)
		for (int j = 0; j <= num; j++)
			cache[i][j] = 1;

	for (int j = 1; j <= num; j++) {
		cache[1][j] = arr[j] * cache[1][j - 1];
		max_value = max(cache[1][j], max_value);
	}
	for (int i = 2; i <= num; i++)
	{
		int j = 1;
		while (j <= num - i+1)
		{
			if (arr[i-1] == 0) {
				for (int k = i; k < j+i; k++)
					cache[i][j] *= arr[k];
			} else {
				if (cache[i - 1][j + 1] != 0)
						cache[i][j] = cache[i - 1][j + 1] / arr[i - 1];
					else
						cache[i][j] = 0;
			}
			max_value = max(cache[i][j], max_value);
			cout << "cache[" << i << "][" << j << "] : " << cache[i][j] << "  max_value : " << max_value << endl;
			j++;
		}
	
		}
	printf("%.3lf\n", max_value);

}