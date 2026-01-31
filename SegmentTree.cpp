#include <iostream>
#include <vector>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    // Build tree from array
    void build(const vector<long long>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, 2*v, tl, tm);
            build(arr, 2*v+1, tm+1, tr);
            tree[v] = tree[2*v] + tree[2*v+1]; // Sum query; change operator for min/max
        }
    }

    // Range query [l, r]
    long long query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0; // change to INF for min, -INF for max
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return query(2*v, tl, tm, l, min(r, tm))
             + query(2*v+1, tm+1, tr, max(l, tm+1), r);
    }

    // Point update: set arr[pos] = val
    void update(int v, int tl, int tr, int pos, long long val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2*v, tl, tm, pos, val);
            else
                update(2*v+1, tm+1, tr, pos, val);
            tree[v] = tree[2*v] + tree[2*v+1]; // Sum query
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree st(n);
    st.build(arr, 1, 0, n-1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // update
            int idx;
            long long val;
            cin >> idx >> val;
            st.update(1, 0, n-1, idx, val);
        } else if (type == 2) { // sum query
            int l, r;
            cin >> l >> r;
            cout << st.query(1, 0, n-1, l, r) << "\n";
        }
    }

    return 0;
}
