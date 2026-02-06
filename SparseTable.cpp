#include <bits/stdc++.h>
using namespace std;

template <class T>
struct SparseTable {
    int n, LOG;
    vector<vector<T>> st;
    vector<int> lg;
    function<T(const T&, const T&)> merge;

    SparseTable(const vector<T>& v, function<T(const T&, const T&)> merge)
        : n(v.size()), merge(merge) {
        LOG = 32 - __builtin_clz(n);
        st.assign(LOG, vector<T>(n));
        st[0] = v;
        for (int i = 1; i < LOG; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                st[i][j] = merge(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;
    }

    T query(int l, int r) const {
        int j = lg[r - l + 1];
        return merge(st[j][l], st[j][r - (1 << j) + 1]);
    }
};

int main() {
    //operations to be done here
}
