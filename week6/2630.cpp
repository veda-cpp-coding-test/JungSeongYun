#include <iostream>
using namespace std;

int board[128][128];
int wcnt = 0, bcnt = 0;

void func(int n, int r, int c) {
	if (n == 1) {
		board[r][c] ? bcnt++ : wcnt++;
		return;
	}

	bool flag = board[r][c];

	for (int i = r;i < r + n;i++) {
		for (int j = c;j < c + n;j++) {
			if (flag != board[i][j]) {
				int half = n / 2;
				func(half, r, c);
				func(half, r, c + half);
				func(half, r + half, c);
				func(half, r + half, c + half);
				return;
			}
		}
	}
	flag ? bcnt++ : wcnt++;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			cin >> board[i][j];

	func(N, 0, 0);

	cout << wcnt << "\n" << bcnt;

	return 0;
}