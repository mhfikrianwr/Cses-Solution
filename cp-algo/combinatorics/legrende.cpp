#include <bits/stdc++.h>
using namespace std;

vector<bool> prime(1000,true);

void solvePrime(int n,int k){
  int ans = 0;
  while(n){
    ++ans;
    n /= k;
  }
  cout << "ans : " << ans << "\n";
}

void solveComp(int n,int k){
  // pilih pembagi terbesar prima untuk bil k, kemudian lakukan hal yang sama dengan solvePrime
}


int main(){
  for(int i = 2; i * i <= 1000; ++i){
    if(prime[i]){
      for(int y = 2 * i; y <= 1000; ++y) prime[y] = false;
    }
  }

  int n = 12;
  int k = 3;
  if(prime[n]){
    solvePrime(n,k);
  }else{
    solveComp(n,k);
  }
}
