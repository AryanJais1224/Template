#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<long long> bit;

public:
    FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, long long delta) {
        for (; i <= n; i += i & -i)
            bit[i] += delta;
    }

    long long query(int i) const {
        long long sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

    long long rangeQuery(int l, int r) const {
        return query(r) - query(l - 1);
    }
};

int main() {
    FenwickTree ft(10);
    //operations to be done here
}
