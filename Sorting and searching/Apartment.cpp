#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<ll,ll>> v;
    int arr[n];
    int indx1 = 0, indx2 = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        v.push_back(make_pair((arr[i]-k),(arr[i]+k)));
    }
    sort(v.begin(),v.end());
    vector<ll> apart(m);
    for(int i=0; i<m; i++){
        cin >> apart[i];
    }
    int ans = 0;
    sort(apart.begin(),apart.end());
    while(indx1 < n && indx2 < m){
        ll a = v[indx1].first, b = apart[indx2], c = v[indx1].second;
        if((a <=b ) && (c >= b)){
            ans++;
            indx1++;
            indx2++;
        }else if(a > b){
            indx2++;
        }else{
            indx1++;
        }
    }
    cout << ans;
}