#include "bits/stdc++.h"

using namespace std;

#define int long long

signed main() {
    int testcases; cin >> testcases;
    while (testcases--) {
        int a, b; cin >> a >> b;
        if (b % a == 0) { cout << b * (b / a) << endl; }
        else { cout << b * (a / gcd(a, b)) << endl; }
    }
    return 0;
}