#include <iostream>
#include <vector>
using namespace std;

#define MX 100000

int arr[2 * MX + 1]{ 0, };
int head = MX,
rear = MX;

void m_push_front(int x)
{
	arr[--head] = x;
}

void m_push_back(int x)
{
	arr[rear++] = x;
}

int m_pop_front()
{
	if (head == rear) return -1;
	return arr[head++];
}

int m_pop_back()
{
	if (head == rear) return -1;
	return arr[--rear];
}

int m_size()
{
	return rear - head;
}

int m_empty()
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
		if (s == "push_front") {
			int x;
			cin >> x;
			m_push_front(x);
		}
		else if (s == "push_back") {
			int x;
			cin >> x;
			m_push_back(x);
		}
		else if (s == "pop_front")
			v.push_back(m_pop_front());
		else if (s == "pop_back")
			v.push_back(m_pop_back());
		else if (s == "size")
			v.push_back(m_size());
		else if (s == "empty")
			v.push_back(m_empty());
		else if (s == "front")
			v.push_back(m_front());
		else
			v.push_back(m_back());
	}

	for (auto& i : v)
		cout << i << "\n";

	return 0;
}