#include "bits/stdc++.h"

using namespace std;

int main() {
    string s;
    cin >> s;

    int res = 0;
    char current;
    for (int i = 0; i < s.size(); i++) {
        if (current and current == s[i]) {
            res++;
        } else {
            current = s[i];
            res = 1;
        }
        if (res == 7) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}