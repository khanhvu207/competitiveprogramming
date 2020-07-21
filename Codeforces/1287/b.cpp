#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
 
int n, k;
string s[1505];
map<string, int> Map;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) { 
        cin >> s[i];
    }
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string t = "";
            for (int z = 0; z < k; ++z) {
                if (s[i][z] == s[j][z]) t += s[i][z];
                else {
                    if ('S' != s[i][z] && 'S' != s[j][z]) t += 'S';
                    else if ('E' != s[i][z] && 'E' != s[j][z]) t += 'E';
                    else if ('T' != s[i][z] && 'T' != s[j][z]) t += 'T';
                }
            }
            if (Map.count(t)) ans += Map[t];
        }
        Map[s[i]]++;
    }
    cout << ans;
}