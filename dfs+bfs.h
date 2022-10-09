#ifndef INCLUDE
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vec = vector<T>;
#endif

struct graph {
    vec<bool> used;
    vec<vec<int>> edges;
    vec<int> d;
    int n;
    graph(int n) : n(n) {
        edges.assign(n + 1, {});
    }

    void read(int k) {
        while (k--) {
            int x, y; cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
    }

    void read_tree_by_ancestors() {
        for (int i = 2; i <= n; ++i) {
            int x; cin >> x;
            edges[i].push_back(x);
            edges[x].push_back(i);
        }
    }

    auto dfs(int s) {
        used.assign(n + 1, {});
        return __dfs(s);
    }

    auto bfs(int s) {
        used.assign(n + 1, {});
        return __bfs(s);
    }

    void __dfs(int s) {
        used[s] = true;
        for (auto v : edges[s])
            if (!used[v])
                __dfs(v);
    }

    void __bfs(int s) {
        queue<int> q;
        q.push(s);
        used[s] = true;
        d[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : edges[u])
                if (!used[v])
                {
                    q.push(v);
                    used[v] = true;
                    d[v] = d[u] + 1;
                }
        }
    }
};