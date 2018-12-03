#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
 
int k;
long long l, r;
long long dp[50][15][15][5][5][2];
vector<int> digitl;
vector<int> digitr;
 
long long solve (int cur, int last1, int last2, bool low, bool high, bool ok)
{
    if (dp[cur][last1][last2][low][high][ok]!=-1) return dp[cur][last1][last2][low][high][ok];
    if (cur==k) return 1ll;
    long long cnt=0ll;
    for (int i=0; i<10; i++)
        if (i!=last1&&i!=last2&&(low||i>=digitl[cur])&&(high||i<=digitr[cur]))
            cnt+=solve(cur+1, (!ok&&i<1?10:i), last1, low||i>digitl[cur], high||i<digitr[cur], ok||(i>0));
    dp[cur][last1][last2][low][high][ok]=cnt;
    return cnt;
}
 
int main()
{
    cin>>l>>r;
    while (l>0)
        digitl.push_back(l%10ll), l/=10ll;
    while (r>0)
        digitr.push_back(r%10ll), r/=10ll;
    while ((int)digitl.size()<(int)digitr.size()) digitl.push_back(0);
    while ((int)digitr.size()<(int)digitl.size()) digitr.push_back(0);
    k=(int)digitr.size();
    reverse(digitl.begin(), digitl.end());
    reverse(digitr.begin(), digitr.end());
    memset(dp, -1, sizeof dp);
    cout<<solve(0, 10, 10, 0, 0, 0);
    return 0;
}