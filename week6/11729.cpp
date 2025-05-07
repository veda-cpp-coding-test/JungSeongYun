#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
vector<pair<int, int>> v;

void func(int a, int b, int n) {
	if (n == 1) {
		//cout << a << ' ' << b << '\n';
		v.push_back({ a,b });
		ans++;
		return;
	}
	func(a, 6 - a - b, n - 1);
	func(a, b, 1);
	func(6 - a - b, b, n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	func(1, 3, N);

	cout << ans << '\n';
	for (auto& p : v)
		cout << p.first << ' ' << p.second << '\n';

	return 0;
}