#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M,
		cnt = 0;
	cin >> N >> M;
	deque<int> d;
	deque<int> s1;
	deque<int> s2;
	vector<int> v(N);

	//deque ä���
	for (int i = 1;i <= N;i++)
		d.push_back(i);
	//v�� ����
	for (int i = 0;i < M;i++)
		cin >> v[i];

	for (int i = 0;i < M;i++)
	{
		if (d.front() == v[i]) d.pop_front();
		else {
			while (d.front() != v[i]) {  //���ʺ��� s1
				s1.push_back(d.front());
				d.pop_front();
			}
			while (d.back() != v[i]) {   //�����ʺ��� s2
				s2.push_back(d.back());
				d.pop_back();
			}

			cnt += min(s1.size(), s2.size() + 1); 
			
			d.pop_front();
			int s1s = s1.size(),
				s2s = s2.size();

			for (int j = 0;j < s1s;j++) { //s1 �պ��� d�ڷ�
				d.push_back(s1.front());
				s1.pop_front();
			}
			for (int j = 0;j < s2s;j++) { //s2 �պ��� d������
				d.push_front(s2.front());
				s2.pop_front();
			}
		}
	}

	cout << cnt;

	return 0;
}