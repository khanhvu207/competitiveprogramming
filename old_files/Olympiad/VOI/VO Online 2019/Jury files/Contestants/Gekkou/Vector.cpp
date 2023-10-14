using namespace std ;
#include <bits/stdc++.h>

const int V = 10000000 ;

map < int , int > p_a , p_b , p_c ;
map < int , int > a_count , b_count ;
vector < pair < int , char  > > answer ;

void GetCount(map < int , int >& count_x)
{
    int k ;
    cin >> k ;
    for (int i = 0 ; i < k ; ++i)
    {
        int value ;
        cin >> value ;
        for (int p = 2 ; p * p <= value ; ++p)
            for ( ; value % p == 0 ; value /= p)
                ++count_x[p] ;
        if (value != 1) ++count_x[value] ;
    }
}
void GetAnswer(map < int , int >& p_x , char cond)
{
    int curr = 1 ;
    for (auto fact : p_x)
        for (auto p = fact ; p.second > 0 ; --p.second , curr *= p.first)
            if (1LL * curr * p.first > V)
                answer.emplace_back(curr , cond) ;
    answer.emplace_back(curr , cond) ;
}

int main()
{
    freopen("Vector.inp" , "r" , stdin) ;
    freopen("Vector.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) ;
    cout.tie(nullptr) ;
    cin.tie(nullptr) ;

    GetCount(a_count) ;
    for (auto fact : a_count)
        if (fact.second % 2)
            ++p_a[fact.first] ;

    GetCount(b_count) ;
    for (auto fact : b_count)
        while (fact.second > 2 * p_a[fact.first])
            p_a[fact.first] += 2 ;

    for (auto fact : p_a) p_b[fact.first] = (a_count[fact.first] + fact.second) >> 1 ;
    for (auto fact : p_a) p_c[fact.first] = 2 * fact.second - b_count[fact.first] ;

    GetAnswer(p_c , 'D') ;
    GetAnswer(p_a , 'W') ;
    GetAnswer(p_b , 'L') ;

    cout << answer.size() << "\n" ;
    for (auto sol : answer)
        cout << sol.first << " " << sol.second << "\n" ;

    return 0 ;
}
