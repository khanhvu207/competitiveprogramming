using namespace std ;
#include <bits/stdc++.h>

const int K = 15000000 ;
const int M = 1000000 ;

int k , mod , p[K] ;
long long inv_mod[M] ;

long long Power(long long a , long long b)
{
    if (b == 0) return 1LL ;
    long long product = Power(a , b >> 1) ;
    product = product * product % mod ;

    if (b % 2 == 0) return product ;
    return product * a % mod ;
}

void Gekkou(int s)
{
    vector < int > a , b ;
    for (int i = 0 ; i < k ; i += s)
        a.emplace_back(p[i]) ;

    int start = 0 ;
    while (start < (int)a.size() && a[start] == 0) ++start ;
    if (start == (int)a.size()) start = 0 ;
    for (int i = 0 ; i < s ; ++i)
        b.emplace_back(1LL * p[start * s + i] * inv_mod[a[start]] % mod) ;

    bool ok = true ;
    int n = a.size() , m = b.size() ;
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < m ; ++j)
            if (1LL * a[i] * b[j] % mod != p[i * s + j])
                ok = false ;

    if (!ok) return ;
    cout << "YES\n" ;

    cout << a.size() << " " ;
    for (int i = 0 ; i < n ; ++i)
        cout << a[i] << (i + 1 != n ? " " : "\n" ) ;

    cout << b.size() << " " ;
    for (int i = 0 ; i < m ; ++i)
        cout << b[i] << (i + 1 != m  ? " " : "\n" ) ;
    exit(false) ;
}

int main()
{
    freopen("Wedding.inp" , "r" , stdin) ;
    freopen("Wedding.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) ;
    cout.tie(nullptr) ;
    cin.tie(nullptr) ;

    cin >> k >> mod ;
    for (int i = 0 ; i < k ; ++i)
        cin >> p[i] ;

    for (int i = 0 ; i < mod ; ++i)
        inv_mod[i] = Power(i , mod - 2) ;

    for (int i = 2 ; i * i < k + 1 ; ++i)
        if (k % i == 0) Gekkou(i) , Gekkou(k / i) ;

    cout << "NO\n" ;
    return 0 ;
}
