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
vector<bool> prime(1e6 + 1, true);
vector<ll> pref(1e6 + 1,0);
void solve() {
    ll a;
    cin >> a;
    cout << pref[a] << "\n";
}

bool noZero(ll a){
    string z = to_string(a);
    for(auto c : z) if(c == '0') return false;
    return true;
}
bool allPrime(ll a){
    ll init = 0;
    ll cnt = 1;
    while(a > 0){
        ll digit = a % 10;
        init = init + (digit * cnt);
        if(!prime[init]) return false;
        cnt *= 10LL;
        a /= 10;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin >> tc;
    prime[1] = false;
    for(ll i = 2; i <= 1e6; ++i){
        pref[i] = pref[i - 1];
        if(prime[i]){
            if(allPrime(i) && noZero(i)) pref[i]++;
            for(ll y = i * i; y <= 1e6; y+=i) prime[y] = false;
        }
    }
    while (tc--) {
        solve();
    }
    return 0;
}