#include <bits/stdc++.h>
using namespace std;

#define ll long long


void dfs(ll cur,ll par,map<ll,vector<ll>> &m){
    cout << cur << " ";
    for(auto x : m[cur]){
        if(x != par) dfs(x,cur,m);
    }
}
void solve() {
    ll n;
    cin >> n;
    set<ll> s;
    map<ll, vector<ll>> m;
    for(int i = 0; i < n; i++){
        ll a,b;
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
        s.insert(a); s.insert(b);
    }
    for(auto x : s){
        if(m[x].size() == 1){
            dfs(x,-1,m); 
            return;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}