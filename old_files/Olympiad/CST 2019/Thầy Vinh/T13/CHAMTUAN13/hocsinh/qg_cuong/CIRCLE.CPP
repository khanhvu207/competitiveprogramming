#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;
const int maxn = 101;
int n,k;
string c,d,temp;
set<string> st;

string findnext(string c)
{
    d = "";
    for (int i=0; i<n-1; ++i){
        d = d + (c[i]==c[i+1]?'B':'W');
    }
    d = d + (c[0]==c[n-1]?'B':'W');
    return d;
}

string getmin(string c)
{
    d = c;
    temp = c;
    for (int i=0; i<n; ++i){
        temp = temp + temp[0];
        temp.erase(0,1);
        if (temp < d) d = temp;
    }
    return d;
}

void dfs(string c, int lev)
{
    if (st.count(c)) return;
    else {
        st.insert(c);
    }
    if (lev == k){
//        cerr << c << endl;
        return;
    }
    temp = 'W';
    for (int i=0; i<n-1; ++i){
        if (c[i]=='W') temp = temp + (temp[i]=='W'?'B':'W');
        else temp = temp + temp[i];
    }
//    cerr << temp << endl;
    temp = getmin(temp);
    dfs(temp,lev+1);

    temp = 'B';
    for (int i=0; i<n-1; ++i){
        if (c[i]=='W') temp = temp + (temp[i]=='W'?'B':'W');
        else temp = temp + temp[i];
    }
    temp = getmin(temp);
    dfs(temp,lev+1);
}

int main()
{
    freopen("CIRCLE.INP","r",stdin);
    freopen("CIRCLE.OUT","w",stdout);

    scanf("%d %d\n",&n,&k);
    char chr;
    for (int i=0; i<n; ++i){
        scanf("%c",&chr);
        c = c + chr;
    }

    for (int i=0; i<k; ++i){
        c = findnext(c);
    }

    c = getmin(c);
    dfs(c,0);
    printf("%d\n",st.size());
    return 0;
}
