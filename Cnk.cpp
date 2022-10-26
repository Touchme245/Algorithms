#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;
const int N = 1e5;
long long fact[N+1];
long long inv_fact[N+1];


long long bpow(long long x, long long y){
    int res = 1;
    while(y > 0) {
        if (y & 1){
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y = y >> 1;
    }

    return res;
}

long long inverse(long long x){
    return bpow(x, MOD-2);

}

void precalc() {
    fact[1] = 1;
    for (long long i =2; i <= N; ++ i) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    for(long long i = 1; i <= N; ++ i) {
        inv_fact[i] = inverse(fact[i]);
    }
}
long long c(long long n,long long k) {
    return (fact[n] * ((inv_fact[k] * inv_fact[n-k]) % MOD)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long n , k;
    cin >> n >> k;
    precalc();
    cout << c(n,k) << endl;;

}