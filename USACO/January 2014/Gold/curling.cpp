#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const double eps = 1e-9;
typedef pair<double,int> pdi;

struct point
{
    double x, y;
    point() { x = 0.0, y = 0.0; }
    point(double xx, double yy) : x(xx), y(yy) {}
};
struct vec
{
    double x, y;
    vec() { x = 0.0, y = 0.0; }
    vec(double xx, double yy) : x(xx), y(yy) {}
};
vec tovec (const point &A, const point &B) { return vec(B.x - A.x, B.y - A.y); }
double dist (const point &A, const point &B) { return hypot(A.x - B.x, A.y - B.y); }
double cross (const vec &A, const vec &B) { return A.x * B.y - B.x * A.y; }
double ccw (const point &p, const point &q, const point &r) { return cross(tovec(p, q), tovec(p, r)) > 0; }
double collinear (const point &p, const point &q, const point &r) { return fabs(cross(tovec(p, q), tovec(p, r))) < eps; }

int n;
point pivot;
vector<point> p[2];

bool grahamScan (const point &L, const point &R)
{
    if (collinear(pivot, L, R))
        return dist(pivot, L) - dist(pivot, R) < 0;
    return ccw(pivot, L, R);
}

vector<point> findCVH (vector<point> P)
{
    if (n<=3)
    {
        if (!(P[0].x==P[n - 1].x&&P[0].y==P[n - 1].y)) P.push_back(P[0]);
        return P;
    }
    int P0=0;
    for (int i=1;i<n;++i)
        if (P[P0].y>P[i].y||(P[P0].y==P[i].y&&P[i].x>P[P0].x)) P0=i;
    point tmp=P[0]; P[0]=P[P0]; P[P0]=tmp;
    pivot=P[0];
    sort(P.begin(),P.end(),grahamScan);
    vector<point> S;
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    int j=2;
    while (j<n)
    {
        int top=(int)S.size()-1;
        if (ccw(S[top-1],S[top],P[j])) S.push_back(P[j++]);
            else S.pop_back();
    }
    return S;
}

int solve(vector<point> cvh,vector<point> t,point centriod) {
    cvh.pop_back();
    double pi=atan(1)*4.0;
    vector<pdi> a;
    for (int i=1;i<(int)cvh.size();++i) {
        cvh[i].x-=centriod.x;
        cvh[i].y-=centriod.y;
        double angle=atan2(cvh[i].y,cvh[i].x)*180.0/pi;
        if (angle<0.0) angle+=360.0;
        a.push_back(pdi(angle,i));
    }
    int cnt=0;
    sort(a.begin(),a.end());
    point O=point(0.0,0.0);
    for (point T:t) {
        T.x-=centriod.x;
        T.y-=centriod.y;
        double angle=atan2(T.y,T.x)*180.0/pi;
        if (angle<0.0) angle+=360.0;
        int pos=lower_bound(a.begin(),a.end(),pdi(angle,0))-a.begin();
        if (pos==(int)a.size()) --pos;
        if (a[pos].first-angle>-eps) pos=(pos-1+(int)a.size())%(int)a.size();
        int cur=a[pos].second;
        int nxt=a[(pos+1)%(int)a.size()].second;
        if (collinear(O,T,cvh[nxt])||collinear(cvh[nxt],T,cvh[cur])||collinear(cvh[cur],T,O)) {
            ++cnt;
            continue;
        }
        double slice_1=fabs(cross(tovec(T,O),tovec(T,cvh[nxt]))/2.0);
        double slice_2=fabs(cross(tovec(T,cvh[nxt]),tovec(T,cvh[cur]))/2.0);
        double slice_3=fabs(cross(tovec(T,cvh[cur]),tovec(T,O))/2.0);
        double area=fabs(cross(tovec(O,cvh[nxt]),tovec(O,cvh[cur]))/2.0);
        cnt+=fabs(slice_1+slice_2+slice_3-area)<=eps;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("curling.in","r",stdin);
    freopen("curling.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;++i)
    {
        double x,y;
        cin>>x>>y;
        p[0].push_back(point(x,y));
    }
    for (int i=0;i<n;++i) {
        double x,y;
        cin>>x>>y;
        p[1].push_back(point(x,y));
    }
    vector<point> cvh[2];
    cvh[0]=findCVH(p[0]);
    cvh[1]=findCVH(p[1]);
    cout<<solve(cvh[0],p[1],cvh[0][0])<<' '<<solve(cvh[1],p[0],cvh[1][0])<<'\n';
}