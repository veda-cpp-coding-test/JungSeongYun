#include <iostream>
#include <map>
#include <set>
using namespace std;

int vis[100002];
int N, M, R;
int ord = 0;

void dfs(map<int, set<int>>& m, int R) {
	ord++;
	vis[R] = ord;
	if (!m[R].empty()) {
		for (auto& i : m[R]) {
			if (vis[i] == 0) dfs(m, i);
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

	for (int i = 1;i <= N;i++) {
		cout << vis[i] << "\n";
	}

	return 0;
}