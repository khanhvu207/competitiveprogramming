#include<bits/stdc++.h>
using namespace std;

int n, m;

vector< pair<int,int> > A, B;

int main()
{
    freopen("VECTOR.inp","r",stdin);
    freopen("VECTOR.out","w",stdout);

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        for(int j=2;j<=sqrt(a);j++)
        {
            if(a % j == 0)
            {
                int dem = 0;
                while(a % j == 0)
                {
                    ++dem;
                    a /= j;
                }
                A.push_back( make_pair(j, dem));
            }
        }
        if(a > 1) A.push_back( make_pair(a, 1));
    }

    cin >> m;

    for(int i=1;i<=m;i++)
    {
        int a;
        cin >> a;
        for(int j=2;j<=sqrt(a);j++)
        {
            if(a % j == 0)
            {
                int dem = 0;
                while(a % j == 0)
                {
                    ++dem;
                    a /= j;
                }
                B.push_back( make_pair(j, dem));
            }
        }
        if(a > 1) B.push_back( make_pair(a, 1));
    }

    vector< pair<int,int> > themA;

    vector< pair<int,int> > themB;

    sort(B.begin(), B.end());

    int dem = 0;

    for(int i=0;i<B.size();i++)
    {
        if(i && B[i].first != B[i-1].first)
        {
            if(dem % 2 == 1)
            {
                themB.push_back( make_pair(B[i-1].first, 1));
                ++dem;
            }
            themA.push_back( make_pair(B[i-1].first, dem/2));
            dem = 0;
        }
        dem = dem + B[i].second;
    }

    if(dem % 2 == 1) themB.push_back( make_pair(B.back().first, 1)), ++dem;
    themA.push_back( make_pair(B.back().first, dem/2));

    sort(themA.begin(), themA.end());
    sort(themB.begin(), themB.end());

    int cur = 1;

    queue< pair<int,int> > turn;

    for(int i=0;i<themB.size();i++)
    {
        if(cur * themB[i].first <= 1000000)
        {
            cur = cur * themB[i].first;
        }
        else
        {
            turn.push( make_pair(1, cur));

            cur = themB[i].first;
        }
    }
    turn.push( make_pair(1, cur));

    cur = 1;

    for(int i=0;i<themA.size();i++)
    {
        for(int j=1;j<=themA[i].second;j++)
        {
            if(cur * themA[i].first <= 10000000)
            {
                cur = cur * themA[i].first;
            }
            else
            {
                turn.push( make_pair(2, cur));
                cur = themA[i].first;
            }
        }
        A.push_back( make_pair(themA[i].first, themA[i].second));
    }

    turn.push( make_pair(2, cur));

    sort(A.begin(), A.end());

    dem = 0;

    for(int i=0;i<A.size();i++)
    {
        if(i && A[i].first != A[i-1].first)
        {
            if(dem % 2 == 1)
            {
                turn.push( make_pair(1, A[i-1].first));
                turn.push( make_pair(1, A[i-1].first));

                turn.push( make_pair(2, A[i-1].first));

                ++dem;
            }

            for(int j=2;j<=dem;j+=2)
            {
                turn.push( make_pair(3, A[i-1].first));
            }

            dem = 0;
        }

        dem = dem + A[i].second;
    }

    if(dem % 2 == 1)
    {
        turn.push( make_pair(1, A.back().first));
        turn.push( make_pair(1, A.back().first));

        turn.push( make_pair(2, A.back().first));
        ++dem;
    }

    for(int j=2;j<=dem;j+=2)
    {
        turn.push( make_pair(3, A.back().first));
    }

    cout << turn.size() << endl;

    while(turn.size())
    {
        cout << turn.front().second << " ";
        if(turn.front().first == 1) cout << "D\n";
        else if(turn.front().first == 2) cout << "W\n";
        else cout << "L\n";

        turn.pop();
    }

    return 0;
}

