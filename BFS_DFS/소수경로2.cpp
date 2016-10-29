#include <iostream>
using namespace std;

struct MyQueue
{
	int number;
	int total;
};

int sosu[100001] = { 0, };
int dest_num;
int front = 0;
int rear = 0;
int m_total = 100001;
MyQueue queue[10000000];
int visit[1000001];

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
		for (int k = j + 1; k < 10000; k++)
			if (k%j == 0)
				sosu[k] = 1;
	}
}

void bfs()
{
	while (front != rear) {
		int num = queue[front].number;
		int total = queue[front++].total;

		if (num == dest_num) {
			if (m_total > total)
				m_total = total;
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
			for (int j = 0; j < 4; j++)
			{
				int numb;
				if (j == 0 && i != 0)
					numb = i * 1000 + b * 100 + c * 10 + d;
				else if (j == 1)
					numb = a * 1000 + i * 100 + c * 10 + d;
				else if (j == 2)
					numb = a * 1000 + b * 100 + i * 10 + d;
				else
					numb = a * 1000 + b * 100 + c * 10 + i;

				if (sosu[numb] == 0 && visit[numb] != 1) {
					visit[numb] = 1;
					queue[rear].number = numb;
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
	for (int i = 0; i < num; i++) {
		int start_num;
		front = 0; rear = 0;
		m_total = 100001;
		for (int i = 1000; i < 10000; i++)
			visit[i] = 0;
		cin >> start_num >> dest_num;
		visit[start_num] = 1;
		queue[rear].number = start_num;
		queue[rear].total = 0;
		rear++;

		bfs();
		if (m_total != 100001)
			cout << m_total << endl;
		else
			cout << "impossible" << endl;
	}
}
