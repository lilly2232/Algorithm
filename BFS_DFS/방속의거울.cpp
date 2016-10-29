// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#define MAX 1002
#define INF 987654321
using namespace std;
char arr[MAX][MAX];
int visit[MAX][MAX];
int num;
int cnt = 0;

int sol(int x, int y, int dir)
{
	if (visit[x][y]== 0) {
		visit[x][y] = 1;
	}
	
	
	if (arr[x][y] == '2') {
		if (dir == 1) {
			for (int i = x + 1; i < num; i++)
				if (arr[i][y] - 48 > 0) {
					if (visit[i][y] == 0)
						return  1 + sol(i, y, 4);
					else
						return sol(i, y, 4);
				}
		}
		else if (dir == 2) {
			for (int i = x - 1; i > -1; i--)
				if (arr[i][y] - 48 > 0) {
					if (visit[i][y] == 0)
						return  1 + sol(i, y, 3);
					else
						return sol(i, y, 3);
				}
		}
		else if (dir == 3) {
			for (int i = y - 1; i > -1; i--)
				if (arr[x][i] - 48 > 0) {
					if (visit[x][i] == 0)
						return 1 + sol(x, i, 2);
					else
						return  sol(x, i, 2);
				}
		}
		else if (dir == 4) {
			for (int i = y + 1; i < num; i++)
				if (arr[x][i] - 48 > 0) {
					if (visit[x][i] == 0)
						return  1 + sol(x, i, 1);
					else
						return  sol(x, i, 1);
				}
		}
	}
	if (arr[x][y] == '1') {
		if (dir == 1) {
			for (int i = x - 1; i > -1; i--)
				if (arr[i][y] - 48 > 0) {
					if (visit[i][y] == 0)
						return 1 + sol(i, y, 3);
					else
						return  sol(i, y, 3);
				}

		}
		else if (dir == 2) {
			for (int i = x + 1; i < num; i++)
				if (arr[i][y] - 48 > 0) {
					if (visit[i][y] == 0)
						return  1 + sol(i, y, 4);
					else
						return  sol(i, y, 4);

				}
		}
		else if (dir == 3) {
			for (int i = y + 1; i < num; i++)
				if (arr[x][i] - 48 > 0) {
					if (visit[x][i] == 0)
						return  1 + sol(x, i, 1);
					else
						return  sol(x, i, 1);
				}
		}
		else if (dir == 4) {
			for (int i = y - 1; i > -1; i--)
				if (arr[x][i] - 48 > 0) {
					if (visit[x][i] == 0)
						return  1 + sol(x, i, 2);
					else
						return  sol(x, i, 2);
				}
		}
	}
	return 0;
}
int main(int argc, char** argv) {
		/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
		������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
		���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
		�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
		����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
		��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
		//freopen("input.txt", "r", stdin);

		setbuf(stdout, NULL);

		int TC;
		int test_case;

		scanf("%d", &TC);	// cin ��� ����
		for (test_case = 1; test_case <= TC; test_case++) {
			// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.

			cin >> num;
			for (int i = 0; i < num; i++)
				cin >> arr[i];
			for (int i = 0; i < num; i++)
				for (int j = 0; j < num; j++)
					visit[i][j] = 0;

			// �� �κп��� ������ ����Ͻʽÿ�.
			printf("Case #%d\n", test_case);	// cout ��� ����
			int i = 0;
			for (; i < num; i++)
				if (arr[0][i] == '1' || arr[0][i] == '2') {
					cout << sol(0, i, 1) + 1 << endl;
					break;
				}
			if (i == num)
				cout << "0" << endl;
		}
		return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
	}
