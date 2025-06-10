#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<long long> vec;
map<long long, int> mm;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vec.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
		mm[vec[i]]++;
	}

	long long ans = vec[0];
	int temp = mm[vec[0]];
	for (auto& i : vec) {
		if (mm[i] > temp) {
			temp = mm[i];
			ans = i;
		}
		if (mm[i] == temp)
			ans = min(ans, i);
	}
	
	cout << ans;		

	return 0;
}