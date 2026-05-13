#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define el "\n"

int find_missing(int cur, const vector<bool>& pres, int max_val) { 
// const because it doesn't change and to force the compiler to not duplicate the whole vector
// We could use a pointer but its value might be null and the syntax would be more complex [ we will use -> ]
// Base case
    if (cur > max_val || !pres[cur]) {
        return cur;
    }
    return find_missing(cur + 1, pres, max_val);
}

void solve() {
    int n;
    cin >> n;
    vector<bool> pres(n + 2, false);
    // Vector starts from 0 not 1 so we add 1, and if a = {1, 2, 3} and n = 3, we need space for the missing 4, so we add another 1.
    forn(i, n) {
        int x;
        cin >> x;
        if (x > 0 && x <= n) {
            pres[x] = true;
        }
    }
        cout << find_missing(1, pres, n + 1) << el;
}

int main() {
	// to make input&output faster
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	
    //int t;
    //cin >> t; 
    //while(t--)
        solve();
    return 0;
}
