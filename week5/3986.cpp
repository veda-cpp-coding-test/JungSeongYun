#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	stack<int> s;
	int cnt = 0;

	while (N--) {
		stack<int> s;
		string ss;
		cin >> ss;
		for (const auto& c : ss) {
			if (s.empty()) s.push(c);
			else {
				if (c == s.top()) s.pop();
				else s.push(c);
			}
		}
		if (s.empty()) cnt++;
	}

	cout << cnt;

	return 0;
}