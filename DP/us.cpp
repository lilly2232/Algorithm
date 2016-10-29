#include <iostream>
#include <vector>
#define MAX 10001
#define max(a,b) a>b?a:b
using namespace std;
int arr[MAX];
int cache[MAX];
int n;
int cache_arr[MAX];
int us(int start)	// return : 최대 증가 수열 수, start : 시작 인덱스 
{
	int& ret = cache[start+1];
	if (ret != -1)
		return ret;
	ret = 1;
	int bestNext = -1;
	for (int i = start+1; i < n; i++)
		if (start == -1 || arr[start] < arr[i])
		{
			int cand = 1 + us(i);
			if (cand > ret)
			{
				ret = cand;
				bestNext = i;
			}
		}
	cache_arr[start + 1] = bestNext;
	return ret;
}

//int us(int start)	// return : 최대 증가 수열 수, start : 시작 인덱스 
//{
//	int& ret = cache[start+1];
//	if (ret != -1)
//		return ret;
//	ret = 1;
//	int bestNext = -1;
//	for (int i = start+1; i < n; i++)
//		if (start == -1 || arr[start] < arr[i])
//		{
//			int cand = 1 + us(i);
//			if (cand > ret)
//			{
//				ret = cand;
//				bestNext = i;
//			
//			}
//		}
//	cache_arr[start + 1] = arr[bestNext];
//	return ret;
//}

void reconstruct(int start, vector<int>& seq)
{
	if (start != -1)
		seq.push_back(arr[start]);
	int next = cache_arr[start + 1];
	if (next != -1) reconstruct(next, seq);
}
int main()
{
	for (int i = 0; i < MAX; i++)
		cache[i] = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int cnt = us(-1)-1;
	cout << cnt << endl;

	for (int i = 0; i < 10; i++)
		cout << cache_arr[i] << " ";

	vector<int> s;
	reconstruct(-1, s);
	for (int i = 0; i < s.size(); i++)
		cout << s.at(i) << " ";
}