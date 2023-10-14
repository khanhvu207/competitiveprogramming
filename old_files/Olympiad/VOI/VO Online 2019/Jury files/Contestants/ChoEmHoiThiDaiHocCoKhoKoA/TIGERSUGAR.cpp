#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

#define fi(a,b,c) for(int a=b;a<=c;a++)
#define fo(a,b,c) for(int a=b;a>=c;a--)
#define long long long
#define pii pair<int,int>
#define mp make_pair

const int N = 1e5+1;

struct List_Type{
  int type, x, l, r;
  List_Type() {}
  List_Type(int type_, int x_, int l_, int r_): type(type_), x(x_), l(l_), r(r_) {}

  bool operator< (List_Type b) const{
    return x < b.x;
  }
};

int n;
pii a[N], b[N], c[N];
vector<int> list_point;
vector<List_Type> list_;

bool Cmp(pii a, pii b){
  return (a.second < b.second);
}

void Init(){
  list_.clear(); list_point.clear();
  fi(i,1,n){
    int l = c[i].first, r = c[i].second, mid = (l+r+1)>>1;
    list_.push_back(List_Type(1,l,l,r));
    list_.push_back(List_Type(2,r,l,r));
  }

  sort(list_.begin(),list_.end());
  list_point.push_back(list_[0].x);
  fi(i,1,list_.size()-1)
    if (list_[i].x != list_[i-1].x)
      list_point.push_back(list_[i].x);
}

pii Find(){
  Init();
  /*fi(i,0,list_point.size()-1)
    cout << list_point[i] << " ";
  cout << endl;
  fi(i,0,list_.size()-1)
    cout << list_[i].type << " " << list_[i].x << " " << list_[i].l << " " << list_[i].r << endl;
  cout << endl;*/

  int cl = 0, cr = n, res = 0, p = list_point[0], ans = 0, l = 0;
  fi(i,1,n)
    res += c[i].first-p;
  ans = res;

  fi(i,0,list_point.size()-1){
    int point = list_point[i];
    while (l < list_.size() && list_[l].x <= point){
      if (list_[l].type == 1)
        cr--;
      if (list_[l].type == 2)
        cl++;
      l++;
    }

    //cout << res << endl;
    if (res < ans){
      p = point; ans = res;
    }

    res += cl-cr;
  }

  return mp(p,ans);
}

main(){
  freopen("TIGERSUGAR.inp","r",stdin);
  freopen("TIGERSUGAR.out","w",stdout);

  scanf("%d", &n);
  fi(i,1,n){
    scanf("%d%d%d%d", &a[i].first, &a[i].second, &b[i].first, &b[i].second);
    if (a[i].first > b[i].first)
      swap(a[i].first, b[i].first);
    if (a[i].second > b[i].second)
      swap(a[i].second, b[i].second);
  }

  int x, y, s = 0;
  pii res;
  fi(i,1,n)
    c[i] = mp(a[i].first, b[i].first);
  res = Find();
  x = res.first; s += res.second;

  fi(i,1,n)
    c[i] = mp(a[i].second, b[i].second);
  res = Find();
  y = res.first; s += res.second;

  printf("%d\n", s);
  printf("%d %d\n", x, y);
  fi(i,1,n){
    int u, v;
    if (a[i].first <= x && x <= b[i].first)
      u = x;
    else
      if (x < a[i].first)
        u = a[i].first;
      else
        u = b[i].first;

    if (a[i].second <= y && y <= b[i].second)
      v = y;
    else
      if (y < a[i].second)
        v = a[i].second;
      else
        v = b[i].second;
    printf("%d %d\n", u, v);
  }
}
