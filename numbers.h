#ifndef INCLUDE
#include "include.h"
#endif

ll gcd(ll x, ll y) {
    while (y) {
        x %= y;
        swap(x, y);
    }
    return abs(x);
}

void create_primes() {
    ll N;
    vec<bool> prime(N + 1, true);
    vec<ll> primes;
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= N; ++i)
        if (prime[i]) {
            for (ll j = i * i; j <= N; j += i)
                prime[j] = false;
            primes.push_back(i);
        }
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
arr<ll, 3> prim_deg(ll x) {
    ll p = 1;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            p = i;
            break;
        }
    if (p == 1)
        if (x > 1)
            return {1, 1, x};
        else
            return {0, 0, 0};
    else {
        ll k = 0;
        while (x % p == 0)
            x /= p, ++k;
        return {x == 1, k, p};
    }
}

struct mfr {
    ll x, y;
    mfr(ll x = 0, ll y = 1) : x(x), y(y) {}

    mfr &operator+=(const mfr &a) {
        x = (x * a.y + a.x * y) % mod;
        y = (a.y * y) % mod;
        return *this;
    }

    mfr &operator-=(const mfr &a) {
        x = truemod(x * a.y - a.x * y, mod);
        y = (a.y * y) % mod;
        return *this;
    }

    mfr &operator*=(const mfr &a) {
        x = (x * a.x) % mod;
        y = (y * a.y) % mod;
        return *this;
    }

    mfr &operator/=(const mfr &a) {
        x = (x * a.y) % mod;
        y = (y * a.x) % mod;
        return *this;
    }

    friend mfr operator+(mfr a, const mfr &b) {
        a += b;
        return a;
    }
    friend mfr operator-(mfr a, const mfr &b) {
        a -= b;
        return a;
    }

    friend mfr operator*(mfr a, const mfr &b) {
        a *= b;
        return a;
    }

    friend mfr operator/(mfr a, const mfr &b) {
        a /= b;
        return a;
    }

    mfr operator-() const { return mfr() - *this; }

    friend istream &operator>>(istream &is, mfr &m) {
        ll x;
        is >> x;
        m = mfr(x);
        return is;
    }

    friend ostream &operator<<(ostream &os, const mfr &m) { return os << m.x << " " << m.y; }
};

// mod-arithmetic operations, but exp and div only for primary mod
struct mint {
    ll x;
    mint(ll x = 0) : x(truemod(x, mod)){};

    static ll powmod(ll base, ll exponent, const ll &modulus) {
        base %= modulus;
        ll result = 1;
        while (exponent) {
            if (exponent & 1)
                result = (result * base) % modulus;
            base = (base * base) % modulus;
            exponent >>= 1;
        }
        return result;
    }

    // only for primary mod [or for 0 <= exp < mod-1]
    void exp(ll exp) { x = powmod(x, truemod(exp, mod - 1), mod); }

    mint &operator+=(const mint &a) {
        ll y = x + a.x;
        x = y - (y >= mod) * mod;
        return *this;
    }

    mint &operator-=(const mint &a) {
        ll y = x - a.x;
        x = y + (y < 0) * mod;
        return *this;
    }

    mint &operator*=(const mint &a) {
        x = (x * a.x) % mod;
        return *this;
    }

    // only for primary mod
    mint &operator/=(const mint &a) {
        x = (x * powmod(a.x, mod - 2, mod)) % mod;
        return *this;
    }

    friend mint operator+(mint a, const mint &b) {
        a += b;
        return a;
    }

    friend mint operator-(mint a, const mint &b) {
        a -= b;
        return a;
    }

    friend mint operator*(mint a, const mint &b) {
        a *= b;
        return a;
    }

    friend mint operator/(mint a, const mint &b) {
        a /= b;
        return a;
    }

    mint operator-() { return mod - x; }

    mint &operator++() {
        x = x < mod - 1 ? x + 1 : 0;
        return *this;
    }

    mint operator++(int) {
        mint a(*this);
        ++*this;
        return a;
    }

    mint &operator--() {
        x = x > 0 ? x - 1 : mod - 1;
        return *this;
    }

    mint operator--(int) {
        mint a(*this);
        --*this;
        return a;
    }

    friend bool operator==(const mint &a, const mint &b) { return a.x == b.x; }

    friend bool operator!=(const mint &a, const mint &b) { return a.x != b.x; }

    friend bool operator>(const mint &a, const mint &b) { return a.x > b.x; }

    friend bool operator<(const mint &a, const mint &b) { return a.x < b.x; }

    friend bool operator>=(const mint &a, const mint &b) { return a.x >= b.x; }

    friend bool operator<=(const mint &a, const mint &b) { return a.x <= b.x; }

    friend istream &operator>>(istream &is, mint &m) {
        ll x;
        is >> x;
        m = x;
        return is;
    }

    friend ostream &operator<<(ostream &os, const mint &m) { return os << m.x; }
};