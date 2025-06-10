#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> vec;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	vec.resize(n);
	for(int i=0;i<n;i++){
		cin >> s;
		reverse(s.begin(), s.end());
		vec[i] = stoll(s);
	}
	sort(vec.begin(), vec.end());
	
	for(auto& i : vec)
		cout << i << '\n';

	return 0;
}