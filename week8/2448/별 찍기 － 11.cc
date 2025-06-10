#include <iostream>
using namespace std;

char board[6200][6200]; // (N) * (2N-1)

void func(int n, int r, int c) {
	if (n == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				if (i==2 || (i==0 && j==2) || (i==1 && j==1) || (i==1 && j==3)){
					board[r+i][c+j] = '*';
				}
			}
		}
		return;
	}
	
	int m = n / 2;
	
	func(m, r, c + m);			//위
	func(m, r + m, c);			//아래좌
	func(m, r + m, c + 2 * m);	//아래우

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		fill(board[i], board[i] + 2 * N - 1, ' ');

	func(N, 0, 0);

	//출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}