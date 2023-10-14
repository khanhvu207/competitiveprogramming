#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD=1e9+7;
const int N=5005;
int n,m,s[N];
vector<int> cow[N];

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>s[i];
	for(int i=0;i<m;++i){
		int f,h;
		cin>>f>>h;
		cow[f].push_back(h);
	}
	int res=0;
	ll total=0;
	for(int i=1;i<=n;++i) sort(cow[i].begin(),cow[i].end());
	for(int cut=-1;cut<n;++cut){
		int num_sleeps=0;
		ll ways=1LL;
		vector<int> left(n+1,0),right(n+1,0);
		for(int i=0;i<=cut;++i) ++left[s[i]];
		for(int i=cut+1;i<n;++i) ++right[s[i]];
		for(int i=1;i<=n;++i)
			if(cut!=-1&&i==s[cut]){
				if(!binary_search(cow[i].begin(),cow[i].end(),left[i])) goto skip;
				num_sleeps+=1;
				ll cnt=0;
				for(int j:cow[i]) if(j!=left[i]&&j<=right[i]) ++cnt;
				if(cnt>0) num_sleeps+=1, (ways*=cnt%MOD)%=MOD;
			}
			else{
				ll l=upper_bound(cow[i].begin(),cow[i].end(),left[i])-cow[i].begin();
				ll r=upper_bound(cow[i].begin(),cow[i].end(),right[i])-cow[i].begin();
				ll cnt=l*r-min(l,r);
				if(cnt>0){
					num_sleeps+=2;
					(ways*=cnt%MOD)%=MOD;
				}
				else if(l>0||r>0){
					num_sleeps+=1;
					(ways*=(l+r)%MOD)%=MOD;
				}
			}
		if(num_sleeps>res){
			res=num_sleeps;
			total=ways;
		}
		else if(num_sleeps==res) (total+=ways%MOD)%=MOD;
		skip:;
	}
	cout<<res<<' '<<total;
}