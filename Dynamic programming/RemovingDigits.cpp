#include <bits/stdc++.h>
using namespace std;
int main(){
        int n; cin >> n;
        int dp[n+1];
        if(n <= 9){
            cout << 1;
            return 0;
        }
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            int maks = -1;
            if(i <= 9) dp[i] = 1;
            else{
                int b = i;
                while(b > 0){
                    maks = max(maks,b%10);
                    b /= 10;
                }
                // cout <<i << " " <<maks << endl;
                dp[i] = dp[i-maks] + 1;
            }
        }
         cout << dp[n] ;
}