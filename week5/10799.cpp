#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	int cnt = 0;

	stack<char> st;
	bool r_rep = false;
	for (auto c : s) {
		if (c == '(') {
			st.push(c);
			r_rep = false;
		}
		else {
			if (st.size() > 1 && !r_rep) {
				st.pop();
				cnt += st.size();
			}
			else if (r_rep) {
				st.pop();
				cnt++;
			}
			else
				st.pop();
			r_rep = true;
		}
	}

	cout << cnt;

	return 0;
}