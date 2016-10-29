#include <iostream>
#define MAX 1000000
using namespace std;
int target, total;
int up, down;
int min_value = MAX;
int cache[MAX];

void dfs(int here, int depth)
{
	if (depth > min_value)
		return;
	if (min_value != MAX && here + up * min_value < target)
		return;
	if (target == here) {
		if (min_value > depth)
			min_value = depth;
		return;
	}
	if (here + up <= total)
		dfs(here + up, depth+1);
	if (here - down >= 1)
		dfs(here - down, depth+1);
}
int main()
{
	int start;
	cin >> total >> start >> target >> up >> down;
	for (int i = 0; i < total + 1;i++)
		cache[i] = -1;
	if ((down == 0 && start > 1) || (up == 0 && start < target)) {
		cout << "use the stairs";
		return 0;
	} else
		dfs(start, 0);
	cout << min_value << endl;
}