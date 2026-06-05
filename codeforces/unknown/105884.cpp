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


#define mxn 300005
#define mod 998244353
int n, k, vis[mxn], arr[mxn], p[mxn];
vector<int>facts[mxn];
ll fact[mxn], ifact[mxn];

ll bigmod(ll b, ll p, ll m){
    b%=m;
    ll ret=1, val=b;
    while(p){
        if(p&1) ret=(ret*val)%m;
        val=(val*val)%m, p>>=1;
    }
    return ret;
}

void genfact(){
    fact[0]=fact[1]=ifact[0]=ifact[1]=1;
    for(ll i=2; i<mxn; i++){
        fact[i]=(fact[i-1]*i)%mod;
        ifact[i]=bigmod(fact[i],mod-2,mod);
    }
}

ll ncr(ll n, ll r){
    if(n<0 || r<0 || n<r) return 0;
    return ifact[r]*ifact[n-r]%mod*fact[n]%mod;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    genfact();
    for(int i=2; i<mxn; i++){
        if(!vis[i]){
            for(int j=i; j<mxn; j+=i){
                vis[j]=1;
                facts[j].pb(i);
            }
        }
    }

    int t, tc=1;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0; i<n+2; i++) p[i]=0;

        for(int i=0; i<n; i++){
            cin>>arr[i];
            for(int a : facts[arr[i]]) p[a]++;
        }

        ll ans=0;

        for(int i=2; i<=n; i++){
            if(p[i]){
                ll now = (ncr(n,k) - ncr(n-p[i],k) + mod )%mod;
                now=(now*i)%mod;
                ans=(ans+now)%mod;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}