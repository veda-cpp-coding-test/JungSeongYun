#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<long long> vec;

void func() {
	for (auto& i : vec) {
		string s = to_string(i);
		reverse(s.begin(), s.end());
		while (s[0] == '0')
			s.erase(s.begin());
		i = stoll(s);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vec.resize(N);

	for (int i = 0; i < N; i++)
		cin >> vec[i];

	func();
	sort(vec.begin(), vec.end());
	for (const auto& i : vec)
		cout << i << '\n';

	return 0;
}