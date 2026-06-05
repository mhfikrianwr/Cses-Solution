#include <bits/stdc++.h>
using namespace std;

#define gg ios::sync_with_stdio(false); cin.tie(nullptr);

// output pair with cout 
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

// print container 
template<typename T_container,
         typename T = typename enable_if<
             !is_same<T_container, string>::value,
             typename T_container::value_type
         >::type>
ostream& operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

// debug printing 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

//#define LOCAL
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ll long long
#define ld long double

#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vl> 
#define vpl vector<pair<ll, ll>>
#define pb push_back
#define fr first
#define sc second

#define ml map<ll,ll>
#define mc map<char,ll>

#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x));
#define RSORT(x) sort(x.rbegin(),x.rend());

const ll INF = LLONG_MAX;
const ll NINF = LLONG_MIN;

#define endl "\n"
#define en "\n"
#define cen cout << "\n"

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
const char move[] = {'D','R','U','L'};

bool valid(ll k, const vl &v) {
    vl cnt(k, 0);
    vl spare;

    for (ll x : v) {
        if (x < k) {
            cnt[x]++;
        } else {
            spare.pb(x);
        }
    }

    for (ll i = 0; i < k; i++) {
        while (cnt[i] > 1) {
            spare.pb(i);
            cnt[i]--;
        }
    }

    SORT(spare);

    ll ptr = 0;

    for (ll i = 0; i < k; i++) {
        if (cnt[i] > 0) continue;

        ll need = (i == 0 ? 1 : 2 * i + 1);

        while (ptr < (ll)spare.size() && spare[ptr] < need) {
            ptr++;
        }

        if (ptr == (ll)spare.size()) return false;

        ptr++;
    }

    return true;
}

void solve() {
    ll n;
    cin >> n;

    vl v(n);
    for (auto &x : v) cin >> x;

    SORT(v);

    ll l = 0, r = n, ans = 0;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (valid(mid, v)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << en;
}

int main() {
    gg;

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}
