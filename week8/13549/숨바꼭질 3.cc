#include <iostream>
#include <deque>
using namespace std;

int vis[200002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	fill(vis, vis + 200002, -1);

	deque<int> deq;
	deq.push_back(N);
	vis[N] = 0;

	while (!deq.empty()) {
		auto cur = deq.front();
		deq.pop_front();
		if (cur == K) break;

		int nx = cur * 2;
		if (nx >= 0 && nx < 200000 && vis[nx] == -1) {
			vis[nx] = vis[cur];
			deq.push_front(nx);
		}

		for (int i = 0;i < 2;i++) {
			if (i == 0) nx = cur - 1;
			if (i == 1) nx = cur + 1;
			if (nx < 0 || nx >= 200000) continue;
			if (vis[nx] != -1) continue;
			vis[nx] = vis[cur] + 1;
			deq.push_back(nx);
		}
	}

	cout << vis[K];

	return 0;
}