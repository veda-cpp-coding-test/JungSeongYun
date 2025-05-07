#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;	//입력순서
vector<int> pos(100002);	//입력순서의 인덱스

map<int, vector<int>> m;
int vis[100002];
int ord = 0;

void dfs(int x) {
	if (vis[x]) return;
	vis[x] = ++ord;
	for (auto& i : m[x]) {
		if (vis[i] == 0) dfs(i);
	}
}

bool cmp(int a, int b) {
	return pos[a] < pos[b];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0;i < N - 1;i++) {
		int aa, bb;
		cin >> aa >> bb;
		m[aa].push_back(bb);
		m[bb].push_back(aa);
	}

	for (int i = 0;i < N;i++) {
		int a;
		cin >> a;
		v.push_back(a);
		pos[v[i]] = i;
	}

	//map 정렬
	for (auto& mv : m) {
		auto& cur = mv.second;
		sort(cur.begin(), cur.end(), cmp);
	}

	dfs(1);

	for (int i = 0;i < N;i++) {
		if (vis[v[i]] != i + 1) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;

	return 0;
}