#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    vector<pair<int,int>> q(n);
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        q[i].first = x;
    }
    for(int i=0; i<n; i++){
        cin >> x;
        q[i].second = x;
    }
    vector<int> dp(m+1,0);
    vector<bool> dps(m+1,false);
    int ans = 0;
    dps[0] = true;
    for(int i=0; i<n; i++){
        for(int y=m-q[i].first; y>=0; y--){
            int b = y + q[i].first;
            if(dps[y]){
                dp[b] = max(dp[b],dp[y] + q[i].second);
                dps[b] = true;
                ans = max(ans,dp[b]);
            }
        }
    }
    cout << ans;
}