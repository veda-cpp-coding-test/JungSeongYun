#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack<char> st;
	int ans = 0;
	int c2 = 0, c3 = 0;

	string s;
	cin >> s;

	for (int i = 0;i < s.size();i++) {
		if (s[i] == '(') {
			st.push(s[i]);
			c2++;
		}
		else if (s[i] == '[') {
			st.push(s[i]);
			c3++;
		}
		else if (s[i] == ')') {
			if (st.empty() || st.top() == '[') {
				cout << 0;
				return 0;
			}
			st.pop();
			c2--;
			if (i && s[i - 1] == '(')
				ans += 2 * pow(2, c2) * pow(3, c3);
		}
		else {
			if (st.empty() || st.top() == '(') {
				cout << 0;
				return 0;
			}
			st.pop();
			c3--;
			if (i && s[i - 1] == '[')
				ans += 3 * pow(2, c2) * pow(3, c3);
		}
	}

	if (!st.empty())
		ans = 0;
	cout << ans;

	return 0;
}