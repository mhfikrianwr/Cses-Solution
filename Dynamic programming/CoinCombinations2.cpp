#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    const int mod = 1e9 + 7;
    vector<int> num(n),dp(m+1,0),dps(m+1,false);
    dps[0] = true;
    dp[0] = 1;
    for(int i=0; i<n; i++){
        cin >> num[i];
        for(int y=0; y<=m - num[i]; y++){
            if(dps[y]){
                dps[y + num[i]] = true;
                dp[y + num[i]] = (dp[y+num[i]] + dp[y]) % mod;
            }
        }
    }
    cout << dp[m] % mod;

}