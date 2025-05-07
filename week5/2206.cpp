#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

char board[1002][1002];
int dist[1002][1002][2];
int n, m;
int dx[4]{ 1,0,-1,0 };
int dy[4]{ 0,1,0,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	queue < pair<pair<int, int>, int>> qu;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];
			fill(dist[i][j], dist[i][j] + 2, -1);
		}
	}

	dist[0][0][0] = 1;

	qu.push({ {0,0}, 0 });
	while (!qu.empty()) {
		pair<pair<int, int>, int> cur = qu.front();
		qu.pop();
		if (cur.first.first == (n - 1) && cur.first.second == (m - 1)) {
			cout << dist[n - 1][m - 1][cur.second];
			return 0;
		}

		for (int i = 0;i < 4;i++) {
			int nx = cur.first.first + dx[i];
			int my = cur.first.second + dy[i];
			if (nx < 0 || nx >= n || my < 0 || my >= m) continue;
			//벽이면 + 부수기전이면
			if (board[nx][my] == '1') {
				if (cur.second == 0 && dist[nx][my][1] == -1) {
					dist[nx][my][1] = dist[cur.first.first][cur.first.second][0] + 1;
					qu.push({ {nx,my}, 1 });
				}
			}
			//벽아니면			
			else {
				if (dist[nx][my][cur.second] == -1) {
					dist[nx][my][cur.second] = dist[cur.first.first][cur.first.second][cur.second] + 1;
					qu.push({ {nx,my}, cur.second });
				}
			}
		}
	}

	cout << -1;

	return 0;
}