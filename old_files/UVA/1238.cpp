#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int n, sign[100], num[100];
bool vst[35][100][6015], val[6015];

void rec (int cur, int open, int sum)
{
    if (vst[cur][open][sum+3000]) return;
    vst[cur][open][sum+3000]=1;
    if (cur==n)
    {
        val[sum+3000]=1;
        return;
    }
    int aux=sum+num[cur]*sign[cur]*(open%2==0?1:-1);
    if (sign[cur]==-1)
        rec(cur+1, open+1, aux);
    else if (open>0)
        rec(cur+1, open-1, aux);
    rec(cur+1, open, aux);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("1238.in", "r", stdin);

    string line;
    while (getline(cin, line))
    {
        stringstream inp(line);
        sign[0]=1;
        inp >> num[0];
        n=1; char x;
        while (inp >> x >> num[n])
        {
            sign[n]=(x=='+'?1:-1);
            ++n;
        }
        memset(val, false, sizeof val);
        memset(vst, false, sizeof vst);
        rec(0, 0, 0);
        int cnt=0;
        for (int i=-3000; i<=3000; ++i)
            cnt+=val[i+3000];
        cout << cnt << '\n';
    }
}
