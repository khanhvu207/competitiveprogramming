#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n;    
int minEle = 1e9 + 1, maxEle = -1;
vector<int> a;

bool chk(int mid) {
    set<int> s;
    for (auto x : a) s.insert(abs(x - mid));
    if ((int)s.size() == 1 || ((int)s.size() == 2 && *s.begin() == 0)) {
        return true;
    } else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.resize(n);
    for (int& x : a) {
        cin >> x;
        minEle = min(minEle, x);
        maxEle = max(maxEle, x); 
    }
    int mid = (minEle + maxEle) / 2;
    for (int i = mid - 1; i <= mid + 1; ++i) {
        if (chk(i)) {
            cout << "YES";
            return 0;
        }
    }
    if (chk(0) || chk(maxEle)) {
        cout << "YES";
    }
    else cout << "NO";
}