#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
vector<int> v;
int isused[10002];
int cnt[10002];

void func(int k) {
	if (k == M) {
		for (int i = 0; i < k; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N;i++) {
		if (i != 0 && v[i] == v[i - 1]) continue;
		if (isused[v[i]]==cnt[v[i]]) continue;
		arr[k] = v[i];
		isused[v[i]]++;
		func(k + 1);
		isused[v[i]]--;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		cnt[a]++;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	func(0);

	return 0;
}