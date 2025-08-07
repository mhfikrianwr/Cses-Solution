#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,ans = 0; cin >> n >> m;
    const int mod = 1e9 + 7;
    vector<long long> v(n);
    vector<vector<long long>> dp(n,vector<long long>(m + 2,0));
    for(auto &x : v) cin >> x;
    for(int i=0; i<n; i++){
        if(i == 0 && v[0] == 0){
            for(int y=1; y<=m; y++){
                dp[i][y] = 1;  
            }
        }else if(i == 0 && v[0] != 0){
            dp[i][v[i]] = 1;
        }else{
            if(v[i] == 0){
                for(int y=1; y<=m; y++){
                    dp[i][y] += (dp[i-1][y] + dp[i-1][y+1]  + dp[i-1][y-1])%mod;
                }
            }else{
                dp[i][v[i]] = (dp[i-1][v[i]] + dp[i-1][v[i]-1] + dp[i-1][v[i] + 1]) % mod;
            }
        }
    }

    for(int i=1; i<=m; i++){
        ans += dp[n-1][i] % mod;
    }
    //dbg
    // for(int i=0; i<n; i++){
    //     for(int y=1; y<=m; y++){
    //         cout << dp[i][y] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans % mod;    
}