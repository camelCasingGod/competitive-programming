#include "bits/stdc++.h"

using namespace std;

int main() { 
    int n, k;
    cin>>n>>k;
    int res = 0;
    int a = INT_MAX;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (b > 0 && i >= k) {
            if (b < a) {
                break;
            } else {
                res++;
                continue;
            }
        } else if (b > 0) {
            res++;
            a = min(a, b);
        } else {
            break;
        }
    }
    cout << res;
}