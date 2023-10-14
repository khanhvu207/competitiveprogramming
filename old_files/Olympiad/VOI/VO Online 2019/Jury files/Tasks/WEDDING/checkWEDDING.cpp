#include "testlib_themis.h"

#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const string TASK_NAME = "WEDDING";

const string YES = "YES";
const string NO = "NO";

#define MAX   1500150
int numS, numT, numP, mod, s[MAX], t[MAX], p[MAX];

void init(void) {
    numP = inf.readInt();
    mod = inf.readInt();
    REP(i, numP) p[i] = inf.readInt();
}

void readArray(InStream &stream, int arr[], int &n, char name) {
    n = stream.readInt(2, numP, format("|%c|", name));
    REP(i, n) arr[i] = stream.readInt(0, mod - 1, format("%c[%d]", name, i));
}

bool checkAnswer(InStream &stream) {
    string answer = stream.readWord(YES + "|" + NO, "yes or no");
    if (answer == NO) return false;

    readArray(stream, s, numS, 'S');
    readArray(stream, t, numT, 'T');

    if (1LL * numS * numT != numP) {
        stream.quitf(_wa, "|S| * |T| = %d * %d <> %d = |P|", numS, numT, numP);
    }

    int cnt = 0;
    REP(i, numS) REP(j, numT) if ((1LL * s[i] * t[j] - p[cnt++]) % mod != 0) {
        stream.quitf(_wa,
            "s[%d] * t[%d] = %d * %d and p[%d] = %d are not congruent modulo %d.",
            i, j, s[i], t[j], cnt - 1, p[cnt - 1], mod);
    }

    return true;
}

void process(void) {
    bool jury = checkAnswer(ans);
    bool cont = checkAnswer(ouf);

    if (jury) {
        if (cont) {
            quitf(_ok, "Correct, |S| = %d, |T| = %d, |P| = %d.", numS, numT, numP);
        } else {
            quitf(_wa, "Contestant thinks that solution does not exist, but it does!");
        }
    } else {
        if (cont) {
            quitf(_fail, "Jury thinks that solution does not exist, but it does!");
        } else {
            quitf(_ok, "Solution does not exist.");
        }
    }
}

int main(int argc, char* argv[]) {
    #ifdef THEMIS
    registerTestlibThemis(TASK_NAME + ".inp", TASK_NAME + ".out");
    #else
    registerTestlibCmd(argc, argv);
    #endif // THEMIS

    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
