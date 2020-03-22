#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int t, n;
long long a, b, c, v[1000015], dp[1000015];
vector<pair<long long, long long> > ev;

bool chkbad (int l1, int l2, int l3)
{
	//l1-l2=(b2-b1)/(slope1-slope2)
	//l1-l3=(b3-b1)/(slope1-slope3)
	return (ev[l3].second-ev[l1].second)*(ev[l1].first-ev[l2].first)<(ev[l2].second-ev[l1].second)*(ev[l1].first-ev[l3].first);
}

void add (long long slope, long long yb)
{
	ev.push_back(make_pair(slope, yb));
	while ((int)ev.size()>=3&&chkbad((int)ev.size()-3, (int)ev.size()-2, (int)ev.size()-1)) ev.erase(ev.end()-2);
}

long long bns (long long x)
{
	int l=0, r=(int)ev.size()-1, k=0;
	while (l<=r)
	{
		int m=(l+r)>>1;
		if (m+1<(int)ev.size()&&(ev[m+1].first*x+ev[m+1].second>ev[m].first*x+ev[m].second)) k=m+1, l=m+1;
			else r=m-1;
	}
	return ev[k].first*x+ev[k].second;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		ev.clear();
		cin >> n;
		cin >> a >> b >> c;
		for (int i=0; i<n; i++) cin >> v[i];
		long long p=0ll;
		add(0ll, 0ll);
		for (int i=0; i<n; i++)
		{
			p+=v[i];
			dp[i]=bns(p)+a*p*p+b*p+c;
			add(-2ll*a*p, dp[i]+a*p*p-b*p);
		}
		cout << dp[n-1] << '\n';
	}
    return 0;
}
