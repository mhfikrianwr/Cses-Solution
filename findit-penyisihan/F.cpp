#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M, L, R;
    cin >> N >> M >> L >> R;

    vector<long long> fact(N + 1), invfact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;

    invfact[N] = modpow(fact[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % MOD;

    auto C = [&](long long n, long long k) -> long long {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    };

    // Hitung banyak solusi:
    // a1 + ... + aM = N
    // L <= ai <= R
    //
    // bi = ai - L
    // b1 + ... + bM = N - M*L
    // 0 <= bi <= R-L

    long long S = N - M * L;
    long long U = R - L;

    if (S < 0 || S > M * U) {
        cout << 0 << '\n';
        return 0;
    }

    long long waysEnergy = 0;

    for (long long j = 0; j <= M; j++) {
        long long rem = S - j * (U + 1);
        if (rem < 0) break;

        long long term = C(M, j) * C(rem + M - 1, M - 1) % MOD;

        if (j & 1) waysEnergy = (waysEnergy - term + MOD) % MOD;
        else waysEnergy = (waysEnergy + term) % MOD;
    }

    long long ans = C(N, M) * waysEnergy % MOD;
    cout << ans << '\n';

    return 0;
}
