/*
	Hm this problem seems not to difficult... 
	UPD: yes, it is
*/

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int find_pos(int val,vector<int>& a){
	return distance(a.begin(),upper_bound(a.begin(),a.end(),val));
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,res=0;
	cin>>n;
	vector<int> a(n);
	for(int& x:a) cin>>x;
	for(int i=0;i<25;++i){
		int cnt=0;
		vector<int> p1,p2;
		for(int x:a) 
			if((x>>i)&1) p1.push_back(x&((1<<i)-1));
			else p2.push_back(x&((1<<i)-1));
		sort(p1.begin(),p1.end());
		sort(p2.begin(),p2.end());
		for(int x:p1){
			cnt+=(int)p1.size()-find_pos((1<<i)-x-1,p1);
			if(x*2>=(1<<i)) --cnt;
		}
		for(int x:p2){
			cnt+=(int)p2.size()-find_pos((1<<i)-x-1,p2);
			if(x*2>=(1<<i)) --cnt;
		}
		cnt/=2;
		for(int x:p1) cnt+=find_pos((1<<i)-x-1,p2);
		if(cnt&1) res|=1<<i;
	}
	cout<<res;
}