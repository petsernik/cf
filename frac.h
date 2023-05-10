#ifndef INCLUDE
#include <iostream>
#include <string>
using namespace std;
using ll = long long;
using ld = long double;
#endif

struct frac {
    ll x, y;
    frac(ll x = 0, ll y = 1) {
        ll g = gcd(x, y);
        g = ((y > 0) ^ (g < 0)) ? g : -g; // y/g > 0
        this->x = x / g;
        this->y = y / g;
    };

    template <class T> frac(T x = 0, T y = 1) { *this = frac((ll)x, (ll)y); }

    template <class T, class N> frac(T x = 0, N y = 1) { *this = frac((ll)x, (ll)y); }

    frac(double f) {
        string s = to_string(f);
        auto p = s.find('.');
        string t = s.substr(0, p), m = s.substr(p + 1);
        ll x = stoi(t), y = stoi(m);
        ll pow = 1, sz = m.size();
        while (sz--)
            pow *= 10;
        *this = x + frac(y, pow);
    }

    frac(ld f) { *this = frac((double)f); }

    static ll gcd(ll a, ll b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    frac &operator+=(const frac &a) { return *this = frac(x * a.y + y * a.x, y * a.y); }

    frac &operator-=(const frac &a) { return *this = frac(x * a.y - y * a.x, y * a.y); }

    frac &operator*=(const frac &a) { return *this = frac(x * a.x, y * a.y); }

    frac &operator/=(const frac &a) { return *this = frac(x * a.y, y * a.x); }

    friend frac operator+(frac a, const frac &b) { return a += b; }

    friend frac operator-(frac a, const frac &b) { return a -= b; }

    friend frac operator*(frac a, const frac &b) { return a *= b; }

    friend frac operator/(frac a, const frac &b) { return a /= b; }

    frac operator-() const { return frac(-x, y); }

    friend bool operator==(const frac &a, const frac &b) { return a.x * b.y == a.y * b.x; }

    friend bool operator!=(const frac &a, const frac &b) { return a.x * b.y != a.y * b.x; }

    friend bool operator>(const frac &a, const frac &b) { return a.x * b.y > a.y * b.x; }

    friend bool operator<(const frac &a, const frac &b) { return a.x * b.y < a.y * b.x; }

    friend bool operator>=(const frac &a, const frac &b) { return a.x * b.y >= a.y * b.x; }

    friend bool operator<=(const frac &a, const frac &b) { return a.x * b.y <= a.y * b.x; }

    friend istream &operator>>(istream &is, frac &m) {
        ll x, y;
        is >> x >> y;
        m = frac(x, y);
        return is;
    }

    friend ostream &operator<<(ostream &os, const frac &m) {
        return os << (long double)((ld)m.x / m.y);
    }
};