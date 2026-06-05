#include <bits/stdc++.h>
using namespace std;


int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int a,b;
    cin >> a >> b;
    if((a & 1) && (b & 1)) cout << "NO\n";
    else cout << "YES\n";
  }
}
  
