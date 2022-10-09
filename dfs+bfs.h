#ifndef INCLUDE
#include <bits/stdc++.h>
using namespace std;
#endif

struct graph {
    vector<bool> used;
    vector<vector<int>> edges;
    vector<int> d;
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


    void dfs(int s) {
        used[s] = true;
        for (auto v : edges[s])
            if (!used[v])
                dfs(v);
    }

    void bfs(int s) {
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
    
    auto new_dfs(int s) {
        used.assign(n + 1, {});
        return dfs(s);
    }

    auto new_bfs(int s) {
        used.assign(n + 1, {});
        return bfs(s);
    }
};