#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	int D = A * B * C;
	
	string s = to_string(D);
	int arr[10]{};

	for (auto& c : s)
		arr[c - '0']++;

	for (int i = 0;i < 10;i++)
		cout << arr[i] << "\n";

	return 0;
}