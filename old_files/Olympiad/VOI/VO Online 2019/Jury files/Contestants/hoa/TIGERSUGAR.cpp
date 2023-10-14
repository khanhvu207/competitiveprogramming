#include <bits/stdc++.h>

using namespace std;

class point
{
    public : int x,y,z,t;
};

point v[1000];
int x[10], ho[10], y[10], ve[10];
int n;

bool cmx(int a, int b)
{
    return (v[a].x < v[b].x);
}

bool cmy(int a, int b)
{
    return (v[a].y < v[b].y);
}

void st2()
{

    for (int i = 0; i< n; i++)
        x[i] = i;
    sort(x, x+n, cmx);
    for (int i = 0; i< n; i++)
    {
        int l = 0, r = 0;
        for (int j = 0; j< i; ++j)
            l += v[x[i]].x - v[x[j]].x;
        for (int j = i+1; j< n; ++j)
            r += v[x[j]].x - v[x[i]].x;
        ho[x[i]] = l+r;
    }

    for (int i = 0; i< n; i++)
        y[i] = i;
    sort(y, y+n, cmy);
    for (int i = 0; i< n; i++)
    {
        int l = 0, r = 0;
        for (int j = 0; j< i; ++j)
            l += v[y[i]].y - v[y[j]].y;
        for (int j = i+1; j< n; ++j)
            r += v[y[j]].y - v[y[i]].y;
        ve[y[i]] = l+r;
    }

    int ans=0;

    for (int i = 0; i < n; ++i)
    {
        if (ve[ans] + ho[ans] > ve[i] + ho[i])
            ans = i;
    }

    cout<<v[ans].x<<" "<<v[ans].y<<endl;
    for (int i = 0; i<n;++i)
        cout<<v[i].x<<" "<<v[i].y<<endl;
}

int main()
{
    freopen("TIGERSUGAR.INP","r", stdin);
    freopen("TIGERSUGAR.OUT","w", stdout);
    cin>> n;
    for (int i = 0; i< n ; ++i)
    {
        cin>>v[i].x>>v[i].y>>v[i].z>>v[i].t;
    }
    st2();
}
