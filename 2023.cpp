#include "bits/stdc++.h"

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        int n, k;
        long long prod = 1;
        cin >> n >> k;
        while (n--) {
            int num;
            cin >> num;
            prod *= num;
        }
        if (2023 % prod == 0) {
            cout << "YES" << endl;
            cout << 2023 / prod << endl;
            k--;
            while (k--) {
                cout << 1 << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}