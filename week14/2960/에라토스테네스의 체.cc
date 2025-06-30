#include <iostream>
#include <vector>
using namespace std;

int knum(int n, int k) {
    vector<bool> chk(n + 1, true);
    chk[1] = false;
    for (int i = 2; i<=n; i++) {
        if (!chk[i]) continue;
        for (int j = i; j <= n; j += i) {
            if (!chk[j]) continue;
            chk[j] = false;
            k--;
            if (!k) return j;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    cout << knum(N, K);

    return 0;
}