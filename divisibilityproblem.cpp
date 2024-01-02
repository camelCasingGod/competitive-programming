#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x % y) {
            cout << to_string((y - (x % y))) + '\n';
        } else {
            cout << to_string(0) + '\n';
        }
    }
}