#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> vin(N);
	vector<int> vou(N);
	for (int i = 0;i < N;i++)
		cin >> vin[i];

	stack<pair<int, int>> stp;
	for (int i = 0;i < N;i++) {
		while (!stp.empty() && vin[i] > stp.top().first)
			stp.pop();
		if (stp.empty()) {
			vou[i] = 0;
			stp.push({ vin[i], i });
		}
		else {
			vou[i] = stp.top().second + 1;
			stp.push({ vin[i], i });
		}
	}

	for (auto& i : vou)
		cout << i << " ";

	return 0;
}