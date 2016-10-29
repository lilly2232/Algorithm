#include <iostream>
#include <vector>
#define MAX 101
#define max(a,b)a>b?a:b
using namespace std;
int num; 
int arr[MAX][4];
struct tow {
	int cnt;
	int high;
};
tow cache[MAX];
int cache_arr[MAX];


tow tower(int start)	// return : 최대 높이, start 시작 번호, 현재 사용한 벽돌
{
	tow& ret = cache[start + 1];;
	if (ret.high != -1) {
		return ret;
	}
	ret.cnt = 1;
	ret.high = 0;
	int next = -1;
	for (int i = 1; i <= num; i++)
		if (start == -1 || (arr[start][1] > arr[i][1] && arr[start][3] > arr[i][3])) {
			tow m_tower = tower(i);
			int cand_high = arr[i][2] + m_tower.high;
			int cand_cnt = 1 + m_tower.cnt;
			if (cand_high >= ret.high)
			{
				next = i;
				ret.high =  cand_high;
				ret.cnt = cand_cnt;
			}
		}
	cache_arr[start+1] = next;
	return ret;
}
void reconstruct(int start, vector<int>& seq)	//& 넣어줘야 수정이됨 
{
	if (start != -1)
		seq.push_back(arr[start][0]);
	int next = cache_arr[start+1];
	if(next != -1) reconstruct(next, seq);
}
int main()
{
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		arr[i][0] = i;
		cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}
	for (int i = 0; i < MAX; i++) {
		cache_arr[i] = -1;
	}
	for (int i = 0; i < MAX; i++) {
		cache[i].cnt = -1;
		cache[i].high = -1;
	}

	cout << tower(-1).cnt -1 << endl;

	vector<int> s = vector<int>();
	reconstruct(-1, s);
	for (int i = s.size()-1; i >= 0; i--)
		cout << s.at(i) << endl;
}