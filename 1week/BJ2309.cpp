#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 9,
		sum = 0,
		stp = 0;

	vector<int> v(N);
	for (auto& i : v) {
		cin >> i;
		sum += i;
	}

	for (int i = 0;i < N - 1;i++) {
		if (stp) break;
		for (int j = i + 1;j < N;j++) {
			if ((sum - v[i] - v[j]) == 100) {
				v.erase(v.begin() + i);
				v.erase(v.begin() + j - 1);
				stp = 1;
				break;
			}
		}
	}
	sort(v.begin(), v.end());

	for (auto& i : v)
		cout << i << "\n";

	return 0;
}