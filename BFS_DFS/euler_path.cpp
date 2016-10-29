#include <iostream>
using namespace std;

int arr[101][101];
int node_num;
int start_point = 1;

void init()
{
	for (int i = 0; i < 101; i++)
	for (int j = 0; j < 101; j++)
		arr[i][j] = 0;
}

void euler(int num)
{
	for (int i = 1; i <= node_num; i++)
		if (arr[num][i] > 0) {
			arr[num][i]--;
			arr[i][num]--;
			arr[num][0]--;
			arr[i][0]--;
			euler(i);
		}
	cout << num << " ";
}


void euler(int num)
{
	int stack[1000];
	int pnt = -1;
	int temp;

	stack[++pnt] = num;

	while (pnt > -1) {
		temp = stack[pnt--];
		if (arr[temp][0] == 0)
			cout << temp << " ";
		else
			stack[++pnt] = temp;
		for (int i = node_num; i > 0; i--) {
			if (arr[temp][i] > 0) {
				stack[++pnt] = i;
				arr[temp][i]--;
				arr[i][temp]--;
				arr[i][0]--;
				arr[temp][0]--;
				break;
			}
		}
	}

}


int is_euler()
{
	int cnt = 0;

	for (int i = 1; i <= node_num; i++)
	if (arr[i][0] % 2 == 1) {
		start_point = i;		//홀수일 때만 변경 
		cnt++;
	}
	if (cnt == 2 || cnt % 2 == 0)
		return start_point;
	else
		return -1;

}


int main()
{
	int edge_num;
	int x, y;

	init();

	cin >> node_num >> edge_num;

	for (int i = 0; i < edge_num; i++) {
		cin >> x >> y;
		arr[x][y]++;
		arr[y][x]++;
		arr[x][0]++;
		arr[y][0]++;
	}


	if (is_euler() > 0)
		euler(start_point);
	else
		cout << "0" << endl;


}