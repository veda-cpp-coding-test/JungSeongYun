#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, string>> vp(N);
	vector<pair<int, int>> vp2(N);
	for (int i = 0;i < N;i++) {
		cin >> vp[i].first >> vp[i].second;
		vp2[i].first = vp[i].first;
		vp2[i].second = i;
	}

	sort(vp2.begin(), vp2.end());
	for (int i = 0;i < N;i++)
		cout << vp[vp2[i].second].first << " "
		<< vp[vp2[i].second].second << "\n";

	return 0;
}