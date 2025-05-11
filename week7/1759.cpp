#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> v1; //input
vector<char> v2; //output

bool chk_a(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void func(int idx, int k) {
    if (k == L) {
        int cnt_a = 0, cnt_b = 0;
        for (const auto& c : v2) {
            chk_a(c) ? cnt_a++ : cnt_b++;
        }
        if (cnt_a >= 1 && cnt_b >= 2) {
            for (const auto& c : v2) cout << c;
            cout << '\n';
        }
        return;
    }

    for (int i = idx; i < C; i++) {
        v2.push_back(v1[i]);
        func(i + 1, k + 1);
        v2.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> L >> C;
    char tmp;
    for (int i = 0;i < C;i++) {
        cin >> tmp;
        v1.push_back(tmp);
    }
    sort(v1.begin(), v1.end());
    func(0, 0);

    return 0;
}