#include <iostream>
using namespace std;

char board[2200][2200];

void func(int n, int r, int c) {
	if (n == 1) {
		board[r][c] = '*';
		return;
	}
	int m = n / 3;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (i == 1 && j == 1) continue;
			else {
				func(m, r + m * i, c + m * j);
			}
		}
	}	
	return;	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0;i < N;i++)
		fill(board[i], board[i] + N, ' ');

	func(N, 0, 0);

	//Ãâ·Â
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}