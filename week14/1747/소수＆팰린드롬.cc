#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool is_pl(int n) {
    string s = to_string(n), sr = s;
    reverse(sr.begin(), sr.end());
    return s == sr;
}

bool is_pr(int n) {
    if (n == 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    while (N) {
        if (is_pl(N) && is_pr(N)) {
            cout << N;
            break;
        }
        N++;
    }

    return 0;
}