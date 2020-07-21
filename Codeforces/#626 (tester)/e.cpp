#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size();
	vector<int> preS(n,0);
	vector<int> evenS(n,0),oddS(n,0);
	preS[0]=s[0]=='1';
	if(s[0]=='0') evenS[0]=1;
	for(int i=1;i<n;++i){ 
		preS[i]=preS[i-1];
		oddS[i]=oddS[i-1];
		evenS[i]=evenS[i-1];
		if(s[i]=='1'){
			++preS[i];
			continue;
		}
		if(preS[i]&1) ++oddS[i];
		else ++evenS[i];
	}
	vector<int> preT(m,0);
	vector<int> evenT(m,0),oddT(m,0);
	preT[0]=t[0]=='1';
	if(t[0]=='0') evenT[0]=1;
	for(int i=1;i<m;++i){ 
		preT[i]=preT[i-1];
		oddT[i]=oddT[i-1];
		evenT[i]=evenT[i-1];
		if(t[i]=='1'){
			++preT[i];
			continue;
		}
		if(preT[i]&1) ++oddT[i];
		else ++evenT[i];
	}
	int q;
	cin>>q;
	while(q--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		--a,--b,--c,--d;
		int even_s=evenS[b]-(a?evenS[a-1]:0);
		int odd_s=oddS[b]-(a?oddS[a-1]:0);
		if((a?preS[a-1]:0)&1) swap(even_s,odd_s);
		int even_t=evenT[d]-(c?evenT[c-1]:0);
		int odd_t=oddT[d]-(c?oddT[c-1]:0);
		if((c?preT[c-1]:0)&1) swap(even_t,odd_t);
		int oneS=preS[b]-(a?preS[a-1]:0);
		int oneT=preT[d]-(c?preT[c-1]:0);
		bool res=(even_s==even_t)&&(odd_s==odd_t)&&(oneS==oneT);
		cout<<res<<'\n';
	}
}