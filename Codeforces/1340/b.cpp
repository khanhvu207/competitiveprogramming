#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

using Bitset=bitset<7>;
const Bitset num[10] = {
    Bitset("1110111"),
    Bitset("0010010"),
    Bitset("1011101"),
    Bitset("1011011"),
    Bitset("0111010"),
    Bitset("1101011"),
    Bitset("1101111"),
    Bitset("1010010"),
    Bitset("1111111"),
    Bitset("1111011"),
};

const int N=2005;
int n,k;
bool dp[N][N];
vector<Bitset> a;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		a.push_back(Bitset(s));
	}
	dp[n][0]=true;
	for(int i=n-1;~i;--i){
		for(int j=0;j<=k;++j){
			for(int x=0;x<10;++x){
				Bitset chk=~num[x]&a[i];
				Bitset add=num[x]^a[i];
				if(chk.count()>0||j-add.count()<0) continue;
				dp[i][j]|=dp[i+1][j-add.count()];
			}
		}
	}
	if(!dp[0][k]){
		cout<<-1;
		return 0;
	}
	for(int i=0;i<n;++i){
		for(int x=9;~x;--x){
			Bitset chk=~num[x]&a[i];
			Bitset add=num[x]^a[i];
			if(chk.count()>0||k-add.count()<0) continue;
			if(dp[i+1][k-add.count()]){
				cout<<x;
				k-=add.count();
				break;
			}
		}
	}
}