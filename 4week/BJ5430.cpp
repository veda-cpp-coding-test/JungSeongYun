#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<deque<int>> vv;

	int T;
	cin >> T;

	while (T--)
	{
		string s1;
		cin >> s1;

		int n;
		cin >> n;
		
		string s2;
		cin >> s2;
		
		//deque에 넣기
		deque<int> d;
		if (n) {
			string s3;
			for (int i = 1;i < s2.size() - 1;i++) {
				if (s2[i] != ',') s3 += s2[i];
				else {
					d.push_back(stoi(s3));
					s3.clear();
				}
			}
			d.push_back(stoi(s3));
		}

		//함수실행
		bool flag = 0;
		for (auto& c : s1) {
			if (c == 'R')
				flag = !flag;
			else {
				if (d.empty()) {
					//cout << "error" << "\n";
					d.push_back(-1);
					break;
				}
				if (flag)
					d.pop_back();
				else
					d.pop_front();
			}
		}

		//vv에 넣기
		if (d.empty()) d.push_back(-2);
		else if (flag)
			reverse(d.begin(), d.end());
		vv.push_back(d);
	}

	//vv 출력
	for (int i = 0;i < vv.size();i++) {
		if (vv[i][0] == -1)
			cout << "error" << "\n";
		else if (vv[i][0] == -2)
			cout << "[]" << "\n";
		else {
			cout << '[';
			for (int j = 0;j < vv[i].size() - 1;j++)
				cout << vv[i][j] << ',';
			cout << vv[i][vv[i].size() - 1] << ']' << "\n";
		}	
	}

	return 0;
}