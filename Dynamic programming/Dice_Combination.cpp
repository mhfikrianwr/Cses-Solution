#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;
int main(){
    ll n; cin >> n;
    ll dp[1000001];
    dp[0] = 1;
    for(ll i =1; i<=6; i++){
        dp[i] = pow(2,i-1);
    }
    if(n<=6){
        cout << dp[n];
        return 0;
    }
    for(ll i=7; i<=n; i++){
        dp[i] = 0;
        for(ll y = 1; y<=6; y++){
            dp[i] = (dp[i]+dp[i-y])%mod;
        }       
    }
    cout << dp[n] % mod;
    return 0;
}