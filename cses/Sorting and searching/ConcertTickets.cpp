#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m; cin >> n >> m;
    multiset<long long> ticket;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        ticket.insert(a);
    }
    //merge sort
    vector<long long> p(m);
    long long indx = 0;
    for(auto &x : p){
        cin >> x;
        auto it = ticket.upper_bound(x);
        if(it == ticket.begin()){
            cout << -1 << endl;
        }else{
            it--;
            cout << *it << endl;
            ticket.erase(it);
        }
    }
}