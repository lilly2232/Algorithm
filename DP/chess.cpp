#include <iostream>
#define MAX 1001
#define max(a,b) a>b?a:b

using namespace std;
int arr[MAX][2];
int cache[MAX][16][16];
int num = 0;
int chess(int index, int white, int black)	// ÃÖ´ë Á¡¼ö , index ÇöÀç ÀÎµ¦½º. white ÆÀ¿ø¼ö black ÆÀ¿ø¼ö 
{

	if (white + black > 30 || index >= num)
		return 0;
	int& ret = cache[index][white][black];
	if (ret != -1) return ret;
	if(white+1 <= 15)
		ret = max(ret, chess(index+1,white + 1, black) + arr[index][0]);
	if(black+1 <= 15)
		ret = max(ret, chess(index+1,white, black + 1) + arr[index][1]);
	ret = max(ret, chess(index+1, white, black));
	return ret;
}
int main()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 16; j++)
			for (int k = 0; k < 16; k++)
				cache[i][j][k] = -1;

	while (!cin.eof())
	{
		cin >> arr[num][0] >> arr[num][1];
		num++;
	}
	cout << chess(0, 0, 0) << endl;
}