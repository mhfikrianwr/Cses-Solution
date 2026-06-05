#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
  string a,b;
  cin >> a >> b;
  vector<pair<ll,ll>> v1,v2;
  int cnt = 1;
  for(int i = 1; i < a.size(); ++i){
    if(a[i] == a[i - 1]) ++cnt;
    else{
      v1.push_back({a[i - 1] - '0',cnt});
      cnt = 1;
    }
  }
  v1.push_back({a[a.size() - 1],cnt});
  cnt = 1;
  for(int i = 1; i < b.size(); ++i){
    if(b[i] == b[i - 1]) ++cnt;
    else{
      v2.push_back({b[i-1] - '0',cnt});
      cnt = 1;
    }
  }
  v2.push_back({b[b.size() - 1],cnt});
  if(v1.size() != v2.size()){
    cout << "NO\n";
  }else{
    for(int i = 0; i < v1.size(); ++i){
      if(v1[i].first != v2[i].first || v2[i].second < v1[i].second || v2[i].second > v1[i].second * v1[i].first){
        cout << "NO\n";
        return;
      } 

    }
    cout << "YES\n";
  }
}
int main(){
  int tc; cin >> tc; while(tc--) solve();
}
