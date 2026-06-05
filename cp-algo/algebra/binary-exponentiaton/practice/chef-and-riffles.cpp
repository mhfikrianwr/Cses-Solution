#include <bits/stdc++.h>
using namespace std;


#define int long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define ll long long


vector<int> applyPerm(vector<int> &seq,vector<int> &riffles){
  int n = riffles.size();
  vector<int> newSeq(n);
  for(int i = 0; i < n; ++i) newSeq[i] = seq[riffles[i]];
  return newSeq;
}

vector<int> perm(vector<int> &seq,vector<int> &riffles,int k){
  while(k > 0){
    if(k & 1){
      seq = applyPerm(seq,riffles);
    }

    riffles = applyPerm(riffles,riffles);
    k >>= 1;
  }
  return seq;
}

void solve(){
  ll n,k;
  cin >> n >> k;
  vector<int> seq(n),v(n),riffles;
  for(int i = 0; i < n; i++) v[i] = i + 1;
  for(int i = 0; i < n; ++i) seq[i] = i;
  for(int i = 0; i<n; i+=2) riffles.push_back(i);
  for(int i = 1; i <n; i+=2) riffles.push_back(i);
  seq = perm(seq,riffles,k);

  for(int i = 0; i < n; i++) cout << v[seq[i]] << " ";
  cout << "\n";
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);   
  int tc;
  cin >> tc;
  while(tc--) solve();
}
