/*
ID: khanhvu2
LANG: C++14
TASK: msquare
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
const int base=40320;

queue<pair<string, string>> q;
unordered_map<int, bool> vst;

void do_a(string& cur) {
    for (int i=0; i<4; ++i)
        swap(cur[i], cur[7-i]);
}

void do_b(string& cur) {
    char tmp=cur[3];
    for (int i=3; i>0; --i) cur[i]=cur[i-1];
    cur[0]=tmp;
    tmp=cur[4];
    for (int i=4; i<7; ++i) cur[i]=cur[i+1];
    cur[7]=tmp;
}

void do_c(string& cur) {
    swap(cur[1], cur[2]);
    swap(cur[1], cur[6]);
    swap(cur[6], cur[5]);
}

int hashString(const string& s) {
    int hashVal=0;
    for (int i=0; i<(int)s.size(); ++i)
        hashVal=(hashVal*base+s[i]-48)%MOD;
    return hashVal;
}

int main() {
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);

    string st="";
    for (int i=0; i<8; ++i) {
        char c; cin>>c;
        st+=c;
    }

    q.push({"12345678", ""});

    while (!q.empty()) {
        string cur=q.front().first;
        string path=q.front().second;
        q.pop();
        vst[hashString(cur)]=true;
        if (cur==st) {
            cout<<(int)path.size()<<'\n';
            cout<<path<<'\n';
            return 0;
        }
        string tmp=cur;
        do_a(cur);
        if (!vst.count(hashString(cur))) q.push({cur, path+'A'});
        cur=tmp;
        do_b(cur);
        if (!vst.count(hashString(cur))) q.push({cur, path+'B'});
        cur=tmp;
        do_c(cur);
        if (!vst.count(hashString(cur))) q.push({cur, path+'C'});
    }
    return 0;
}
