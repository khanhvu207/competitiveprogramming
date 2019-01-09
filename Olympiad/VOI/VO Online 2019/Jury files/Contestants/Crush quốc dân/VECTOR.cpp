#include <bits/stdc++.h>
using namespace std;
long long a[303],b[303];
vector<pair<long long,char> > V;
int main()
{
    ifstream cin("VECTOR.inp");
    ofstream cout("VECTOR.out");
    int n,m;
    cin>>n;

    for(int i(1);i<=n;++i)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i(1);i<=m;++i)
    {
        cin>>b[i];
    }
    for(int i(1);i<=min(m,n);++i)
    {
        long long T=b[i]/__gcd(a[i]*a[i],b[i]);
        if(a[i]*a[i]/__gcd(a[i]*a[i],b[i])!=1)V.push_back({a[i]*a[i]/__gcd(a[i]*a[i],b[i]),'D'});
        if(a[i]!=1)V.push_back({a[i],'W'});
        if(a[i]!=1)V.push_back({a[i],'L'});
        if(T!=1)V.push_back({T,'D'});
        if(T!=1)V.push_back({T,'W'});
        if(T!=1)V.push_back({T*T,'D'});
        if(T!=1)V.push_back({T,'W'});
        if(T!=1)V.push_back({T,'L'});
    }
    for(int j(min(n,m)+1);j<=n;++j)
    {
        if(a[j]==1) continue;
        V.push_back({a[j]*a[j],'D'});
        V.push_back({a[j],'W'});
        V.push_back({a[j],'L'});
    }
    for(int j(min(n,m)+1);j<=m;++j)
    {
        if(b[j]==1) continue;
        V.push_back({b[j],'D'});
        V.push_back({b[j],'W'});
        V.push_back({b[j]*b[j],'D'});
        V.push_back({b[j],'W'});
        V.push_back({b[j],'L'});
    }
     cout<<V.size()<<endl;
     for(int i(0);i<V.size();++i)
        cout<<V[i].first<<" "<<V[i].second<<endl;
}
