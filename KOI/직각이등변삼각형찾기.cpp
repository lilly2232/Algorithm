#include <iostream>
#include <vector>

using namespace std;
int arr[10][10];
vector<pair<int,int> > three;

int flag = true;
void find_point()
{
	int x, y, cnt;
	cnt = 0; 
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			if (arr[i][j] == 1)
			{
				x = i; 
				y = j;
				cnt = 1;
				for (int next_j = j + 1; next_j < 10; next_j++)
				{
					cnt++;
				}
			}
	}
	for (int i = 0; i < 10; i++)
	{

	}
}
int find_length(int i, int j)
{
	int cnt = 0;
	if (arr[i][j + 1] == 1)
	{
		for (int next_j = j; next_j < 10; next_j++)
			if (arr[i][next_j] == 1)
				cnt++;
			else
				three.push_back(pair<int, int>(next_j-1, i));

	}
	else if (arr[i + 1][j] == 1)
	{
		for (int next_i = i; next_i < 10; next_i++)
			if (arr[i][next_i] == 1)
				cnt++;
			else
				three.push_back(pair<int, int>(j, next_i-1));
	}
	return cnt;
}
int main()
{
	char str[11];	
	for (int i = 0; i < 10; i++)
	{
		cin >> str;
		for (int j = 0; j < 10; j++)
			arr[i][j] = str[j] - 48;
	}
	three = vector<pair<int, int>>();
}