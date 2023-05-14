#ifndef INCLUDE
#include "include.h"
#endif

vec<vec<ll>> C;
void calcmodC(ll n = N) {
    C = vec<vec<ll>>(n + 1, vec<ll>(n + 1));
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; ++j)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
}

vec<ll> fib;
void calcmodfib(ll n = N) {
    fib = vec<ll>(n + 1, 1);
    for (int i = 2; i <= n; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
}

struct prefsum {
    prefsum(vec<ll> &a) {
        ll n = a.size();
        pref = vec<ll>(n + 1);
        for (int i = 0; i < n; ++i)
            pref[i + 1] = pref[i] + a[i];
    }
    vec<ll> pref;
    ll operator[](int i) { return pref[i]; }
};

struct suffsum {
    suffsum(vec<ll> &a) {
        ll n = a.size();
        suff.resize(n + 1);
        for (int i = n - 1; i >= 0; --i)
            suff[i] = suff[i + 1] + a[i];
    }
    vec<ll> suff;
    ll operator[](int i) { return suff[i]; }
};

void nothing() { int n; }

template <typename T> struct cevec {
    vec<T> a;
    int center;
    // cevec<ll> a(n);
    cevec(int maxIndex, T val = T()) {
        center = maxIndex;
        a = vec<T>(2 * center + 1, val);
    }
    T &operator[](int i) { return a[center + i]; }
};

template <typename T> ll bin_search(vec<T> &a, ll x) {
    ll n = a.size();
    ll l, r;
    l = 0;
    r = n;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (a[m] > x)
            r = m;
        else
            l = m;
    }
    return l;
}

ll powmod(ll base, ll exp, ll modulus = mod) {
    base %= modulus;
    ll result = 1 % modulus;
    while (exp) {
        if (exp & 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

vec<vec<ll>> ans;
void backpack(vec<ll> &w, vec<ll> &p, ll W) { // sum(w)<=W, sum(p)=max = ans[W][n]
    ll n = p.size();
    ans = vec<vec<ll>>(W + 1, vec<ll>(n + 1));
    for (int i = 0; i <= W; ++i)
        for (int j = 1; j <= n; ++j)
            if (i >= w[j - 1])
                ans[i][j] = max(ans[i - w[j - 1]][j - 1] + p[j - 1], ans[i][j - 1]);
            else
                ans[i][j] = ans[i][j - 1];
}

vec<ll> res;
void backpack_res(vec<ll> &w, vec<ll> &p, ll W) { // sum(w)<=W, sum(p)=max = ans[W][n]
    ll n = p.size();
    res = vec<ll>();
    for (ll i = W, j = n; j > 0; --j) {
        if (ans[i][j] != ans[i][j - 1]) {
            res.push_back(j - 1);
            i -= w[j - 1];
        }
    }
    reverse(res.begin(), res.end());
}

void scanline() {
    ll n;
    cin >> n;
    vec<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    for (ll i = 0; i < n; ++i)
        cin >> b[i];
    vec<vec<ll>> sl;
    for (ll i = 0; i < n; ++i) {
        sl.push_back({a[i], 1});  // open
        sl.push_back({b[i], -1}); // close
    }
    sort(sl.begin(), sl.end(), lmd(a, b, a[0] < b[0] || a[0] == b[0] && a[1] > b[1]));
}