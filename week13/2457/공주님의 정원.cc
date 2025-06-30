#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, ans=0;
    cin >> N;
    vector<pair<int, int>> vp(N);
    for(int i=0;i<N;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vp[i].first=a*100+b;
        vp[i].second=c*100+d;
    }
    sort(vp.begin(), vp.end());
    int cur=301;
    int end=1201;
    int idx=0;
    int mend=0;
    while(cur<end){
        bool chk=false;
        while(idx<N && vp[idx].first<=cur){
            if(vp[idx].second>mend){
                mend = vp[idx].second;
                chk = 1;
            }
            idx++;
        }
        if(!chk){
            ans=0;
            break;
        }
        cur = mend;
        ans++;
    }

    cout << ans;
        
    return 0;
}