#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

pair< pair<int,int> , pair<int,int> > r[maxn];

int n;

typedef long long ll;

ll val = 1e18;
int toadox, toadoy;

ll ngang(int u)
{
    ll dis = 0;

    for(int i=1;i<=n;i++)
    {
        if(r[i].first.first <= u && u <= r[i].second.first)
        {
            continue;
        }
        else dis = dis + min(abs(r[i].first.first - u), abs(r[i].second.first - u));
    }

    return dis;
}

ll doc(int u)
{
    ll dis = 0;

    for(int i=1;i<=n;i++)
    {
        if(r[i].first.second <= u && u <= r[i].second.second)
        {
            continue;
        }
        else dis = dis + min(abs(r[i].first.second - u), abs(r[i].second.second - u));
    }

    return dis;
}

int main()
{
    freopen("TIGERSUGAR.inp","r",stdin);
    freopen("TIGERSUGAR.out","w",stdout);

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> r[i].first.first >> r[i].first.second >> r[i].second.first >> r[i].second.second;
        if(r[i].first.first > r[i].second.first) swap(r[i].first.first, r[i].second.first);
        if(r[i].first.second > r[i].second.second) swap(r[i].first.second, r[i].second.second);
    }

    int L = 0, R = 1000000000;

    for(int i=1;i<=35;i++)
    {
        int mid1 = (L + (R - L)/3);
        int mid2 = (R - (R - L)/3);

        if(ngang(mid1) > ngang(mid2))
        {
            L = mid1;
        }
        else
        {
            R = mid2;
        }
    }

    int cs = -1;
    for(int i=L;i<=R;i++)
    {
        if(cs == -1) cs = i;
        else
        {
            if(ngang(i) < ngang(cs)) cs = i;
        }
    }
    toadox = cs;
    L = 0, R = 1000000000;

    for(int i=1;i<=35;i++)
    {
        int mid1 = (L + (R - L)/3);
        int mid2 = (R - (R - L)/3);

        if(doc(mid1) > doc(mid2))
        {
            L = mid1;
        }
        else
        {
            R = mid2;
        }
    }
    cs = -1;
    for(int i=L;i<=R;i++)
    {
        if(cs == -1) cs = i;
        else
        {
            if(doc(i) < doc(cs)) cs = i;
        }
    }
    toadoy = cs;

    cout << ngang(toadox) + doc(toadoy) << endl;

    cout << toadox << " " << toadoy << endl;

    for(int i=1;i<=n;i++)
    {
        if(r[i].first.first <= toadox && toadox <= r[i].second.first)
        {
            if(r[i].first.second <= toadoy && toadoy <= r[i].second.second)
            {
                cout << toadox << " " << toadoy << endl;
            }
            else
            {
                if(toadoy < r[i].first.second) cout << toadox << " " << r[i].first.second << endl;
                else cout << toadox << " " << r[i].second.second << endl;
            }
        }
        else
        {
            if(r[i].first.second <= toadoy && toadoy <= r[i].second.second)
            {
                if(toadox < r[i].first.first) cout << r[i].first.first << " " << toadoy << endl;
                else cout << r[i].second.first << " " << toadoy << endl;
            }
            else
            {
                if(toadox < r[i].first.first) cout << r[i].first.first << " ";
                else cout << r[i].second.first << " ";

                if(toadoy < r[i].first.second) cout << r[i].first.second << endl;
                else cout << r[i].second.second << endl;
            }
        }
    }
}
