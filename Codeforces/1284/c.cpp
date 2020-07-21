// Extremely trivial!

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    multiset<int> s;
    s.insert(10);
    s.insert(10);
    s.insert(20);
    auto it = s.lower_bound(10);
    s.erase(it);
    for (auto i : s) cout << i << ' ';
}