#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> P;

const int N=2e5+5;
int n,a[N],pos[N],f[25][N];
priority_queue<pair<int,P>> heap;

int rmq(int l,int r){
	int k=log2((r-l)/2+1); // half of the len cuz we just consider the postions which have the same parity with l
	return min(f[k][l],f[k][r-2*((1<<k)-1)]);
}

void add(int l,int r){
	if(l>r) return;
	int x=rmq(l,r-1);
	heap.push(make_pair(-x,make_pair(l,r)));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
		pos[a[i]]=i;
	}
	for(int i=0;i<n;++i)
		f[0][i]=a[i];
	for(int i=1,l=2;i<20;++i,l<<=1) // f[i][j] = min of elements whose positions bear the same parity with j
		for(int j=0;j<n;++j){
			f[i][j]=f[i-1][j];
			if(j+l<n) f[i][j]=min(f[i][j],f[i-1][j+l]);
		}
	add(0,n-1);
	for(int i=0;i<n/2;++i){
		pair<int,P> seg=heap.top();
		heap.pop();
		int l=seg.second.first,r=seg.second.second;
		int q1=rmq(l,r-1);
		int pos1=pos[q1];
		int q2=rmq(pos1+1,r);
		int pos2=pos[q2];
		cout<<q1<<' '<<q2<<' ';
		add(l,pos1-1);
		add(pos1+1,pos2-1);
		add(pos2+1,r);
	}
	cout<<'\n';
}


