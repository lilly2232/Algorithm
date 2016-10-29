#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cafe_num;
vector<pair<int, int> > arr;
int test_cafe[11];

bool oper1(pair<int, int> aa, pair<int, int> bb)	// 내림차순
{
	if (aa.second > bb.second)
		return true;
	else
		return false;
}
bool oper2(pair<int, int> aa, pair<int, int> bb)	// 오름차순
{
	if (bb.second > aa.second)
		return true;
	else
		return false;
}
int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--)
	{

		cin >> cafe_num;
		arr = vector<pair<int, int> >(cafe_num + 1);
		arr[0].first = -1; arr[0].second = 0;

		for (int i = 1; i <= cafe_num; i++)
			cin >> arr[i].first >> arr[i].second;

		sort(arr.begin(), arr.end());

		int k = 1;
		int pre = 0;
		int next = 0;

		for (int i = 0; i <= cafe_num; i++)
		{

			if (i + 1 <= cafe_num && arr[i].first == arr[i + 1].first)
				k++;
			else {


				if (pre - 1 >= 0 && arr[pre].second != arr[pre - 1].second)	// 문제다!!
				{
		
					if (arr[pre - 1].second > arr[pre].second)
						next = 1;
					else
						next = 2;

					if (next == 1)
						sort(arr.begin() + pre, arr.begin() + pre + k, oper1);
					else
						sort(arr.begin() + pre, arr.begin() + pre + k, oper2);
				}
				pre = i + 1;
				k = 1;	
			}
		}

		int test_num;
		cin >> test_num;
		int test_cafe[11];
		int index = 0;

		for (int i = 0; i < test_num; i++)
			cin >> test_cafe[index++];
		for (int i = 0; i < test_num; i++)
			cout << arr[test_cafe[i]].first << " " << arr[test_cafe[i]].second << endl;

	}
}