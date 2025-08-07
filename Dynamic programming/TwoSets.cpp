#include <bits/stdc++.h>
using namespace std;
int mod_inv(int a, int m) {
    int res = 1, exp = m - 2;
    while (exp) {
        if (exp % 2) res = (1LL * res * a) % m;
        a = (1LL * a * a) % m;
        exp /= 2;
    }
    return res;
}
int main(){
    const int mod = 1e9 + 7;
    int n; cin >> n;
    int sum = (n*(n+1))/2;
    if(sum%2 == 1){
        cout << 0;
        return 0;
    }
    int z = sum / 2;
    vector<long long>dp(z+1,0);
    dp[0] = 1;
    for(int i = 1;i <= n; i++){
        for(int y = z - i; y >= 0; y--){
            dp[y + i] += dp[y];
            dp[y + i] %= mod;
        }
    }
    cout << (dp[z] * mod_inv(2,mod)) % mod;
}