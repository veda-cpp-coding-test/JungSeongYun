#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N;
        long long ans=0;
        cin >> N;
        vector<int> v(N);
        for(int i=0;i<N;i++)
            cin >> v[i];
        int maxx=v[N-1];
        for(int i=N-1;i>=0;i--){
            if(v[i]>maxx){
                maxx = v[i];
                continue;
            }
            ans += maxx - v[i];
        }
        cout << ans <<'\n'; 
    }
    
    return 0;
}