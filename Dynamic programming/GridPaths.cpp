#include <bits/stdc++.h>
using namespace std;
int main(){
    long long const mod = 1e9 + 7;
    int n; cin >> n;
    long long dp[n][n];
    memset(dp, 0, sizeof dp);
    char paths[n][n];
    for(int i=0; i<n; i++){
        for(int y=0; y<n; y++){
            cin >> paths[i][y];
        }
    }
    for(int i=0; i<n; i++){
        // kolom
        if(i == 0){
            if(paths[0][0] != '*') dp[0][0] = 1;
        }else{
            if((paths[i][0] != '*')&&(dp[i-1][0] != 0)) dp[i][0] = 1;
            if((paths[0][i] != '*')&&(dp[0][i-1] != 0)) dp[0][i] = 1;
        }
    }
    for(int i=1; i<n; i++){
        for(int y=1; y<n; y++){
            if(paths[i][y] == '*') continue;
            if(paths[i-1][y] == '.') dp[i][y] = (dp[i][y] + dp[i-1][y]) % mod;
            if(paths[i][y-1] == '.') dp[i][y] = (dp[i][y] + dp[i][y-1]) % mod;
        }
    } 

    cout << dp[n-1][n-1] % mod;
}