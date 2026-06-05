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


ll solve1(ll n,vector<ll> &v, map<ll,ll> &l,map<ll,ll> &r){
    ll left = l[0] - 1, right =  r[0] + 1;
    set<ll> s1;
    s1.insert(0);
    while(left >= 0 && right < 2 * n){
        if(v[left] == v[right]) s1.insert(v[left]);
        else break;
        --left;
        ++right;
    }

    left = l[0] + 1;
    right = r[0] - 1;
    while(left <= right){
        if(v[left] == v[right]) s1.insert(v[left]);
        else return 0;
        ++left;
        --right;
    }
    ll cur = 0;
    for(ll x : s1){
        if(x != cur) break;
        ++cur;
    }
    return cur;
}

ll solve2(ll n,vector<ll> &v,map<ll,ll> &l,map<ll,ll> &r){
    ll left = l[0] - 1, right = l[0] + 1;
    set<ll> s1,s2;
    while(left >= 0 && right < 2 * n){
        if(v[left] == v[right]) s1.insert(v[left]);
        else break;
        --left;
        ++right;
    }
    left = r[0] - 1;
    right = r[0] + 1;
    while(left >= 0 && right < 2 * n){
        if(v[left] == v[right]) s2.insert(v[left]);
        else break;
        --left;
        ++right;
    }

    ll ans1 = 0, ans2 = 0;
    s1.insert(0);
    s2.insert(0);
    for(ll x : s1){
        if(ans1 != x) break;
        ++ans1;
    }
    for(ll x : s2){
        if(ans2 != x) break;
        ++ans2;
    }

    return max(ans1,ans2);
} 
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};
void solve(int count) {
    ll n;
    cin >> n;
    vector<ll> v(2 * n);
    map<ll,ll> l,r;
    bool found = false;
    for(int i = 0; i < 2 * n; i++){
        cin >> v[i];
        if(v[i] == 0){
            if(!found){
                l[0] = i;
                found = true;
            }else{
                r[0] = i;
            }
        }
    }
    // if(count == 270){
    //     for(auto x : v) cout << x;
    //     cout << "\n";
    //     return;
    // }
    ll ans1 = solve1(n,v,l,r);
    ll ans2 = solve2(n,v,l,r);
    cout << max(ans1,ans2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    int count = 1;
    while (tc--) {
        solve(count); ++count;
    }
    return 0;
}