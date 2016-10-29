#include <iostream>
#define MAX 301
using namespace std;
int num;
int score[MAX];
int max_score[MAX];
bool start = true;

//int up_stair(int stair, int pref)	// n 계단 위치, i : 1 or 2 : 
//{
//	if (stair == 1)
//		return score[1];
//	if (stair < 1)
//		return -10000000;
//	int ref;
//	if (pref == 1)
//		ref = score[stair] + up_stair(stair - 2, 2);
//	else if (pref == 2){
//		ref = score[stair] + up_stair(stair - 1, 1);
//		if (ref < score[stair] + up_stair(stair - 2, 2))
//		ref = score[stair] + up_stair(stair - 2, 2);
//	}
//	return ref;
//}

int up_stair(int stair, int pref)	// n 계단 위치, i : 1 or 2 : 
{
	if (stair == 1)
		return score[1];
	if (stair < 1)
		return -10000000;
	int ref = max_score[stair];
	if (ref != -1)
		return ref;
	if (pref == 1) {

		cout << "stair : " << stair << endl;
		ref = score[stair] + up_stair(stair - 2, 2);
		cout << "ref " << ref << endl;
		if (ref > 0 && ref > max_score[stair])
			max_score[stair] = ref;
	}
	else if (pref == 2) {
		cout << "stair : " << stair << endl;
		ref = score[stair] + up_stair(stair - 1, 1);
		cout << "ref " << ref << endl;
		if (ref > 0 && ref > max_score[stair])
			max_score[stair] = ref;

		ref = score[stair] + up_stair(stair - 2, 2);
		cout << "ref " << ref << endl;
		if (ref > 0 && ref > max_score[stair])
			max_score[stair] = ref;
	}
	cout<< stair << "max_score" << max_score[stair] << endl;
	return max_score[stair];
}

int main()
{
	cin >> num;

	for (int i = 1; i <= num; i++)
		cin >> score[i];
	
	for (int i = 0; i <= MAX; i++)
		max_score[i] = -1;
	max_score[0] = -10000000;
//	max_score[1] = score[1];
//	max_score[2] = score[2] + score[1];
//	max_score[3] = score[3] + score[1];

	cout << up_stair(num,2)<< endl;
	


}