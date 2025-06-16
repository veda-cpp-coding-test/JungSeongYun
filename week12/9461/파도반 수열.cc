#include <iostream>
#include <vector>
using namespace std;

vector<long long> v(102);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    v[1]=1, v[2]=1, v[3]=1, v[4]=2, v[5]=2;
    for(int i=6;i<=100;i++)
        v[i]=v[i-1]+v[i-5];

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        cout << v[N] << '\n';
    }

    return 0;
}