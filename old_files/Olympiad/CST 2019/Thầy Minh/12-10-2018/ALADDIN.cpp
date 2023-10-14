#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct bignum {
    const long long base = 1e9;

	int len;
	long long data[2200];

	long long &operator [](int x){return(data[x]);}

	const long long &operator [](int x)const { return(data[x]);}

	bignum() {
		memset(data, 0, sizeof data);
		len = 0;
	}

	bignum operator =(const bignum &x){
		for (int i = x.len + 1; i <= len; ++i)
            data[i] = 0;
		for (int i = 1; i <= x.len; ++i)
            data[i] = x.data[i];
		len = x.len;
		return *this;
	}

	bignum operator =(long long x) {
        for (int i = len; i >=0; --i)
            data[i] = 0;
		len = 0;
		while (x)
			data[++len] = x % base,
			x /= base;
		return *this;
	}

	bignum(long long x) {
        memset(data, 0, sizeof data);
		len = 0; (*this) = x;
	}

	bignum operator *(const bignum &b){
		bignum tmp;
		for(int i = 1; i <= len; ++i)
            if(data[i]!=0)
                for(int j = 1; j <= b.len; ++j)
                    if (b.data[j])
                        tmp.data[i + j - 1] += data[i] * b.data[j],
                        tmp.data[i + j] += tmp.data[i + j - 1] / base,
                        tmp.data[i + j - 1] %= base;
		tmp.len = len + b.len - 1;
		while(tmp.data[tmp.len + 1]) tmp.len++;
		return tmp;
	}

	bignum operator +(const bignum &b){
		bignum tmp;
		int l = max(len, b.len);
		for (int i = 1; i <= l; ++i)
            tmp[i] = data[i] + b[i];
		for (int i = 1; i <= l; ++i)
            tmp[i + 1] += tmp[i] / base,
            tmp[i] %= base;
		tmp.len = l;
		if(tmp[tmp.len + 1]) tmp.len++;
		return tmp;
	}

	bignum operator -(long long x) {
		bignum tmp = *this;
		tmp[1] -= x;
		for(int i = 1; i <= len && tmp[i] < 0; ++i)
			tmp[i + 1] += (tmp[i] + 1) / base - 1,
			tmp[i] = (tmp[i] + 1) % base + base - 1;
		while(!tmp[tmp.len] && tmp.len > 1) tmp.len--;
		return tmp;
	}

	void write() {
		printf("%lld", data[len]);
		for(int i = len - 1; i >= 1; --i) {
            for (int tmp = base / 10; tmp && data[i] < tmp; tmp /= 10)
                printf("0");
			if (data[i]) printf("%lld", data[i]);
		}
	}
};

bignum power(bignum base, int expo) {
	if (!expo) return 1;
	bignum res = power(base, expo / 2);
	res = res * res;
	if (expo & 1) res = res * base;
	return res;
}

int n, m;

int main() {
    freopen("aladdin.inp", "r", stdin);
    freopen("aladdin.out", "w", stdout);
    scanf("%d %d", &n, &m);
    (power(2, n) + power(2, m) - 2).write();
}