#include "bits/stdc++.h"
using namespace std;

#define FAST_IO             (ios_base:: sync_with_stdio(false),cin.tie(NULL));

#define int                 long long
#define ll                  long long
#define ull                 unsigned long long
#define endl                '\n'
#define ff                  first
#define ss                  second
#define pb                  push_back
#define all(x)              x.begin(), x.end()
#define sz(x)               (int)(x).size()

#define yes                 cout<<"YES"<<endl
#define no                  cout<<"NO"<<endl

#define PI                  3.141592653589793238
#define MIN                 INT_MIN
#define MAX                 INT_MAX
#define INF                 LONG_LONG_MAX
#define MOD                 1000000007
#define LLM                 1000000000000000007

ll factorial(ll n)              { if(n==0) return 1; ll res = 1; for (ll i = 2; i <= n; i++) res = res * i; return res; }
ll nPr(ll n, ll r)              { return factorial(n) / factorial(n - r); }
ll nCr(ll n, ll r)              { return factorial(n) / (factorial(r) * factorial(n - r));}
ll gcd(ll a, ll b)              { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b)              { return (a * b) / gcd(a, b);}
ull mypow(ull a, ull b)         { ull ans = 1; a%=MOD; while(b){ if (b&1) ans = (ans*a) % MOD; a = (a*a) % MOD; b >>= 1; } return ans; }
bool isPrime(ll n)              { if(n <= 1) return false; for(ll i = 2; i*i <= n; i++) if(n % i == 0) return false; return true; }

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x <<" "; _print(x); cerr << endl;
#define dbgin(x) cerr << #x <<" "; _print(x); cerr << ";"<<endl;
#else
#define dbg(x)
#define dbgin(x)
#endif

void _print(int t) {cerr << t;}void _print(string t) {cerr << t;}void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}void _print(double t) {cerr << t;}void _print(unsigned ll t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr<<"[ "; for(T i : v) {_print(i); cerr<<" ";} cerr<<"]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";} 
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
    // PC shares to one person at least
    // n total people that need to know the announcement
    // p is the cost for PC to share info with one person
    // if a resident has heard the announcement, then they can share it with some # ofothers for a price
    int n, p;
    cin >> n >> p;
    int a[n];
    int b[n];
    int rep = 0;
    while (rep < n) {
        cin >> a[rep];
        rep++;
    }
    rep = 0;
    while (rep < n) {
        cin >> b[rep];
        rep++;
    }
    // inputs done

    vector<pair<int, int>> sort_;
    sort_.push_back(make_pair(p, -1));
    for (int i = 0; i < n; i++) {
        sort_.push_back(make_pair(b[i], i));
    }

    sort(sort_.begin(), sort_.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });

    int total_price = 0;
    int num_remaining = n;

    while (num_remaining > 0) {
        pair<int, int> current_lowest_price = sort_.back();
        sort_.pop_back();

        // current_lowest_price.first // price to tell each person
        // current_lowest_price.second // index of the array
        
        if (current_lowest_price.second == -1) {
            // PC is telling everyone for the lowest price
            total_price += (current_lowest_price.first * num_remaining);
            cout << total_price << endl;
            return;
        } else {
            if (num_remaining == n) {
                total_price += p;
                num_remaining--;
            }
            if (num_remaining > a[current_lowest_price.second]) {
                total_price += (current_lowest_price.first * a[current_lowest_price.second]);
                num_remaining -= a[current_lowest_price.second];
            } else {
                total_price += (current_lowest_price.first * num_remaining);
                cout << total_price << endl;
                return;
            }
        }
    }
}

int32_t main()
{
    FAST_IO;
    int TC;
    cin >> TC;
    while (TC--) 
        solve();
}