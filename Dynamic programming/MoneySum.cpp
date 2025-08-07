#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, sum = 0; 
    cin >> n;
    vector<int> v(n);
    for(auto &x : v){
        cin >> x;
        sum += x;
    }
    vector<bool> dp(sum + 1,false);
    dp[0] = true;
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int y = sum - v[i]; y>=0; y--){
            if(dp[y]){
                if(!dp[y + v[i]]) ans++;
                dp[y + v[i]] = true;
            }
        }
    }
    cout << ans << "\n";
    for(int i=1; i<=sum; i++){
        if(dp[i]) cout << i << " ";
    }

}