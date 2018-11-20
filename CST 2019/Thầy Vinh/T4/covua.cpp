#include <bits/stdc++.h>
using namespace std;

int n, score[35];
char x[35][35], m[35][35];
bool flag;

void gen_random_scoreboard(int player)
{
    srand(time(NULL));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
        {
            if (x[i][j]!='.')
            {
                m[i][j]=x[i][j];
            } else
            {
                if (i==player)
                {
                    m[i][j]='1';
                    continue;
                }
                int seed=rand()%3;
                if (seed==0)
                    m[i][j]='d';
                else if (seed==1)
                    m[i][j]='0';
                else if (seed==2)
                    m[i][j]='1';
            }
        }
}

void doo(int player)
{
        int max_score=0;
        for (int i=0; i<n; i++)
            score[i]=0;
        gen_random_scoreboard(player);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (m[i][j]=='1') score[i]+=2;
                    else if (m[i][j]=='d') score[i]+=1;
            }
            max_score=max(max_score, score[i]);
        }
        if (max_score!=score[player])
        {
            flag=0;
            return;
        }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("covua.inp", "r", stdin);
    freopen("covua.out", "w", stdout);
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> x[i][j];
    double time_per_player = 0.900000 / (n * 1.0), last_time = 0.0;
    for (int i=0; i<n; i++)
    {
        flag=1;
        while ((clock() - last_time) <= time_per_player * CLOCKS_PER_SEC)
        {
            doo(i);
        }
        if (flag)
            cout << i+1 << ' ';
        last_time=clock();
    }
    return 0;
}
