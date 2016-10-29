#include <iostream>
#define MAX 10000001
#define QMAX 10000000	
using namespace std;
int arr[MAX][2] = { 0, };
int visit[MAX] = { 0, };
int p, q;
int n, m;
int m_queue[QMAX];
int front = 0;
int rear = 0;
bool result = false;

void bfs (int p, int q)
{
	m_queue[rear++] = p;
	while (front != rear)
	{
		int here = m_queue[front++];
		visit[here] = 1;

		if (here == q) {
			cout << "yes" << endl;
			result = true;
			return;
		}
		for (int i = 0; i < m; i++)
			if (visit[arr[i][1]] != 1 && arr[i][0] == here)
				m_queue[rear++] = arr[i][1];
	}

	for (int i = 0; i <MAX; i++) 
		visit[i] = 0;

	front = 0;
	rear = 0;
	m_queue[rear++] = q;
	while (front != rear)
	{
		int here = m_queue[front++];
		visit[here] = 1;

		if (here == p) {
			cout << "no" << endl;
			result = true;
			return;
		}
		for (int i = 0; i < m; i++)
			if (visit[arr[i][1]] != 1 && arr[i][0] == here)
				m_queue[rear++] = arr[i][1];
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> arr[i][0] >> arr[i][1];
	cin >> p >> q;

	bfs(p,q);
	if (result == false)
		cout << "unknown" << endl;
}