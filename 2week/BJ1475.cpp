#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int max1 = 0;
	string s;
	cin >> s;

	int arr[10]{};
	for (auto& c : s)
		arr[c - '0']++;

	int gap= abs(arr[6] - arr[9]);
	gap = (gap & 1) ? (gap / 2 + 1) : (gap / 2);
	arr[6] = min(arr[6], arr[9]) + gap;

	for (int i = 0;i < 9;i++) 
		max1 = max(max1, arr[i]);

	cout << max1;

	return 0;
}