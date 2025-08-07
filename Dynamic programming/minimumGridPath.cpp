#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ii pair<int,int>

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};
void solve() {
    int n; cin >> n;
    char mtrks[n][n];
    vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{-1,-1}));
    for(int i = 0; i < n; i++){
        for(int y = 0 ; y < n; y++){
            cin >> mtrks[i][y];
        }
    }
    int l = 0, r = 0;
    while(l < n && r < n){
        cout << mtrks[l][r];
        if(mtrks[l + 1][r] < mtrks[l][r - 1]){
            l++;
        }else{
            r--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}