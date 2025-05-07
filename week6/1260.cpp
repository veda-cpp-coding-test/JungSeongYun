#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

int vis[1002];
int N, M, R;
int ord = 0;
void dfs(map<int, set<int>>& m, int R) {
	ord++;
	vis[R] = ord;
	cout << R << " ";
	if (!m[R].empty()) {
		for (auto& i : m[R]) {
			if (vis[i] == 0) dfs(m, i);
		}
	}
}

int vis2[1002];
int ord2 = 1;
queue<int> qu;
void bfs(map<int, set<int>>& m, int R) {
	vis2[R] = ord2;
	qu.push(R);
	while (!qu.empty()) {
		auto cur = qu.front();
		qu.pop();
		cout << cur << " ";
		if (m[cur].empty()) continue;
		for (auto& i : m[cur]) {
			if (vis2[i] == 0) {
				vis2[i] = ++ord2;
				qu.push(i);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> R;

	map<int, set<int>> m;
	for (int i = 0;i < M;i++) {
		int k, v;
		cin >> k >> v;
		m[k].insert(v);
		m[v].insert(k);
	}

	dfs(m, R);
	cout << "\n";
	bfs(m, R);

	/*for (int i = 1;i <= N;i++) {
		cout << vis[i] << " ";
	}
	cout << "\n";
	for (int i = 1;i <= N;i++) {
		cout << vis2[i] << " ";
	}*/

	return 0;
}