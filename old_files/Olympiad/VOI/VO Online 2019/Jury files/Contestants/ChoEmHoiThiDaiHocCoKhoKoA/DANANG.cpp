#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

#define fi(a,b,c) for(int a=b;a<=c;a++)
#define fo(a,b,c) for(int a=b;a>=c;a--)
#define long long long
#define pll pair<long,long>
#define mp make_pair

const int N = 2e5+1;
const long oo = 1e18;

struct Queue_Type{
  long x, ed, cost;
  Queue_Type () {}
  Queue_Type (long x_, long ed_, long cost_): x(x_), ed(ed_), cost(cost_) {}

  bool operator< (Queue_Type b) const{
    return cost > b.cost;
  }
};

int n, m;
long d, ans;
long cost[N];
vector<pll> list_node[N];
map<long,long> dij[N];
priority_queue<Queue_Type> qu;

void Solve(){
  fi(i,1,n)
    fi(j,0,(int)list_node[i].size()-1)
      dij[i][list_node[i][j].second] = oo;

  ans = oo;
  dij[1][-oo] = 0;
  qu.push(Queue_Type(1,-oo,0));
  while (!qu.empty()){
    long x = qu.top().x, ed = qu.top().ed; qu.pop();
    //cout << x << " " << ed << endl;
    if (x == n){
      ans = min(ans, dij[x][ed]);
      continue;
    }
    fi(i,0,(int)list_node[x].size()-1){
      long y = list_node[x][i].first, edd = list_node[x][i].second;
      if (edd >= ed+d && dij[x][ed]+edd < dij[y][edd]){
        dij[y][edd] = dij[x][ed]+edd;
        qu.push(Queue_Type(y,edd,dij[y][edd]));
      }
    }

    while (!qu.empty() && dij[qu.top().x][qu.top().ed] != qu.top().cost)
      qu.pop();
  }
}

main(){
  freopen("DANANG.inp","r",stdin);
  freopen("DANANG.out","w",stdout);

  scanf("%d%d", &n, &m);
  scanf("%lld", &d);
  fi(i,1,m){
    long x, y, z;
    scanf("%lld%lld%lld", &x, &y, &z);
    //cost[i] = z;
    list_node[x].push_back(mp(y,z));
    list_node[y].push_back(mp(x,z));
  }

  Solve();

  if (ans == oo)
    puts("-1");
  else
    printf("%lld", ans);
}
