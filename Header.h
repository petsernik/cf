#ifndef INCLUDE
#include <bits/stdc++.h>
#include <random>
#define all(x) (x).begin(), (x).end()
using namespace std;

using ll = long long;
template<class T> using vec = vector<T>;
const ll inf = (ll)1e18;
const ll mod = 998244353;

random_device rd;
mt19937 mt(rd());
#endif

vec<vec<ll>> C;
void calcC(ll n)
{
    C = vec<vec<ll>>(n + 1, vec<ll>(n + 1));
    for (int i = 0; i <= n; ++i)
    {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

ll truemod(ll a, ll modulus = mod) {
    a = a % modulus;
    return a + (a < 0) * modulus;
}

bool prime(ll x) {
    if (x == 1)
        return false;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

struct preffix_sum {
    preffix_sum(vector<ll> &a) {
        ll n = a.size();
        pref = vector<ll>(n + 1);
        for (int i = 0; i < n; ++i)
            pref[i + 1] = pref[i] + a[i];
    }
    vector<ll> pref;
    ll operator [](int i) {
        return pref[i];
    }
};

struct suffix_sum {
    suffix_sum(vector<ll> &a) {
        ll n = a.size();
        suff = vector<ll>(n + 1);
        for (int i = n - 1; i >= 0; --i)
            suff[i] = suff[i + 1] + a[i];
    }
    vector<ll> suff;
    ll operator [](int i) {
        return suff[i];
    }
};


template<typename T>
struct tecvect {
    vector<T> a;
    int center;
    // tecvect<ll> a(n);
    tecvect(int maxIndex, T val = T()) {
        center = maxIndex;
        a = vector<T>(2 * center + 1, val);
    }
    T &operator[](int i) {
        return a[center + i];
    }
};

template<typename T>
ll bin_search(vector<T> &a, ll x) {
    ll n = a.size();
    ll l, r;
    l = 0; r = n;
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
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

vector<vector<ll>> ans;
void backpack(vector<ll> &w, vector<ll> &p, ll W) { // sum(w)<=W, sum(p)=max = ans[W][n]
    ll n = p.size();
    ans = vector<vector<ll>>(W + 1, vector<ll>(n + 1));
    for (int i = 0; i <= W; ++i)
        for (int j = 1; j <= n; ++j)
            if (i >= w[j - 1])
                ans[i][j] = max(ans[i - w[j - 1]][j - 1] + p[j - 1], ans[i][j - 1]);
            else
                ans[i][j] = ans[i][j - 1];
}

vector<ll> res;
void backpack_res(vector<ll> &w, vector<ll> &p, ll W) { // sum(w)<=W, sum(p)=max = ans[W][n]
    ll n = p.size();
    res = vector<ll>();
    for (ll i = W, j = n; j > 0; --j) {
        if (ans[i][j] != ans[i][j - 1]) {
            res.push_back(j - 1);
            i -= w[j - 1];
        }
    }
    reverse(res.begin(), res.end());
}

bool prime(ll x) {
    if (x == 1)
        return false;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

// return { is deg of prime, deg min prime, min prime }
vector<ll> prim_deg(ll x) {
    ll p = 1;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            p = i;
            break;
        }
    if (p == 1)
        return x > 1 ? vector<ll>{ 1, 1, x } : vector<ll>{ 0, 0, 0 };
    else {
        ll k = 0;
        while (x % p == 0)
            x /= p, ++k;
        return { x == 1, k, p };
    }
}

void sieve_eratosthene() {
    ll n;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; ++i)
        if (prime[i])
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
}

ll gcd(ll x, ll y) {
    while (y) {
        x %= y;
        swap(x, y);
    }
    return x;
}

void scanline() {
    int n; cin >> n;
    vector<ll> a(n), b(n);
    vector<vector<ll>> sl;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        sl.push_back({ a[i], 1 }); // open
        sl.push_back({ b[i], -1 }); // close
    }
    sort(sl.begin(), sl.end(),
        [&](auto a, auto b)
        {return a[0] < b[0] || a[0] == b[0] && a[1] > b[1]; });
}

struct mfr {
    ll x, y;
    mfr(ll x = 0, ll y = 1) : x(x), y(y) {}

    static ll truemod(ll a, ll modulus = mod) {
        a = a % modulus;
        return a + (a < 0) * modulus;
    }

    mfr &operator +=(const mfr &a) {
        x = (x * a.y + a.x * y) % mod;
        y = (a.y * y) % mod;
        return *this;
    }

    mfr &operator -=(const mfr &a) {
        x = truemod(x * a.y - a.x * y);
        y = (a.y * y) % mod;
        return *this;
    }

    mfr &operator *=(const mfr &a) {
        x = (x * a.x) % mod;
        y = (y * a.y) % mod;
        return *this;
    }

    mfr &operator /=(const mfr &a) {
        x = (x * a.y) % mod;
        y = (y * a.x) % mod;
        return *this;
    }

    friend mfr operator +(mfr a, const mfr &b) {
        a += b;
        return a;
    }
    friend mfr operator -(mfr a, const mfr &b) {
        a -= b;
        return a;
    }

    friend mfr operator *(mfr a, const mfr &b) {
        a *= b;
        return a;
    }

    friend mfr operator /(mfr a, const mfr &b) {
        a /= b;
        return a;
    }

    mfr operator -() const {
        return mfr() - *this;
    }

    friend istream &operator >>(istream &is, mfr &m) {
        ll x;
        is >> x;
        m = mfr(x);
        return is;
    }

    friend ostream &operator <<(ostream &os, const mfr &m) {
        return os << m.x << " " << m.y << "\n";
    }
};