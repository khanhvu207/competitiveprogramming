#include <bits/stdc++.h>
using namespace std;
string trans(int num,int n){
    string res;
    while(n--) res.push_back('0' + num%2), num /= 2;
    return res;
}
int main(){
#ifdef THEMIS
    freopen("SINGER.INP", "r", stdin);
    freopen("SINGER.OUT", "w", stdout);
#endif // THEMIS

    int n, length, no;
    cin >> n >> length >> no;
    length --;
    int ans = 0;
    for(int mask=0;mask<(1<<n);mask++){
        int cnt = 0;
        int curlen = 0;
        for(int i=0;i<n;i++){
            if (curlen == 0)    curlen++;
            else{
                int last = ((mask >> (i-1)) & 1);
                int bit  = ((mask >> i) & 1);
                if ((i+bit)%2 == (last+i-1+2)%2)    curlen++;
                else curlen = 1;
            }
            if (curlen >= length)   cnt++;
        }
        if (cnt == no)  ans ++;
    }
    cout << ans;
}
