#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N,
		X;
	cin >> N >> X;

	vector<int> v(N, 0);
	for (auto& i : v) {
		cin >> i;
		if (i < X) cout << i << " ";
	}
	return 0;
}