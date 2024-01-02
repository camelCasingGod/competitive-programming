#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    int a[n];
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = x + y + z;
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= 2) { k++; }
    }
    cout << k;
    return 0;
}