#ifndef INCLUDE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#endif

struct dsu {
    vector<ll> parent, rank;
    dsu(ll n) : parent(vector<ll>(n + 1)), rank(vector<ll>(n + 1)) {
        for (ll i = 0; i <= n; ++i)
            make_set(i);
    };

    void make_set(ll v) {
        parent[v] = v;
        rank[v] = 0;
    }

    ll find_set(ll v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(ll a, ll b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                ++rank[a];
        }
    }
};

template<class T>
struct dsumap {
    multimap<T, T> parent;
    multimap<T, ll> rank;

    void make_set(T v) {
        parent[v] = v;
        rank[v] = 0;
    }

    T find_set(const T &v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(T a, T b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                ++rank[a];
        }
    }
};