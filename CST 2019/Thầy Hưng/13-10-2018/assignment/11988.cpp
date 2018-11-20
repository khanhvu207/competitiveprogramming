#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

string s;
list<char> t;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("11988.INP", "r", stdin);
    freopen("11988.OUT", "w", stdout);
   	while (cin >> s)
   	{
   		t.clear();
   		list<char>::iterator it = t.begin();
   		for (int i = 0; i < (int)s.size(); i++)
   		{
   			if (s[i] != '[' && s[i] != ']')
   			{
   				t.insert(it, s[i]);
   				continue;
   			}
   			if (s[i] == '[') it = t.begin();
   				else it = t.end();
   		}
   		for (char x : t)
   			cout << x;
   		cout << '\n';
   	}
    return 0;
}
