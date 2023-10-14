#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#define ii pair<string,short>
#define N 101
#define M 11
using namespace std;
set<string> d[M];
char s[N];
short n,k;
string pre[N], suf[N];
void cb(const string &u,const short &c){
    d[c].insert(u);
    string v;
    pre[0] = u[0];
    suf[n-1] = u[n-1];
    for(int i=1; i<n; ++i) pre[i] = pre[i-1]+u[i];
    for(int i=n-2;i>=0;--i)suf[i] = u[i]+suf[i+1];
    for (short i=1;i<n;++i){
        v = suf[i] + pre[i-1];
        d[c].insert(v);
    }
}
int kq;
void dfs(string u,short c){
    queue<ii> Q;
    for(Q.push(ii(u,c)); !Q.empty(); Q.pop()){
        u = Q.front().first;
        c = Q.front().second;

        /*if (d[c].count(u)) continue;
        cb(u,c); */
        if (c == 0) {++kq; continue;}
        string v=u; bool g;
        for (short j=0;j<2;++j){
            if (j) v[n-1]='W'; else v[n-1]='B';
            g=j;
            for (short i=0;i<n-1;++i)
            if (u[i]=='B') v[i]=g?'W':'B';
            else g=!g,v[i]=g?'W':'B';
            if (u[n-1]=='B'){
                if (v[n-1]==(g?'W':'B')){
                    if (d[c-1].count(v) == 0) {
                        cb(v,c-1);
                        Q.push(ii(v,c-1));
                    }
                }
            }else{
                g=!g;
                if (v[n-1]==(g?'W':'B')){
                    if (d[c-1].count(v) == 0) {
                        cb(v,c-1);
                        Q.push(ii(v,c-1));
                    }
                }
            }
        }
    }
}
int main(){
    freopen("CIRCLE.inp","r",stdin);
    freopen("CIRCLE.out","w",stdout);
    scanf("%hd%hd\n%s",&n,&k,s+1);
    for (short i=1;i<=k;++i){
        s[0]=s[n];
        for (short j=n;j;--j) s[j]=s[j]!=s[j-1]?'W':'B';
    }
    dfs(s+1,k);
    printf("%d",kq);
}
