#include <iostream>
using namespace std;
#define MAX 9876543
struct MyQueue {
	int num;
	int total;
};
MyQueue queue[10000000];
int visit[10001] = { 0 };
int sosu[10001] = { 0, };
int t_total; int front; int rear;
void init()
{
	t_total = MAX;
	front = 0;
	rear = 0;
	for (int i = 1000; i < 10000; i++)
		visit[i] = 0;
}
void make_sosu()
{
	sosu[0] = 1;
	sosu[1] = 1;

	int j = 1;
	while (j < 10000) {
		while (1)
		{
			j++;
			if (sosu[j] == 0)
				break;
		}
		for (int k = j+1; k < 10000; k++)
			if (k%j == 0)
				sosu[k] = 1;
	}
}
void bfs(int start_num, int end_num)
{
	visit[start_num] = 1;
	queue[rear].num = start_num;
	queue[rear].total = 0;
	rear++;

	while (front != rear)
	{
		int num = queue[front].num;
		int total = queue[front++].total;
	
		if (num == end_num) {
			if (t_total > total)
				t_total = total;
		}
		int a = (num / 1000);
		num %= 1000;
		int b = (num / 100);
		num %= 100;
		int c = (num / 10);
		num %= 10;
		int d = num;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 4; j++) {
				if (j == 0 && i > 0)
					num = 1000 * i + 100 * b + 10 * c + d;
				else if (j == 1)
					num = 1000 * a + 100 * i + 10 * c + d;
				else if (j == 2)
					num = 1000 * a + 100 * b + 10 * i + d;
				else
					num = 1000 * a + 100 * b + 10 * c + i;

				if (sosu[num] == 0 && visit[num] != 1) {
					visit[num] = 1;
					queue[rear].num = num;
					queue[rear].total = total + 1;
					rear++;
				}
			}
		}
	}
}
int main()
{
	int num;
	cin >> num;
	make_sosu();
	for (int i = 0; i < num; i++)
	{
		int start_num, end_num;
		cin >> start_num >> end_num;
		init();
		bfs(start_num, end_num);
		if (t_total == MAX)
			cout << "impossible" << endl;
		else
			cout << t_total << endl;
	}
}

