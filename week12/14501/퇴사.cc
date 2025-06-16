#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> vin;
vector<int> vans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vin.resize(N+1);
    vans.resize(N+1);

    for(int i=1;i<=N;i++)
        cin >> vin[i].first >> vin[i].second;

    for(int i=1;i<=N;i++){
        int T = vin[i].first;
        int P = vin[i].second;
        vans[i] = max(vans[i], vans[i-1]);
        if(i+T-1 <= N){
            if(i+T-1 <= N){
                vans[i+T-1] = max(vans[i+T-1], vans[i-1]+P);
            }
        }
    }

    cout << vans[N];    

    return 0;
}