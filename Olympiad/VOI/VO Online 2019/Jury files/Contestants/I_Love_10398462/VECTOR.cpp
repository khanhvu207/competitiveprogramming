#include <bits/stdc++.h>

using namespace std;

int used[10000010];
vector <int> v[3];
vector< pair<int,char> > res;
int n,m,p,q;

void eratosthenes(){
    for (int i=2; i<=sqrt(1e7); i++)
        if (!used[i])
            for (int j=i*i; j<=1e7;  j+=i)
                used[j]=i;
    for (int i=2; i<=1e7; i++)
        if (!used[i]) used[i]=i;
}

void solve(){
    sort(v[2].begin(),v[2].end());

    int n,c;
    n=v[2].size();
    v[2].push_back(0);
    c=1;
    for (int i=1; i<=n; i++)
        if (v[2][i]==v[2][i-1]) c++;
        else{
            for (int j=1; j<=c/2; j++){
                res.push_back( {v[2][i-1],'W'} );
                v[1].push_back(v[2][i-1]);
            }

            if (c%2!=0){
                res.push_back({v[2][i-1],'L'});
                res.push_back( {v[2][i-1],'W'} );
                v[1].push_back(v[2][i-1]);
            }
            c=1;
        }

    sort(v[1].begin(),v[1].end());
    n=v[1].size();
    v[1].push_back(0);
    c=1;
    for (int i=1; i<=n; i++)
        if (v[1][i]==v[1][i-1]) c++;
        else{
            for (int j=1; j<=c/2; j++)
                res.push_back( {v[1][i-1],'D'} );

            if (c%2!=0){
                res.push_back({v[1][i-1],'L'});
                res.push_back({v[1][i-1],'L'});
                res.push_back( {v[1][i-1],'W'} );
                res.push_back( {v[1][i-1],'D'} );
            }
            c=1;
        }
}

void fact(int a,int i){
    while (a!=1){
        v[i].push_back(used[a]);
        a/=used[a];
    }
}

int main(){


    eratosthenes();

    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        scanf("%d",&p);
        fact(p,1);
    }

    scanf("%d",&m);
    for (int i=1; i<=m; i++){
        scanf("%d",&q);
        fact(q,2);
    }

    solve();

    cout<<res.size()<<"\n";
    for (int i=0; i<res.size(); i++)
        cout<<res[i].first<<" "<<res[i].second<<"\n";

    return 0;

}
