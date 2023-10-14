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
    
}