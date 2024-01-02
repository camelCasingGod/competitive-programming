#include "bits/stdc++.h"

using namespace std;

int main() {
    int iterations;

    cin >> iterations;

    for (int i = 0; i < iterations; i++) {
        string s;
        cin >> s;
        int curr_size = s.size();
        if (curr_size <= 10) {
            cout << s + '\n';
        } else {
            cout << s[0] + to_string(curr_size - 2) + s[curr_size - 1] + '\n';
        }
    }
    return 0;
}