/*
ID: khanhvu2
LANG: C++14
TASK: spin
*/
#include <bits/stdc++.h>
using namespace std;

int speed[5], n[5];
vector<pair<int, int>> w[5];

bool pass(int id, int time, int angle) {
    bool ok=false;
    for (int i=0; i<n[id]; ++i) {
        int st=w[id][i].first+time*speed[id];
        st%=360;
        int ed=(st+w[id][i].second)%360;
        if (st<=ed) ok|=st<=angle&&angle<=ed;
        else {
            ok|=(angle<=ed||angle>=st);
        }
    }
    return ok;
}

int main() {
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    for (int i=0; i<5; ++i) {
        cin>>speed[i]>>n[i];
        for (int j=0; j<n[i]; ++j) {
            int x, y; cin>>x>>y;
            w[i].push_back({x, y});
        }
    }
    for (int i=0; i<360; ++i) {
        for (int angle=0; angle<360; ++angle) {
            bool ok=true;
            for (int j=0; j<5; ++j) {
                ok&=pass(j, i, angle);
            }
            if (ok) {
                cout<<i<<'\n';
                return 0;
            }
        }
    }
    cout<<"none\n";
    return 0;
}
