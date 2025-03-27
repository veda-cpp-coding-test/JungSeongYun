#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N = 5,
		sum = 0;
	vector<int> v(N);

	for (int i = 0;i < N;i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	
	cout << sum / N << "\n"
		<< v[N / 2];

	return 0;
}