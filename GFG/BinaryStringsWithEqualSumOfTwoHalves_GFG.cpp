class Solution {
  public:
    static const int mod = 1000000007;
    using ll = long long;
    long long power(ll a, ll b){
        ll res = 1;
        while(b) {
            if(b & 1) res = (res * a) % mod;
            a = (a*a) % mod;
            b >>= 1;
        }
        return res;
    }
    int computeValue(int n) {
        vector<ll> f(2 * n + 1);
        f[0] = 1;
        for(int i = 1; i <= 2 * n; i++) {
            f[i] = (f[i-1] * i ) % mod;
        }
        ll d = (f[n] * f[n]) % mod;
        return (f[2*n] * power(d, mod-2)) % mod;
    }
};
