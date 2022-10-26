#include <iostream>
using namespace std;

long long const MOD =1e9 + 7;
int const N = 1e5;
long long fact[N+1];
long long inv_fact[N+1];

long long bpow(long long x, long long y) {
    long long res = 1;
    while(y>0){
        if (y&1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y = y >> 1;
    }
    return res;
}

long long inverse(long long n) {
    return bpow(n,MOD-2);
}


/*void precalc(){
    fact[1] = 1;
    for( long long i; i <= N; ++i){
        fact[i] = (fact[i-1] * i) % MOD;
    }
    for(long long i =1; i <= N; ++i) {
        inv_fact[i] = inverse(fact[i]);
    }
} */
long long prob(long long a, long long n){
    return (a * inverse(n)) % MOD;
} 


int main() {
    long long a,n;
    cin >> a >> n;
    cout << prob(a,n) << endl;


}