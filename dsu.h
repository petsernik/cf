#ifndef INCLUDE
#include <vector>
#include <map>
using namespace std;
#endif

struct dsu {
    vector<int> parent, rank;
    dsu(int n) : parent(vector<int>(n + 1)), rank(vector<int>(n + 1)) {
        for (int i = 0; i <= n; ++i)
            make_set(i);
    };

    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
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
    multimap<T, int> rank;

    void make_set(const T &v) {
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