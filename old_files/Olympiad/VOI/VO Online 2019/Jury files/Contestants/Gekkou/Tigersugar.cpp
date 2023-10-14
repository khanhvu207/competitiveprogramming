using namespace std ;
#include <bits/stdc++.h>

struct Rectangle
{
    int corner_u , corner_v , corner_p , corner_q ;
    Rectangle(int u = 0 , int v = 0 , int p = 0 , int q = 0)
        : corner_u(u) , corner_v(v) , corner_p(p) , corner_q(q) { }
    friend istream& operator>> (istream& Input , Rectangle& R)
    {
        Input >> R.corner_u >> R.corner_v >> R.corner_p >> R.corner_q ;
        if (R.corner_u > R.corner_p) swap(R.corner_u , R.corner_p) ;
        if (R.corner_v > R.corner_q) swap(R.corner_v , R.corner_q) ;
        return Input ;
    }
} ;

template < typename T1 , typename T2 >
pair < T1 , T2 > operator+ (const pair < T1 , T2 >& A , const pair < T1 , T2 >& B) { return make_pair(A.first + B.first , A.second + B.second) ; }
template < typename T1 , typename T2 >
pair < T1 , T2 > operator- (const pair < T1 , T2 >& A , const pair < T1 , T2 >& B) { return make_pair(A.first - B.first , A.second - B.second) ; }

typedef pair < long long , int > DataType ;
typedef pair < DataType , DataType > SegmentType ;

const int N = 100000 ;
const int M = 200000 ;

int n ;
Rectangle rects[N] ;

SegmentType segment[M] ;
pair < int , int > points[N] ;

void Update(int p , SegmentType add)
{
    for (++p ; p < M + 1 ; p += p & -p)
        segment[p - 1] = segment[p - 1] + add ;
}

SegmentType Query(int p)
{
    SegmentType result ;
    for (++p ; p > 0 ; p -= p & -p)
        result = result + segment[p - 1] ;
    return result ;
}

int Find(vector < pair < int , int > >& lines)
{
    vector < int > candidate ;
    for (int i = 0 ; i < n ; ++i)
    {
        candidate.emplace_back(lines[i].first) ;
        candidate.emplace_back(lines[i].second) ;
    }

    sort(candidate.begin() , candidate.end()) ;
    candidate.erase(unique(candidate.begin() , candidate.end()) , candidate.end()) ;

    #define Index(value) lower_bound(candidate.begin() , candidate.end() , value) - candidate.begin()
    fill(segment , segment + M , SegmentType()) ;
    for (int i = 0 ; i < n ; ++i)
    {
        Update(Index(lines[i].first) , SegmentType(make_pair(lines[i].second , 1) , DataType())) ;
        Update(Index(lines[i].second) , SegmentType(DataType() , make_pair(lines[i].first , 1))) ;
    }

    int found = 0 ;
    long long best_solution = (long long)1e18 + 7 ;
    for (int coordinate : candidate)
    {
        DataType upper = Query(Index(coordinate) - 1).first ;
        DataType lower = Query(candidate.size() - 1).second - Query(Index(coordinate)).second ;

        long long curr_solution = 0 ;
        curr_solution += 1LL * coordinate * upper.second - upper.first ;
        curr_solution += lower.first - 1LL * coordinate * lower.second ;
        if (best_solution > curr_solution) best_solution = curr_solution , found = coordinate ;
    }

    #undef Index
    return found ;
}

int main()
{
    freopen("Tigersugar.inp" , "r" , stdin) ;
    freopen("Tigersugar.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) ;
    cout.tie(nullptr) ;
    cin.tie(nullptr) ;

    cin >> n ;
    for (int i = 0 ; i < n ; ++i)
        cin >> rects[i] ;

    vector < pair < int , int > > u_lines , v_lines ;
    for (int i = 0 ; i < n ; ++i)
    {
        u_lines.emplace_back(rects[i].corner_u , rects[i].corner_p) ;
        v_lines.emplace_back(rects[i].corner_v , rects[i].corner_q) ;
    }

    int U = Find(u_lines) ;
    int V = Find(v_lines) ;

    for (int i = 0 ; i < n ; ++i)
    {
        if (rects[i].corner_u <= U && U <= rects[i].corner_p) points[i].first = U ;
        else points[i].first = (abs(U - rects[i].corner_u) < abs(U - rects[i].corner_p)) ? rects[i].corner_u : rects[i].corner_p ;

        if (rects[i].corner_v <= V && V <= rects[i].corner_q) points[i].second = V ;
        else points[i].second = (abs(V - rects[i].corner_v) < abs(V - rects[i].corner_q)) ? rects[i].corner_v : rects[i].corner_q ;
    }

    long long answer = 0 ;
    for (int i = 0 ; i < n ; ++i)
        answer += abs(U - points[i].first) + abs(V - points[i].second) ;

    cout << answer << "\n" << U << " " << V << "\n" ;
    for (int i = 0 ; i < n ; ++i)
        cout << points[i].first << " " << points[i].second << "\n" ;
    return 0 ;
}
