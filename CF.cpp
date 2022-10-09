#define INCLUDE
#include <bits/stdc++.h>
#include <random>
using namespace std;
template<class T> using vec = vector<T>;
//#define __128
#if defined(__128) && defined(__GNUC__)
using ll = __int128; using ld = __float128;
#else
using ll = long long; using ld = long double;
#endif

#ifdef __GNUC__
auto &operator>>(istream &is, __int128 &x) { long long e;  is >> e; x = e; return is; }
auto &operator>>(istream &is, __float128 &x) { long double e;  is >> e; x = e; return is; }
auto &operator<<(ostream &os, __int128 &x) { os << (long long)x; return os; }
auto &operator<<(ostream &os, __float128 &x) { os << (long double)x; return os; }
#endif

#define all(a) (a).begin(), (a).end()
#define myset(T, cmp) multiset<T, function<bool(T,T)>> s([&](T a, T b){return cmp;})
#define print(ans) cout << ans << "\n"
#define fore(a) for (auto &e : (a))
#define dtype(a) decltype(a)
#define bit(a,i) (((a)>>(i))&1LL)
#define mask(a,x) ((a)&(x))

template<class T> auto sort(T &a) { sort(all(a)); }
template<class T, class N> auto sort(T &a, N pr) { sort(all(a), pr); }
template<class T> auto rsort(T &a) { sort(all(a), [](auto &a, auto &b) {return a > b; }); }
template<class T> auto rsort(T f, T l) { sort(f, l, [](auto &a, auto &b) {return a > b; }); }
template<class T, class N> auto low(T &a, const N &x) { return lower_bound(all(a), x); }
template<class T, class N> auto low(T f, T l, const N &x) { return lower_bound(f, l, x); }
template<class T, class N, class M> auto low(T f, T l, const N &x, M pr) { return lower_bound(f, l, x, pr); }
template<class T, class N> auto upp(T &a, const N &x) { return upper_bound(all(a), x); }
template<class T, class N> auto upp(T f, T l, const N &x) { return upper_bound(f, l, x); }
template<class T, class N, class M> auto upp(T f, T l, const N &x, M pr) { return upper_bound(f, l, x, pr); }
template<class T> auto rev(T &a) { reverse(all(a)); }
template<class T> auto rev(T f, T l) { reverse(f, l); }
template<class T> auto mne(T &a) { return min_element(all(a)); }
template<class T> auto mne(T f, T l) { return min_element(f, l); }
template<class T, class N> auto mne(T &a, N pr) { return min_element(all(a), pr); }
template<class T, class N> auto mne(T f, T l, N pr) { return min_element(f, l, pr); }
template<class T> auto mxe(T &a) { return max_element(all(a)); }
template<class T> auto mxe(T f, T l) { return max_element(f, l); }
template<class T, class N> auto mxe(T &a, N pr) { return max_element(all(a), pr); }
template<class T, class N> auto mxe(T f, T l, N pr) { return max_element(f, l, pr); }
template<class T, class N> auto min(T a, N b) { return sizeof(a) > sizeof(b) ? min(a, (T)b) : min((N)a, b); }
template<class T, class N> auto max(T a, N b) { return sizeof(a) > sizeof(b) ? max(a, (T)b) : max((N)a, b); }

template<class T> auto &operator>>(istream &is, vec<T> &x) { fore(x) is >> e; return is; }
template<class T> auto &operator>>(istream &is, vec<vec<T>> &x) { fore(x) is >> e; return is; }
template<class T> auto &operator<<(ostream &os, vec<T> &x) { fore(x) os << e << " "; return os; }
template<class T> auto &operator<<(ostream &os, vec<vec<T>> &x) { fore(x) os << e << "\n"; return os; }

template<class T> auto bbeg(T &a) { return a.begin(); }
template<class T> auto eend(T &a) { return a.end(); }

random_device rd;
mt19937 mt(rd());

const ll inf = (ll)1e18;
const ll mod = 998244353;



void precalc() {
    
}

// get i-th bit from a:                            #DEFINE bit(a,i) (((a)>>(i))&1LL)
// x is a group like indicator:                    bit(x,i) == 1  iff  i in x
// intersection group a and group x:               #DEFINE mask(a,x) ((a)&(x))
// MY SNIPPETS: f,fi,fd,fe,ff -- for; v, vv -- vec; s -- string;



#define TESTS
void solve() {

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precalc();
    signed T = 1;
#ifdef TESTS
    cin >> T;
#endif
    while (T--)
        solve();
}