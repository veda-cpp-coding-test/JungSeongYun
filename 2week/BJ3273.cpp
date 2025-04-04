#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000001]{};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,
		x,
		cnt = 0;

	cin >> n;
	vector<int> v(n);
	for (auto& i : v) {
		cin >> i;
		arr[i]++;
	}
	cin >> x;
	
	for (auto& i : v) {
		int a = x - i;
		if (a > 1000000 || a < 0) continue;
		if (arr[a]) cnt++;
	}

	cout << cnt/2;

	return 0;
}