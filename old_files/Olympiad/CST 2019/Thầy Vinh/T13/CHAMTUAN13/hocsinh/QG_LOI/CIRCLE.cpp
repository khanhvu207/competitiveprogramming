#include <iostream>
#include <cstdio>
#include <set>
#define N 101
#define M 11
using namespace std;
set<string> d[M];
char s[N];
short n,k;
void cb(const string &u,const short &c){
    d[c].insert(u);
    string v;
    for (short i=1;i<n;++i){
        v="";
        for (short j=i;j<n;++j) v=v+u[j];
        for (short j=0;j<i;++j) v=v+u[j];
        d[c].insert(v);
    }
}
int kq;
void dfs(string u,short c){
    if (d[c].count(u)) return;
    cb(u,c);
    if (!c) {++kq;return;}
    string v=u;
    bool g;
    for (short j=0;j<2;++j){
        if (j) v[n-1]='W'; else v[n-1]='B';
        g=j;
        for (short i=0;i<n-1;++i)
        if (u[i]=='B') v[i]=g?'W':'B';
        else g=!g,v[i]=g?'W':'B';
        if (u[n-1]=='B'){
            if (v[n-1]==(g?'W':'B')){
                dfs(v,c-1);
            }
        }else{
            g=!g;
            if (v[n-1]==(g?'W':'B')){
                dfs(v,c-1);
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
