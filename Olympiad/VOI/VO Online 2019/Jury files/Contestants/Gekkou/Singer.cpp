using namespace std ;
#include <bits/stdc++.h>

const int N = 420 ;
const int Mod = 998244353 ;

int n , len , seq ;

long long answer ;
vector < int > curr_pres(1 , 0) ;

void Gekkou(int i)
{
    if (i == n)
    {
        int counter = 0 ;
        for (int i = 0 ; i + len <= n + 1; ++i)
        {
            int a_min = *min_element(curr_pres.begin() + i , curr_pres.begin() + i + len) ;
            int a_max = *max_element(curr_pres.begin() + i , curr_pres.begin() + i + len) ;
            if (a_max - a_min <= 1) ++counter ;
        }

        if (counter == seq) ++answer ;
        return  ;
    }

    curr_pres.emplace_back(curr_pres.back() + 1) ;
    Gekkou(i + 1) ;
    curr_pres.pop_back() ;

    curr_pres.emplace_back(curr_pres.back() - 1) ;
    Gekkou(i + 1) ;
    curr_pres.pop_back() ;
}

int main()
{
    freopen("Singer.inp" , "r" , stdin) ;
    freopen("Singer.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) ;
    cout.tie(nullptr) ;
    cin.tie(nullptr) ;

    cin >> n >> len >> seq ;

    Gekkou(0) ;
    cout << answer << "\n" ;
    return 0 ;
}
