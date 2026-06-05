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
void solve() {
    ll n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    string ans_a = "", ans_b = "";
    bool x = 1;
    for(int i = 0 ; i < n; i++){
        if(a[i] == b[i]){
            ans_a += a[i];
            ans_b += b[i];
        }else{
            if(x){
                ans_a += '(';
                ans_b += ')';
            }else{
                ans_a += ')';
                ans_b += '(';
            }
            x ^= 1;
        }
    }
    x = 1;
    ll cnt_a = 0, cnt_b = 0;
    for(ll i = 0 ; i < n; i++){
        if(ans_a[i] == '(') cnt_a++; else cnt_a--;
        if(ans_b[i] == '(') cnt_b++; else cnt_b--;
        if(cnt_a < 0 || cnt_b < 0){
            cout << "NO\n";
            return;
        }
    }
    if(cnt_a != 0 || cnt_b != 0) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}