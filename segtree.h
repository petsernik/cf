#ifndef INCLUDE
#include <vector>
using namespace std;
#endif

template <typename T> struct segtree {
  private:
    struct node {
        T sum, inheritance;
        bool change_indicator;
        // default value is a neutral element for "+"
        node(T x = T()) : sum(x), inheritance(0), change_indicator(false) {}
        // merge nodes
        friend node operator+(const node &a, const node &b) {
            return node{a.sum + b.sum};
        }
        // operation "+" in node
        void add(T x, int l, int r) {
            sum += (r - l) * x;
            inheritance += x;
        }
        // operation "=" in node
        void change(T x, int l, int r) {
            sum = (r - l) * x;
            inheritance = x;
            change_indicator = 1;
        }
        // update by parent
        void update(const node &parent, int l, int r) {
            if (!parent.change_indicator)
                add(parent.inheritance, l, r);
            else
                change(parent.inheritance, l, r);
        }
        operator T() const { return sum; }
        ostream &operator<<(ostream &ostr) {
            return ostr << sum << " " << inheritance << " " << change_indicator
                        << "\n";
        }
    };
    vector<node> tree;
    int n;

  public:
    // initialization
    segtree(const vector<T> &data) {
        n = (int)data.size();
        tree.resize(4 * n + 1);
        build(1, 0, n, data);
    }
    // operation "+" on [l,r]
    void add(int l, int r, T x) { add(1, 0, n, l, r + 1, x); }
    // operation "=" on [l,r]
    void change(int l, int r, T x) { change(1, 0, n, l, r + 1, x); }
    // get sum on [l,r]
    node query(int l, int r) { return query(1, 0, n, l, r + 1); }

  private:
    void build(int v, int l, int r, const vector<T> &a) {
        if (l == r - 1) {
            tree[v] = node(a[l]);
            return;
        }
        int m = (l + r) / 2;
        build(2 * v + 0, l, m, a);
        build(2 * v + 1, m, r, a);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    void push(int v, int l, int r) {
        int m = (l + r) / 2;
        tree[2 * v + 0].update(tree[v], l, m);
        tree[2 * v + 1].update(tree[v], m, r);
    }
    void add(int v, int l, int r, int ql, int qr, T x) {
        if (qr <= l || r <= ql)
            return;
        if (ql <= l && r <= qr) {
            tree[v].add(x, l, r);
            return;
        }
        int m = (l + r) / 2;
        push(v, l, r);
        add(2 * v + 0, l, m, ql, qr, x);
        add(2 * v + 1, m, r, ql, qr, x);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    void change(int v, int l, int r, int ql, int qr, T x) {
        if (qr <= l || r <= ql)
            return;
        if (ql <= l && r <= qr) {
            tree[v].change(x, l, r);
            return;
        }
        int m = (l + r) / 2;
        push(v, l, r);
        change(2 * v + 0, l, m, ql, qr, x);
        change(2 * v + 1, m, r, ql, qr, x);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
    node query(int v, int l, int r, int ql, int qr) {
        if (qr <= l || r <= ql)
            return node();
        if (ql <= l && r <= qr)
            return tree[v];
        int m = (l + r) / 2;
        push(v, l, r);
        return query(2 * v, l, m, ql, qr) + query(2 * v + 1, m, r, ql, qr);
    }
};
