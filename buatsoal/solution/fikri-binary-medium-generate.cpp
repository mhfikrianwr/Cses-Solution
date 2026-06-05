#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(istream& in, ostream& out){
    ll n;
    in >> n;
    vector<ll> v(n);
    ll mx = -1;
    for (auto &x : v) {
        in >> x;
        mx = max(mx, x);
    }
    ll sum = 0;
    ll current = 1;
    map<ll,ll> ones, zeros;
    while (current <= mx) {
        for (auto &x : v) {
            if (x & current) ones[current]++;
            else zeros[current]++;
        }
        current = (current << 1LL);
    }
    current = 1;
    ll banyak = 1;
    while (current <= mx) {
        if (ones[current] >= zeros[current]) {
            sum += (current * ones[current]);
            if(ones[current] == zeros[current]) banyak *= 2LL;
        } else {
            sum += (current * zeros[current]);
        }
        current = (current << 1LL);
    }
    out << sum <<  " " <<  banyak <<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist_tc(1, 1000);
    uniform_int_distribution<int> dist_n(1, 10);
    uniform_int_distribution<int> dist_val(1, 1000);

    for (int i = 1; i <= 40; i++) {
        string path = "../Fikri and His Binary Assignment(Medium)/data/secret/";

        ofstream finput(path + to_string(i) + ".in");
        int tc = dist_tc(rng);
        finput << tc << "\n";

        for (int t = 0; t < tc; t++) {
            int n = dist_n(rng);
            finput << n << "\n";
            for (int j = 0; j < n; j++) {
                finput << dist_val(rng) << (j + 1 == n ? '\n' : ' ');
            }
        }
        finput.close();

        ifstream cinFile(path + to_string(i) + ".in");
        ofstream coutFile(path + to_string(i) + ".ans");

        int testcases;
        cinFile >> testcases;
        while (testcases--) {
            solve(cinFile, coutFile);
        }

        cinFile.close();
        coutFile.close();
    }

    return 0;
}
