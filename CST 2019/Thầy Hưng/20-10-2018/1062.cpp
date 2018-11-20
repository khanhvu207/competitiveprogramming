#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

typedef stack<int> containers;
string s;
int C = 0;
vector<containers> p;

int main()
{
    freopen("1062.inp", "r", stdin);
    freopen("1062.out", "w", stdout);
    while (cin >> s)
    {
        if (s == "end") return 0;
        p.clear();
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (p.empty())
            {
                containers x;
                x.push(s[i]);
                p.push_back(x);
                continue;
            } else
            {
                int flag = 0;
                for (int j = 0; j < (int)p.size(); j++)
                    if (p[j].top() >= s[i])
                    {
                        p[j].push(s[i]);
                        flag = 1;
                        break;
                    }
                if (!flag)
                {
                    containers x;
                    x.push(s[i]);
                    p.push_back(x);
                    continue;
                }
            }
        }
        cout << "Case " << ++C << ": " << (int)p.size() << '\n';
    }
    return 0;
}
