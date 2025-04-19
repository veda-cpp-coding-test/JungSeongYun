#include <iostream>
#include <vector>
using namespace std;

#define MAX 100000
int arr[MAX]{ 0, };
int head = 0,
rear = 0;

void m_push(int x)
{
	arr[rear++] = x;
}

int m_pop()
{
	if (head == rear) return -1;
	else
		return arr[head++];
}

int m_size()
{
	return rear - head;
}

bool m_empty()
{
	if (head == rear) return 1;
	return 0;
}

int m_front()
{
	if (head == rear) return -1;
	return arr[head];
}

int m_back()
{
	if (head == rear) return -1;
	return arr[rear - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v;

	int N;
	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			m_push(x);
		}
		else if (s == "pop")	v.push_back(m_pop());
		else if (s == "size")	v.push_back(m_size());
		else if (s == "empty")	v.push_back(m_empty());
		else if (s == "front")	v.push_back(m_front());
		else v.push_back(m_back());
	}

	for (auto& i : v)
		cout << i << "\n";

	return 0;
}