#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
  ll n;
  cin >> n;
  ll mod = 1e9 + 7;
  vector<ll> dp(n + 1, 0);
  dp[0] = 1;
  for(int i = 1; i <= n; i++){
    for(int y = 1; y <= 6; y++){
      if(i - y >= 0){
        dp[i] = (dp[i] + dp[i - y]) % mod;
      }
    }
  }
  cout << dp[n];
