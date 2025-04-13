#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	list<int> l;
	vector<int> v;

	int N, K;
	cin >> N >> K;
	cin.ignore();
	for (int i = 1;i <= N;i++)
		l.push_back(i);
	auto pos = l.begin();

	while (N--)
	{
		for (int i = 0;i < K - 1;i++)
		{
			pos++;
			if (pos == l.end())	pos = l.begin();
		}
		v.push_back(*pos);
		pos = l.erase(pos);
		if (pos == l.end())	pos = l.begin();
	}

	//Ãâ·Â
	cout << '<';
	for (int i = 0;i < v.size() - 1;i++)
		cout << v[i] << ", ";
	cout << v[(v.size() - 1)] << '>';

	return 0;
}