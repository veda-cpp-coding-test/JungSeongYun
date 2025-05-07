#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

char board[1002][1002];
int dist_j[1002][1002];
int dist_f[1002][1002];
int n, m;
int dx[4] = { 1,0, -1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {

		cin >> m >> n;

		queue<pair<int, int>> qu_j, qu_f;

		for (int i = 0;i < n;i++) {
			fill(dist_j[i], dist_j[i] + m, -1);
			fill(dist_f[i], dist_f[i] + m, -1);
			for (int j = 0;j < m;j++) {
				cin >> board[i][j];
				if (board[i][j] == '@') {
					qu_j.push({ i,j });
					dist_j[i][j] = 0;
				}
				else if (board[i][j] == '*') {
					qu_f.push({ i,j });
					dist_f[i][j] = 0;
				}
			}
		}

		while (!qu_f.empty()) {
			pair<int, int> cur = qu_f.front();
			qu_f.pop();
			for (int dir = 0;dir < 4;dir++) {
				int nx = cur.first + dx[dir];
				int my = cur.second + dy[dir];
				if (nx < 0 || nx >= n || my < 0 || my >= m) continue;
				if (dist_f[nx][my] >= 0 || board[nx][my] == '#') continue;
				dist_f[nx][my] = dist_f[cur.first][cur.second] + 1;
				qu_f.push({ nx, my });
			}
		}
		int stp = false;
		while (!qu_j.empty()) {
			if (stp) break;
			pair<int, int> cur = qu_j.front();
			qu_j.pop();
			for (int dir = 0;dir < 4;dir++) {
				int nx = cur.first + dx[dir];
				int my = cur.second + dy[dir];
				if (nx < 0 || nx >= n || my < 0 || my >= m) {
					cout << dist_j[cur.first][cur.second] + 1 << "\n";
					stp = true;
					break;
				}
				if (board[nx][my] == '#' || dist_j[nx][my] > 0) continue;
				if (dist_f[nx][my] != -1 && dist_f[nx][my] <= dist_j[cur.first][cur.second] + 1) continue;
				dist_j[nx][my] = dist_j[cur.first][cur.second] + 1;
				qu_j.push({ nx, my });
			}
		}
		if (!stp)
			cout << "IMPOSSIBLE" << "\n";
	}

	return 0;
}