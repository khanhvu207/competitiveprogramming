#include <bits/stdc++.h>

using namespace std;

#define INPUT  "10107.INP"
#define OUTPUT "10107.OUT"
#define ll long long
#define ld long double

void fileio()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen(INPUT, "r")){
		freopen(INPUT, "r", stdin);
		freopen(OUTPUT, "w", stdout);
	}
}

vector<int> a;
int x;

int main() {
    fileio();

    while(cin>>x){
        a.emplace_back(x);
        if((int)a.size()&1){
            nth_element(a.begin(),a.begin()+a.size()/2,a.end());
            cout<<a[a.size()/2]<<'\n';
        } else {
            int x,y;
            nth_element(a.begin(),a.begin()+a.size()/2-1,a.end());
            x=a[a.size()/2-1];
            nth_element(a.begin(),a.begin()+a.size()/2,a.end());
            y=a[a.size()/2];

            cout<<((x+y)>>1)<<'\n';
        }
    }
    return 0;
}
