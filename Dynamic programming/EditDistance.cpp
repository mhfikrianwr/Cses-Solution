#include <bits/stdc++.h>
using namespace std;
int main(){
    const int maxN = 1e9;
    string a,b; cin >> a >> b;
    int sza = (int)a.length(), szb = (int)b.length();
    vector<vector<int>> dp(sza + 1,vector<int>(szb + 1,maxN));
    for(int i=0; i<=sza; i++){
        for(int y=0; y<=szb; y++){
            int cost;
            if(i == 0 && y == 0){
                dp[i][y] = 0;
            }else if(i == 0){
                dp[i][y] = dp[i][y-1] + 1;
            }else if(y == 0){
                dp[i][y] = dp[i-1][y] + 1;
            }else{
                dp[i][y] = min(dp[i][y],dp[i-1][y] + 1);
                dp[i][y] = min(dp[i][y],dp[i][y-1] + 1);
                if(a[i - 1] ==  b[y - 1]) cost = 0;
                else cost = 1;
                dp[i][y] = min(dp[i][y],dp[i-1][y-1] + cost);
            }
        }
    }
    cout << dp[sza][szb];
}