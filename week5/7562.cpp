#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int board[1002][1002];
int dist[1002][1002];
int n, m;
int dx[8] = { 2,1,-1,-2,-2,-1, 1, 2 };
int dy[8] = { 1,2, 2, 1,-1,-2,-2,-1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v; //답 저장용

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		m = n;

		pair<int, int> s_pos, e_pos;
		cin >> s_pos.first >> s_pos.second;
		cin >> e_pos.first >> e_pos.second;
		if (s_pos == e_pos) {
			v.push_back(0);
			continue;
		}

		queue<pair<int, int>> qu;

		qu.push(s_pos);

		while (!qu.empty()) {
			if (dist[e_pos.first][e_pos.second] != 0) break;
			pair<int, int> cur = qu.front();
			qu.pop();
			for (int dir = 0;dir < 8;dir++) {

				int nx = cur.first + dx[dir];
				int my = cur.second + dy[dir];

				if (nx < 0 || nx >= n || my < 0 || my >= m) continue;
				if (dist[nx][my] > 0) continue;
				dist[nx][my] = dist[cur.first][cur.second] + 1;
				qu.push({ nx, my });
			}
		}

		v.push_back(dist[e_pos.first][e_pos.second]);
		for (int i = 0;i < n;i++)
			fill(dist[i], dist[i] + n, 0);
	}

	for (const auto& i : v)
		cout << i << "\n";

	return 0;
}