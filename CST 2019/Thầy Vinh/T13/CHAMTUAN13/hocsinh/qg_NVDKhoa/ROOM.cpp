#include <iostream>
#include <cstdio>
#include <set>
#define x first
#define y second
#define point pair<int,int>
using namespace std;

const int
    td[] = {-1,-1,0,1,1,1,0,-1},
    tc[] = {0,1,1,1,0,-1,-1,-1};
int n,Count,k,rev[10];
point s,t,p1,p2;
set<point> com[10], node;
char c;

int main()
{
    rev[0] = 4;
    rev[1] = 5;
    rev[2] = 6;
    rev[3] = 7;
    rev[4] = 0;
    rev[5] = 1;
    rev[6] = 2;
    rev[7] = 3;
    freopen("ROOM.inp","r",stdin);
    freopen("ROOM.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        node.insert(s);
        scanf(" %c",&c); k = c-'0';
        t.x = s.x+td[k];
        t.y = s.y+tc[k];
        if (com[k].count(s) || com[rev[k]].count(t)) goto skip;
        Count += ( node.count(t) != 0 );
        switch(k){
        case 1:
            p1.x = s.x-1;   p1.y = s.y;
            p2.x = s.x;     p2.y = s.y+1;
            Count += ( com[3].count(p1) || com[7].count(p2) );
            break;
        case 3:
            p1.x = s.x+1;   p1.y = s.y;
            p2.x = s.x;     p2.y = s.y+1;
            Count += ( com[1].count(p1) || com[5].count(p2) );
            break;
        case 5:
            p1.x = s.x;     p1.y = s.y-1;
            p2.x = s.x+1;   p2.y = s.y;
            Count += ( com[3].count(p1) || com[7].count(p2) );
            break;
        case 7:
            p1.x = s.x;     p1.y = s.y-1;
            p2.x = s.x-1;   p2.y = s.y;
            Count += ( com[1].count(p1) || com[5].count(p2) );
            break;
        }
        com[k].insert(s);
        skip:
        s = t;
    }
    printf("%d",Count);
}
