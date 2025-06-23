#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<long long>> v(102, vector<long long>(12));

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= 9; i++)
		v[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		v[i][0] = v[i - 1][1] % 1000000000;
		v[i][9] = v[i - 1][8] % 1000000000;
		for (int j = 1; j <= 8; j++) {
			v[i][j] = v[i - 1][j - 1] + v[i - 1][j + 1];
			v[i][j] %= 1000000000;
		}
	}
	
	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans = (ans + v[N][i]) % 1000000000;

	cout << ans;

	return 0;
}