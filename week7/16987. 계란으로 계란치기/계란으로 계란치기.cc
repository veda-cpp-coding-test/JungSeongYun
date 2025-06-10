#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ans=0;
vector<pair<int, int>> vec;

void func(int k){
    if(k==N){
        int brok=0;
        for(int i=0;i<N;i++)
            if(vec[i].first<=0) brok++;
        ans = max(ans, brok);
        return;
    }
    if(vec[k].first<=0){
        func(k+1);
        return;
    }

    bool hitt = false;
    for(int i=0;i<N;i++){
        if(i==k || vec[i].first<=0) continue;
        hitt = true;
        vec[k].first -= vec[i].second;
        vec[i].first -= vec[k].second;
        func(k+1);
        vec[k].first += vec[i].second;
        vec[i].first += vec[k].second;
    }
    if(!hitt) func(k+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    vec.resize(N);
    for(int i=0;i<N;i++)
        cin >> vec[i].first >> vec[i].second;

    func(0);

    cout << ans;

    return 0;
}