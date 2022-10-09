#ifndef INCLUDE
#include <bits/stdc++.h>
#include <random>
using namespace std;
using ll = long long;
random_device rd;
mt19937 mt(rd());
#endif

template <typename T>
struct treap {
    struct node {
        // for all k1 from left, k2 from right: k1<k<=k2; 
        // for all p1 from left or right:       p1<=p; 
        T key; ll prior;
        T sum; ll size;
        node
            *left = nullptr,
            *right = nullptr;

        operator T() const { return key; }

        node(T x) : key(x), prior(mt()), size(1), sum(x) {}

        static void update(node *t) {
            if (t) {
                t->size = 1 + t->left_size() + t->right_size();

                //t->sum =
                //    t->key +
                //    (t->left ? t->left->sum : 0) +
                //    (t->right ? t->right->sum : 0);
            }
        }

        // first keys less than k, second keys at least x
        static pair<node *, node *> split(node *node, const T &x) {
            if (!node) return { nullptr, nullptr };
            if (node->key < x) {
                auto p = split(node->right, x);
                node->right = p.first;
                update(node);
                return { node, p.second };
            }
            else {
                auto p = split(node->left, x);
                node->left = p.second;
                update(node);
                return { p.first, node };
            }
        }

        // second tree has k vertices
        static pair<node *, node *> split_size(node *node, const ll &k) {
            if (!node) return { nullptr, nullptr };
            if (node->right_size() >= k) {
                auto p = split_size(node->right, k);
                node->right = p.first;
                update(node);
                return { node, p.second };
            }
            else {
                auto p = split_size(node->left, k - 1 - node->right_size());
                node->left = p.second;
                update(node);
                return { p.first, node };
            }
        }

        // first keys must be less than second keys
        static node *merge(node *t1, node *t2) {
            if (!t1 || !t2) return t1 ? t1 : t2;
            if (t1->prior >= t2->prior) {
                t1->right = merge(t1->right, t2);
                update(t1);
                return t1;
            }
            else {
                t2->left = merge(t1, t2->left);
                update(t2);
                return t2;
            }
        }

        node *min() {
            node *t = this;
            while (t->left)
                t = t->left;
            return t;
        }

        node *max() {
            node *t = this;
            while (t->right)
                t = t->right;
            return t;
        }

        ll left_size() {
            return left ? left->size : 0;
        }

        ll right_size() {
            return right ? right->size : 0;
        }

        node *insert(const T &x) {
            node *k = new node(x);
            auto p = split(this, x);
            p.first = merge(p.first, k);
            return merge(p.first, p.second);
        }

        node *erase(const T &x) {
            if (key < x)
                right = right ? right->erase(x) : nullptr;
            else if (key > x)
                left = left ? left->erase(x) : nullptr;
            else {
                node *res = merge(left, right);
                delete this;
                return res;
            }
            update(this);
            return this;
        }

        node *find(const T &x) {
            node *cur = this;
            while (cur)
                if (cur->key < x)
                    cur = cur->right;
                else if (cur->key > x)
                    cur = cur->left;
                else
                    return cur;
            return nullptr;
        }

        node *lower_bound(const T &x) {
            node *cur = this, *res = nullptr;
            while (cur)
                if (cur->key < x)
                    cur = cur->right;
                else {
                    res = cur;
                    cur = cur->left;
                }
            return res;
        }

        node *upper_bound(const T &x) {
            node *cur = this, *res = nullptr;
            while (cur)
                if (cur->key <= x)
                    cur = cur->right;
                else {
                    res = cur;
                    cur = cur->left;
                }
            return res;
        }

        void clear() {
            if (left) left->clear();
            if (right) right->clear();
            delete this;
        }
    };
    node *head = nullptr;
    node *min() { return head ? head->min() : nullptr; }
    node *max() { return head ? head->max() : nullptr; }
    ll size() { return head ? head->size : 0; }
    void insert(const T &x) { head = head ? head->insert(x) : new node(x); }
    void erase(const T &x) { head = head ? head->erase(x) : nullptr; }
    node *find(const T &x) { return head ? head->find(x) : nullptr; }
    node *lower_bound(const T &x) { return head ? head->lower_bound(x) : nullptr; }
    node *upper_bound(const T &x) { return head ? head->upper_bound(x) : nullptr; }

    pair<node *, node *> split(const T &x) { return node::split(head, x); }
    pair<node *, node *> split_size(const ll &k) { return node::split_size(head, k); }
    void merge(node *a, node *b) { head = node::merge(a, b); }

    ~treap() { if (head) head->clear(); }

    friend ostream &operator <<(ostream &os, const struct treap::node *node) {
        if (node) {
            os << node->left;
            os << "(" << node->key << ", " << node->prior << ")\n";
            os << node->right;
        }
        return os;
    }

    friend ostream &operator <<(ostream &os, const treap &treap) {
        return os << treap.head;
    }
};