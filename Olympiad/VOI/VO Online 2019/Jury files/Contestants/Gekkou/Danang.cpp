using namespace std ;
#include <bits/stdc++.h>

struct HeapType
{
    int destination , prev_weight ;
    long long distance ;

    HeapType(int u = 0 , int w = 0 , long long d = 0) : destination(u) , prev_weight(w) , distance(d) { }
    friend bool operator< (const HeapType& A , const HeapType& B) { return A.distance > B.distance ; }
} ;

const int N = 200000 ;
const long long Infi = (long long)1e18 + 7 ;

int n , m , delta ;
vector < pair < int , int > > near[N] ;

long long dist[N] ;
priority_queue < HeapType > my_heap ;

int main()
{
    freopen("Danang.inp" , "r" , stdin) ;
    freopen("Danang.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) ;
    cout.tie(nullptr) ;
    cin.tie(nullptr) ;

    cin >> n >> m >> delta ;
    for (int i = 0 ; i < m ; ++i)
    {
        int u , v , w ;
        cin >> u >> v >> w ;
        near[u - 1].emplace_back(v - 1 , w) ;
        near[v - 1].emplace_back(u - 1 , w) ;
    }

    fill(dist , dist + n , Infi) ;
    my_heap.emplace(0 , -1 , dist[0] = 0) ;

    while (my_heap.size())
    {
        int u = my_heap.top().destination ;
        int prev_w = my_heap.top().prev_weight ;
        long long curr_dist = my_heap.top().distance ;
        my_heap.pop() ;

        if (curr_dist > dist[u]) continue ;
        for (pair < int , int > edge : near[u])
        {
            int v = edge.first , w = edge.second ;
            if (prev_w < 0 || (delta <= w - prev_w))
                if (dist[v] > dist[u] + w)
                    my_heap.emplace(v , w , dist[v] = curr_dist + w) ;
        }
    }

    if (dist[n - 1] == Infi)
        return cout << "-1\n" , 0 ;
    cout << dist[n - 1] << "\n" ;
    return 0 ;
}
