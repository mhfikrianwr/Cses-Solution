#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ii pair<int,int>

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};
const ll maxn = 1e8;
void solve() {
    vector<bool> prime(maxn + 1,true);
    for(ll i = 2; i <= maxn; ++i){
        if(prime[i]){
            for(ll y = 1LL * i * i; y <= maxn; y+=i) prime[y] = false;
        }
    }
    ll cnt = 0;
    for(ll i = 2; i <= maxn; ++i){
        if(prime[i]){
            ++cnt;
            if(cnt % 100 == 1) cout << i << "\n";
        }

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}