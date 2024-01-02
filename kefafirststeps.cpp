#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    int res = 0, min_ = INT_MIN;

    int l = 0, r = 0;
    while (r < n) {
        int current;
        cin >> current;

        if (current < min_) {
            l = r;
        } else {
            res = max(res, r - l + 1);
        }
        min_ = current;

        r++;
    }

    cout << res;
}