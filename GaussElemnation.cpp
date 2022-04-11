#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Base {
    const static int N = 60;

    ll p[N];

    Base() {
        memset(p, 0, sizeof(p));
    }

    void insert(ll x) {
        for (int i = N - 1; ~i; --i) {
            if (x & (1LL << i)) {
                if (p[i]) {
                    x ^= p[i];
                } else {
                    p[i] = x;
                    break;
                }
            }
        }
    }

    bool can(ll x) {
        for (int i = N - 1; ~i; --i) {
            if (x & (1 << i)) {
                x ^= p[i];
            }
        }
        return x == 0;
    }

    ll getMax() {
        ll result = 0;
        for (int i = N - 1; ~i; --i) {
            if ((result ^ p[i]) > result) {
                result ^= p[i];
            }
        }
        return result;
    }

} base;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll& x : a) {
        scanf("%lld", &x);
        base.insert(x);
    }

    cout << base.getMax() << endl;
}
