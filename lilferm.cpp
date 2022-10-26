#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;


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








int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    long long x;
    cin >> x;
    cout << inverse(x) << endl;
    cout << (inverse(x) * x ) % MOD << endl;

}