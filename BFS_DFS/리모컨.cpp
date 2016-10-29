#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 500001
using namespace std;
int target;
int broken[10] = { 0, };
int visit[MAX];
int tarr[6];
int multi[6] = { 100000,10000,1000,100,10,1 };
vector<pair<int,int> > findarr;
void makeclose(int pos, int val,int num ,int cnt)
{
	if (pos == 6) {
		findarr.push_back(make_pair(val, cnt));
		return;
	}
	
	if (broken[num] == 1) {
		for (int i = num+1; i < 10; i++)
			if(broken[i] == 0)
				makeclose(pos, val ,i, cnt);
		for (int i = num - 1; i >= 0; i--)
			if (broken[i] == 0)
				makeclose(pos, val, i, cnt);
	}
	else 
		makeclose(pos + 1, val+num*multi[pos], tarr[pos + 1], cnt + 1);
}

int main()
{
	cin >> target;

	int n;
	cin >> n; 
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		broken[x] = 1;
	}
	int mod = target;

	int size = 0;
	for (int i = 100000; i > 0; i /= 10)
	{
		tarr[size++] = mod / i;
		mod = mod%i;
	}
		
	for (int i = 0; i < 6; i++) 
			if (tarr[i] != 0) {
				makeclose(i, 0, tarr[i], 0);
				break;
			}
	int ret = abs(target-100);
	for (int i = 0; i < findarr.size(); i++) {
		cout << findarr[i].first << " " << findarr[i].second << endl;
	}
	for (int i = 0; i < findarr.size(); i++) {
		if (target > findarr[i].first)
			ret = min(ret, abs(target - findarr[i].first) + findarr[i].second);
		else
			ret = min(ret, abs(findarr[i].first - target) + findarr[i].second);
	}

	//for (int k = 0; k <= 9; k++)
	//{
	//	if(broken[k] == 0)
	//		ret = min(ret, abs(target - k) + 1);
	//}
		cout << ret << endl;
}