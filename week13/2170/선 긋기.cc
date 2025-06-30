#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, ans=0;
    cin >> N;
    vector<pair<int,int>> v(N);
    for(int i=0;i<N;i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());
    int ll=v[0].first, rr=v[0].second;
    for(int i=1;i<N;i++){
        int ff=v[i].first, ss=v[i].second;
        if(ss<=rr) continue;
        if(ff<=rr) rr=ss;
        else{
            ans += rr-ll;
            ll=ff;
            rr=ss;
        }  

    }
    ans += rr-ll;

    cout << ans;
    
    return 0;
}