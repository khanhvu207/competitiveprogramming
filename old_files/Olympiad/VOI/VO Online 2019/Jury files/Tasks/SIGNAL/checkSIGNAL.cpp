#include "testlib_themis.h"
#include <cmath>

using namespace std;

const string TASK_NAME = "SIGNAL";
const double EPS = 1E-4 + 1E-6 + 1E-9;

int main(int argc, char * argv[])
{
    setName("compare two sequences of doubles, max absolute or relative  error = %.7f", EPS);

    #ifdef THEMIS
    registerTestlibThemis(TASK_NAME + ".inp", TASK_NAME + ".out");
    #else
    registerTestlibCmd(argc, argv);
    #endif // THEMIS

    int n = 0;
    double j = 0, p = 0;

    while (!ans.seekEof())
    {
        n++;
        j = ans.readDouble();
        p = ouf.readDouble();
        if (!doubleCompare(j, p, EPS))
        {
            quitf(_wa, "%d%s numbers differ - expected: '%.7f', found: '%.7f', error = '%.7f'",
                n, englishEnding(n).c_str(), j, p, doubleDelta(j, p));
        }
    }

    if (n == 1)
        quitf(_ok, "found '%.7f', expected '%.7f', error '%.7f'", p, j, doubleDelta(j, p));

    quitf(_ok, "%d numbers", n);
}
