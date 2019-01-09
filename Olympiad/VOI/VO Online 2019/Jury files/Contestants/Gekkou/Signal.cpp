using namespace std ;
#include <bits/stdc++.h>

struct Rectangle
{
    double corner_u , corner_v , corner_p , corner_q ;
    Rectangle(double u = 0 , double v = 0 , double p = 0 , double q = 0)
        : corner_u(u) , corner_v(v) , corner_p(p) , corner_q(q) { }
} ;

const int K = 4 ;
const int N = 50000 ;
const double L = 0.0000001 ;
const Rectangle iRect(-10000000 , -10000000 , 10000000 , 10000000) ;

int n , k , power[N] ;
pair < int , int > points[N] ;

bool OK(const Rectangle& A , const Rectangle& B)
{
    if (min(A.corner_p , B.corner_p) <= max(A.corner_u , B.corner_u)) return false ;
    if (min(A.corner_q , B.corner_q) <= max(A.corner_v , B.corner_v)) return false ;
    return true ;
}
void Inter(Rectangle& A , const Rectangle& B)
{
    A.corner_u = max(A.corner_u , B.corner_u) ;
    A.corner_v = max(A.corner_v , B.corner_v) ;
    A.corner_p = min(A.corner_p , B.corner_p) ;
    A.corner_q = min(A.corner_q , B.corner_q) ;
}

int FindTutor(double s)
{
    vector < Rectangle > rects ;
    for (int i = 0 ; i < n ; ++i)
    {
        double r = (double)power[i] * s ;
        double u = (double)points[i].first , v = (double)points[i].second - r ;
        double p = (double)points[i].first , q = (double)points[i].second + r ;
        rects.emplace_back(u + v , v - u , p + q , q - p) ;
    }

    vector < bool > is_inter(n) ;
    for (int tutor = 0 ; tutor < K ; ++tutor)
    {
        Rectangle curr_rect(iRect) ;
        for (int i = 0 ; i < n ; ++i)
            if (!is_inter[i] && OK(curr_rect , rects[i]))
                is_inter[i] = true , Inter(curr_rect , rects[i]) ;
        if (!count(is_inter.begin() , is_inter.end() , 0)) return tutor + 1 ;
    }

    return K ;
}

int main()
{
    freopen("Signal.inp" , "r" , stdin) ;
    freopen("Signal.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) ;
    cout.tie(nullptr) ;
    cin.tie(nullptr) ;

    cin >> n >> k ;
    for (int i = 0 ; i < n ; ++i)
    {
        int u , v ;
        cin >> u >> v >> power[i] ;
        points[i] = make_pair(u , v) ;
    }

    #define mid (low + high) / 2
    double low = 0 - L , high = 10000000 ;
    while (low + L < high) (FindTutor(mid) <= k ? high : low) = mid ;
    #undef mid

    cout << fixed << setprecision(12) << high << "\n" ;
    return 0 ;
}
