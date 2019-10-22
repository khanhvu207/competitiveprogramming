/*
ID: khanhvu2
LANG: C++14
TASK: ratios
*/
#include <bits/stdc++.h>
using namespace std;

int a[4], b[4], c[4], best=1e9, res_i, res_j, res_k, res_x=-1;

int main() {
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    for (int i=0; i<4; ++i)
        cin>>a[i]>>b[i]>>c[i];
    for (int i=0; i<100; ++i)
        for (int j=0; j<100; ++j)
            for (int k=0; k<100; ++k) {
                int x=(i*a[1]+j*a[2]+k*a[3]);
                int y=(i*b[1]+j*b[2]+k*b[3]);
                int z=(i*c[1]+j*c[2]+k*c[3]);
                if ((a[0]==0&&x)||(b[0]==0&&y)||(c[0]==0&&z)) continue;
                if (a[0]>0) {
                    if (x%a[0]!=0) continue;
                    x/=a[0];
                }
                if (b[0]>0) {
                    if (y%b[0]!=0) continue;
                    y/=b[0];
                }
                if (c[0]>0) {
                    if (z%c[0]!=0) continue;
                    z/=c[0];
                }
                if ((x==0&&a[0])||(y==0&&b[0])||(z==0&&c[0])) continue;
                int t=max(x, max(y, z));
                if ((x&&x!=t)||(y&&y!=t)||(z&&z!=t)) continue;
                if (0<t&&t<100) {
                    if (i+j+k<best) {
                        best=i+j+k;
                        res_i=i, res_j=j, res_k=k, res_x=t;
                    }
                }
            }
    if (res_x==-1)
        cout<<"NONE\n";
    else
        cout<<res_i<<' '<<res_j<<' '<<res_k<<' '<<res_x<<'\n';
    return 0;
}
