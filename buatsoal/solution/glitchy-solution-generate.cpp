#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(istream& in, ostream& out){
    string a, b;
    in >> a >> b;
    vector<pair<ll,ll>> v1, v2;
    int cnt = 1;
    for(int i = 1; i < (int)a.size(); ++i){
        if(a[i] == a[i - 1]) ++cnt;
        else{
            v1.push_back({a[i - 1] - '0', cnt});
            cnt = 1;
        }
    }
    v1.push_back({a[(int)a.size() - 1] - '0', cnt});
    cnt = 1;
    for(int i = 1; i < (int)b.size(); ++i){
        if(b[i] == b[i - 1]) ++cnt;
        else{
            v2.push_back({b[i - 1] - '0', cnt});
            cnt = 1;
        }
    }
    v2.push_back({b[(int)b.size() - 1] - '0', cnt});
    if(v1.size() != v2.size()){
        out << "NO\n";
    }else{
        for(int i = 0; i < (int)v1.size(); ++i){
            if(v1[i].first != v2[i].first || v2[i].second < v1[i].second || v2[i].second > v1[i].second * v1[i].first){
                out << "NO\n";
                return;
            }
        }
        out << "YES\n";
    }
}

int main(){
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> dist_tc(1, 1000);
    uniform_int_distribution<int> dist_a_len(1, 100);
    uniform_int_distribution<int> dist_b_len(1, 100);
    uniform_int_distribution<int> dist_char(1, 9);

    string path = "../Glitchy keyboard/data/secret/";

    for(int i = 10; i <= 80; i++){
        ofstream fin(path + to_string(i) + ".in");
        int tc = dist_tc(rng);
        fin << tc << '\n';

        for(int t = 0; t < tc; ++t){
            int n = dist_a_len(rng);
            int m = dist_b_len(rng);
            string a, b;
            for(int j = 0; j < n; ++j) a += char('0' + dist_char(rng));
            for(int j = 0; j < m; ++j) b += char('0' + dist_char(rng));
            fin << a << ' ' << b << '\n';
        }
        fin.close();

        ifstream cinFile(path + to_string(i) + ".in");
        ofstream coutFile(path + to_string(i) + ".ans");

        int tc2;
        cinFile >> tc2;
        while(tc2--) solve(cinFile, coutFile);

        cinFile.close();
        coutFile.close();
    }

    return 0;
}
