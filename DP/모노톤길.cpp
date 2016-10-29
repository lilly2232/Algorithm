#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cafe_num;
vector<pair<int, int> > arr;
int test_cafe[11];

bool oper(pair<int, int> aa, pair<int, int> bb) // 내림 차순 
{
	if (aa.second > bb.second)
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
		arr = vector<pair<int, int> >(cafe_num+1);
		arr[0].first = -1; arr[0].second = 0; 

		for (int i = 1; i <= cafe_num; i++)
			cin >> arr[i].first >> arr[i].second;
		sort(arr.begin(), arr.end());

		for (int i = 1; i <= cafe_num; i++)
		   cout <<  arr[i].first <<" " <<  arr[i].second <<  endl;

		int k = 1;
		int pre =0;
		int next =0;

		for (int i = 0; i <= cafe_num; i++)
		{
			
			if (i + 1 <= cafe_num && arr[i].first == arr[i + 1].first)
					k++;
			else {
				if (pre -1 >= 0&& arr[pre].second != arr[pre-1].second) 
					sort(arr.begin() + pre, arr.begin() + pre + k, oper);
				pre = i + 1;	
				k = 1;
			}
		}
		for (int i = 1; i <= cafe_num; i++)
			cout << i << " " << arr[i].first << " " << arr[i].second << endl;


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