#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	list<char> l;
	auto pos = l.end();

	int M;
	cin >> M;
	cin.ignore();

	//Ŀ���� ���� ���̻���
	//Ŀ���� ����Ű�� ���ڴ� �ٷ� ������
	while (M--)
	{
		list<char> l;
		auto pos = l.end();
		string s;
		getline(cin, s);
		for (int i = 0;i < s.size();i++) {
			if (s[i] == '<')
			{
				if (pos != l.begin())
					pos--;
			}
			else if (s[i] == '>')
			{
				if (pos != l.end())
					pos++;
			}
			else if (s[i] == '-')
			{
				if (pos != l.begin())
					pos = l.erase(--pos); //erase�� ��ȯ�� ������ �� ������
			}
			else
				l.insert(pos, s[i]);
		}
		for (auto& c : l)
			cout << c;
		cout << "\n";
	}

	return 0;
}