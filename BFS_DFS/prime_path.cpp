#include <iostream>
using namespace std;
struct MyQueue
{
	int number;
	int total;
};

int arr[100001] = { 0, };	// 0~ 10000까지 사용
int sosu[100001] = { 0, };

int dest_num;
int front = 0;
int rear = 0;
int m_total = 100001;
MyQueue queue[10000000];
int visit[1000001];


void set_prime()
{
	arr[0] = 1;	// 소수가 아님 : 1
	arr[1] = 1;

	int div;
	int k;

	while (1){
		for ( k = 2; k < 100000; k++) 
			if (arr[k] == 0)
			{								//  남아있는 수들중 가장 작은 수 찾기 
				sosu[k] = 1;	
				arr[k] = 1;
				break;
			}

		if (k > 10000)
			break;

		for (int i = 0 ; i < 10000; i++)	// 해당 수로 나눠지는 것들은 소수 아님 : 1 
			if (arr[i] != 1 && i % k == 0)
				arr[i] = 1; 			
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

				if (sosu[numb] == 1 && visit[numb] != 1) {
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

	int start_num;

	cin >> start_num >> dest_num;

	set_prime();

	visit[start_num] = 1;
	queue[rear].number = start_num;
	queue[rear].total = 0;
	rear++;

	bfs();
	cout << m_total << endl;
	
}