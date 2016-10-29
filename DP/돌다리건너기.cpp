#include <iostream>
using namespace std;
char match_str[21];
char str[2][101];
int m_len = 0;
int len = 0; 
int cache[2][21][101];

int bridge(int pat, int match_index, int index)	// return : 가능한 경우의 수, pat (천/악), match_index (매칭 시켜야되는 문자 인덱스), index(현재 돌다리 위치)
{
	if (match_index == m_len)
		return 1;
	if (index > len)
		return 0; 
	int& ret = cache[pat][match_index][index];
	if (ret != 0)
		return ret;
	if (pat == 0)
	{
	
		for (int i = index; i < len; i++) 
			if (str[0][i] == match_str[match_index]) 
				ret +=  bridge(1, match_index+1, i+1);
		
	} else {
		for (int i = index; i < len; i++)
			if (str[1][i] == match_str[match_index])
				ret+= bridge(0, match_index+1, i+1);
	}
	return ret;
}
int main()
{
	cin >> match_str;
	cin >> str[0];
	cin >> str[1];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 101; k++)
				cache[i][j][k] = 0;

	for (; match_str[m_len] != '\0'; m_len++) {};
	for (; str[0][len] != '\0'; len++) {};

	cout << bridge(0, 0, 0) + bridge(1, 0, 0) << endl;
}
