#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >>n;
    vector<long long> v(n);
    for(auto &x : v) cin >> x;
    vector<vector<pair<long,long>>> dp(n,vector<pair<long,long>>(n,{0,0}));
    //base cases
    for(int i=0; i<n; i++){
        for(int y=0; y+i<n; y++){
            if(i == 0){
                dp[y][y].first = v[y];
                dp[y][y].second = 0;
            }else{
                int indx2 = y + i;
                long long left2 = dp[y][indx2-1].second + v[indx2],right2 = dp[y][indx2-1].first;
                long long left1 = dp[y+1][indx2].second + v[y],right1 = dp[y+1][indx2].first;
                if(left2 < left1){
                   dp[y][indx2].first = left1;
                   dp[y][indx2].second = right1;
                }else{
                    dp[y][indx2].first = left2;
                    dp[y][indx2].second = right2;
                }
            }
        }
    }
    cout << dp[0][n-1].first;
}