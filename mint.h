#ifndef INCLUDE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
#endif

struct mint {
    ll x;
    mint(ll x = 0) : x(truemod(x, mod)) {};

    static ll truemod(ll a, ll modulus) {
        a = a % modulus;
        return a + (a < 0) * modulus;
    }
    static ll powmod(ll base, ll exp, const ll &modulus) {
        base %= modulus;
        ll result = 1;
        while (exp) {
            if (exp & 1) result = (result * base) % modulus;
            base = (base * base) % modulus;
            exp >>= 1;
        }
        return result;
    }

    // only for primary mod [or for 0 <= exp < mod-1]
    void exp(ll exp) {
        x = powmod(x, truemod(exp, mod - 1), mod);
    }

    mint &operator +=(const mint &a) {
        ll y = x + a.x;
        x = y - (y >= mod) * mod;
        return *this;
    }

    mint &operator -=(const mint &a) {
        ll y = x - a.x;
        x = y + (y < 0) * mod;
        return *this;
    }

    mint &operator *=(const mint &a) {
        x = (x * a.x) % mod;
        return *this;
    }

    // only for primary mod
    mint &operator /=(const mint &a) {
        x = (x * powmod(a.x, mod - 2, mod)) % mod;
        return *this;
    }

    friend mint operator +(mint a, const mint &b) {
        a += b;
        return a;
    }

    friend mint operator -(mint a, const mint &b) {
        a -= b;
        return a;
    }

    friend mint operator *(mint a, const mint &b) {
        a *= b;
        return a;
    }

    friend mint operator /(mint a, const mint &b) {
        a /= b;
        return a;
    }

    mint operator -() const {
        return mod - x;
    }

    friend bool operator ==(const mint &a, const mint &b) {
        return a.x == b.x;
    }

    friend bool operator !=(const mint &a, const mint &b) {
        return a.x != b.x;
    }

    friend istream &operator >>(istream &is, mint &m) {
        ll x;
        is >> x;
        m = x;
        return is;
    }

    friend ostream &operator <<(ostream &os, const mint &m) {
        return os << m.x;
    }
};