#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,sum;
    cin >> n >> sum;
    int coin[n];
    int dp[sum+1];
    for(int i=0; i<n; i++) {
        cin >> coin[i];
    }
    sort(coin,coin+n,greater<int>());
    memset(dp,0,sizeof(dp));
    dp[0] = 0;
    for(int i=1; i<=sum; i++){
        for(int y=0; y<n; y++){
            if(coin[y] <= n){
                dp[i] = dp[i] + dp[i-coin[y]] + 1;
                break;
            }
        }
    }
    for(int i : dp) cout << i << " ";
    //cout << dp[sum];
}