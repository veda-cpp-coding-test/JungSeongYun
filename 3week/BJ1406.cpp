#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	list<char> l;
	for (auto& c : s)
		l.push_back(c);
	
	auto pos = l.end();

	int M;
	cin >> M;
	cin.ignore();

	while (M--)
	{
		getline(cin, s);
		if ((s[0] == 'L') && (pos != l.begin()))
			pos--;
		else if ((s[0] == 'D') && (pos != l.end()))
			pos++;
		else if ((s[0] == 'B') && (pos != l.begin()))
			pos = l.erase(--pos); //erase의 반환은 삭제한 값 다음
		else if (s[0] == 'P')
			l.insert(pos, s[2]);
	}

	for (auto& c : l)
		cout << c;

	return 0;
}