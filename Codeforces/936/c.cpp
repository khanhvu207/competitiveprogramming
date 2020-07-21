#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int n;
string s,t,tmp;
vector<int> res,tres;

void shift(const string& s,string& res,int j){
	res=s.substr(j);
	reverse(res.begin(),res.end());
	res+=s.substr(0,j);
}

void solve(string& s){
	while(true){
		int i=0,j=n-1;
		while(i+1<n&&s[i+1]>=s[i]) ++i;
		while(j-1>=0&&s[j-1]>=s[j]) --j;
		if(i==n-1) break;
		if(j<=i) j=i+1;
		shift(s,tmp,j);
		if(s==tmp){
			++j;
			shift(s,tmp,j);
		}
		s=tmp;
		res.push_back(n-j);
	}
}

void tshift(const string& s,string& res,int j){
	res=s.substr(0,j+1);
	reverse(res.begin(),res.end());
	res=s.substr(j+1)+res;
}

void tsolve(string& s){
	while(true){
		int i=0,j=n-1;
		while(i+1<n&&s[i+1]<=s[i]) ++i;
		while(j-1>=0&&s[j-1]<=s[j]) --j;
		if(j==0) break;
		if(i>=j) i=j-1;
		tshift(s,tmp,i);
		if(s==tmp){
			--i;
			tshift(s,tmp,i);
		}
		s=tmp;
		tres.push_back(i+1);
	}
}

int main() {
	#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>s>>t;
	solve(s);
	tsolve(t);
	if(s!=t) cout<<"-1\n";
	else{
		reverse(tres.begin(),tres.end());
		for(int x:tres) res.push_back(x);
		cout<<(int)res.size()<<'\n';
		for(int i:res) cout<<i<<' ';
	}
}