#include <iostream>
using namespace std;
int k;
int m_min = 1000000;
int n;

struct myQueue {

	int here;
	int count;
};

myQueue queue[100000000];
int check[100001] = { 0, };
int front = 0;
int rear = 0;

void catchcow()
{
	while (front != rear) {
		
	myQueue q_here = queue[front++];
	
	int here = q_here.here;
	int count = q_here.count;
	check[here] = 1;

		if (here == k)
		{
			if (count < m_min)
				m_min = count;
			return;
		}

		myQueue q_next;

			if (here + 1 <= 100000 && check[here +1] == 0) {
				q_next.here = here + 1;
				q_next.count = count + 1;
				check[here+1] = 1;
				queue[rear++] = q_next;
			}
			if (here - 1 >= 0 && check[here -1] == 0) {
				q_next.here = here - 1;
				q_next.count = count + 1;
				check[here-1] = 1;
				queue[rear++] = q_next;
			}
			if ((here * 2) <= 100000 && check[here*2] == 0) {
				q_next.here = (here * 2);
				q_next.count = count + 1;
				check[here*2] = 1;
				queue[rear++] = q_next;
			}
		}
}

int main()
{

	cin >> n >> k;

	myQueue start;
	start.count = 0;
	start.here = n;
	queue[rear++] = start;
	catchcow();

	cout << m_min << endl;
}