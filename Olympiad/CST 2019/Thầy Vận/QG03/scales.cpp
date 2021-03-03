#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long a;
long long pow3[30];

int main()
{
    freopen("scales.inp", "r", stdin);
    freopen("scales.out", "w", stdout);
    cin>>a;
    pow3[0]=1ll;
    for (int i=1; i<=28; i++)
        pow3[i]=pow3[i-1]*3ll;
    vector<int> tera(30, 0);
    for (int i=28; i>=0; i--)
        if (a>=2ll*pow3[i])
        {
            tera[i]=2;
            a-=2ll*pow3[i];
        }
        else if (a>=pow3[i])
        {
            tera[i]=1;
            a-=pow3[i];
        }
        else tera[i]=0;
    vector<long long> left, right;
    int nho=0;
    for (int i=0; i<(int)tera.size(); i++)
    {
        tera[i]=tera[i]+nho;
        if (tera[i]==3)
        {
            nho=1;
            continue;
        }
        if (tera[i]==2)
            left.push_back(pow3[i]), nho=1;
        else if (tera[i]==1)
            right.push_back(pow3[i]), nho=0;
    }
    cout<<(int)left.size()<<' ';
    for (int i=0; i<(int)left.size(); i++) cout<<left[i]<<' ';
    cout<<'\n';
    cout<<(int)right.size()<<' ';
    for (int i=0; i<(int)right.size(); i++) cout<<right[i]<<' ';
    return 0;
}
