#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const long long base=1e8;

struct bignum {
	int len; long long data[15];
	long long &operator [](int x) {return(data[x]);}
	const long long &operator [](int x) const {return(data[x]);}
	bignum () {
		memset(data,0,sizeof(data)); len=0;
	}
	bignum operator =(const bignum &x) {
		for(int i=x.len+1;i<=len;++i)data[i]=0;
		for(int i=1;i<=x.len;++i)data[i]=x.data[i];
		len=x.len;
		return *this;
	}
	bignum operator=(long long x){
		for(int i=len;i>=0;--i)data[i]=0;
		len=0;
		while(x){
			data[++len]=x%base;
			x/=base;
		}
		return *this;
	}
	bignum(long long x){
		memset(data,0,sizeof(data));
		len=0;
		(*this)=x;
	}
	bignum operator +(const bignum &b){
		bignum tmp;
		int i,l=max(len,b.len);
		for(i=1;i<=l;++i)tmp[i]=data[i]+b[i];
		for(i=1;i<=l;++i)tmp[i+1]+=tmp[i]/base,tmp[i]%=base;
		tmp.len=l;
		if(tmp[tmp.len+1])tmp.len++;
		return tmp;
	}
	void write(){
		printf("%I64d",data[len]);
		for(int i=len-1;i>=1;--i)printf("%0*I64d",8,data[i]);
	}
};

bignum dp[215][215];

int main() {
    freopen("10541.inp", "r", stdin);
    freopen("10541.out", "w", stdout);
    dp[0][0] = 1;
    for (int i = 1; i <= 200; ++i)
        for (int j = i; j <= 200; ++j)
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
    int t; cin >> t;
    for (int n, k; t--;) {
        cin >> n >> k;
        for (int i = 0, x; i < k; ++i) cin >> x, n -= x;
        (dp[k + 1][n] + dp[k][n] + dp[k][n] + dp[max(k - 1, 0)][n]).write();
        putchar('\n');
    }
}
