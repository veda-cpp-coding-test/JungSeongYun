#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	stack<int> st;
	vector<char> vc;

	int s = 0;
	for (int i = 0;i < n;i++)
	{
		int a;
		cin >> a;

		if (a > s) {
			for (int j = s + 1;j <= a;j++) {
				st.push(j);
				vc.push_back('+');
			}
			s = a;
			st.pop();
			vc.push_back('-');
		}
		else {
			if (a > st.top()) {
				cout << "NO";
				return 0;
			}
			st.pop();
			vc.push_back('-');
		}
	}

	for (auto& c : vc)
		cout << c << "\n";

	return 0;
}