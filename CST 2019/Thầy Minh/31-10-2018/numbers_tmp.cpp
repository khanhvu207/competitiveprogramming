#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int k;
long long l, r;
long long dp[50][15][15][5][5];
vector<int> digitl;
vector<int> digitr;

long long solve (int cur, int last1, int last2, bool low, bool high)
{
    if (last1>=0&&last2>=0)
        if (dp[cur][last1][last2][low][high]!=-1) return dp[cur][last1][last2][low][high];
    if (cur==k)
        return (low&&high)*1ll;
    long long cnt=0ll;
    for (int i=0; i<10; i++)
        if (i!=last1&&i!=last2)
            cnt+=solve(cur+1, i, last1, (i>digitl[cur])||(low&&i==digitl[cur]), (i<digitr[cur])||(high&&i==digitr[cur]));
    //cerr<<cur<<' '<<last1<<' '<<last2<<' '<<low<<' '<<high<<'\n';
    if (last1>=0&&last2>=0)
        dp[cur][last1][last2][low][high]=cnt;
    return cnt;
}

int main()
{
    freopen("numbers.inp", "r", stdin);
    freopen("numbers.out", "w", stdout);
    cin>>l>>r;
    while (l>0)
        digitl.push_back(l%10ll), l/=10ll;
    while (r>0)
        digitr.push_back(r%10ll), r/=10ll;
    while ((int)digitl.size()<(int)digitr.size()) digitl.push_back(0);
    while ((int)digitr.size()<(int)digitl.size()) digitr.push_back(0);
    k=(int)digitr.size();
    memset(dp, -1, sizeof dp);
    cout<<solve(0, -1, -1, 1, 1);
    return 0;
}
