#include <iostream>
#include <vector>
using namespace std;

#define MAX 2000000

int queue[MAX];
int front = 0,
rear = 0;

void push_Back(int num) {
	if (rear < MAX) queue[rear++] = num;
}

int pop_Front() {
	if (front == rear) return -1;
	else  return queue[front++];
}

int it_Size() {
	return (rear - front);
}

bool is_Empty() {
	return (front == rear);
}

int get_Front() {
	if (front == rear) return -1;
	else return queue[front];
}

int get_Back() {
	if (front == rear) return -1;
	else return queue[rear - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num,
		x;
	string command;
	vector<int> v;

	cin >> num;
	while (num--)
	{
		cin >> command;
		if (command == "push") {
			cin >> x;
			push_Back(x);
		}
		else if (command == "pop") v.push_back(pop_Front());
		else if (command == "size") v.push_back(it_Size());
		else if (command == "empty") v.push_back(is_Empty());
		else if (command == "front") v.push_back(get_Front());
		else if (command == "back") v.push_back(get_Back());
	}

	//Ãâ·Â
	for (auto& i : v)
		cout << i << "\n";

	return 0;
}