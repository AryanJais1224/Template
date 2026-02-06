struct DSU {
    vector<int> p, r;
    DSU(int n) : p(n), r(n, 0) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) {
            if (r[a] < r[b]) swap(a, b);
            p[b] = a;
            if (r[a] == r[b]) r[a]++;
        }
    }
};
