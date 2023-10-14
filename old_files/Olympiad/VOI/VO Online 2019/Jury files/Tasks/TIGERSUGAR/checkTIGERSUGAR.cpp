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

const string TASK_NAME = "TIGERSUGAR";

const int MAX_CORD = (int)1e9;
int readCord(InStream &stream, const string &name, int lower = 0, int upper = MAX_CORD) {
    return stream.readInt(lower, upper, name);
}

struct Point {
    int x, y;

    Point(int _x = 0, int _y = 0) {
        x = _x; y = _y;
    }

    Point(InStream &stream, const string &name,
          int minX = 0, int maxX = MAX_CORD, int minY = 0, int maxY = MAX_CORD) {
        x = readCord(stream, name + ".x", minX, maxX);
        y = readCord(stream, name + ".y", minY, maxY);
    }
};

struct Area {
    Point lower, upper;
    int id;

    Area() {
        id = 0;
    }

    Area(InStream &stream, int id) {
        string name = format("areas[%d]", id);
        this->id = id;

        lower = Point(stream, name + ".first");
        upper = Point(stream, name + ".second");
        if (lower.x > upper.x) swap(lower.x, upper.x);
        if (lower.y > upper.y) swap(lower.y, upper.y);
    }

    Point readPointInside(InStream &stream) {
        string name = format("points[%d]", id);
        return Point(stream, name, lower.x, upper.x, lower.y, upper.y);
    }
};

long long dis(const Point &a, const Point &b) {
    return Abs(a.x - b.x) + Abs(a.y - b.y);
}

#define MAX   100100
Area areas[MAX];
Point center, points[MAX];
int n;

void init(void) {
    n = inf.readInt();
    FOR(i, 1, n) areas[i] = Area(inf, i);
}

long long checkAnswer(InStream &stream) {
    long long res = stream.readLong();
    long long sum = 0;

    center = Point(stream, "center");
    FOR(i, 1, n) {
        points[i] = areas[i].readPointInside(stream);
        sum += dis(center, points[i]);
    }

    if (res != sum) {
        stream.quitf(_wa, "Total distance mismatch: received %I64d, calculated %I64d.", res, sum);
    }
    return sum;
}

void process(void) {
    long long jury = checkAnswer(ans);
    long long cont = checkAnswer(ouf);

    if (jury == cont) {
        quitf(_ok, "Best total distance: %I64d, center: (%d, %d).", jury, center.x, center.y);
    } else if (jury < cont) {
        quitf(_wa, "Jury has better answer (jury: %I64d, contestant: %I64d).", jury, cont);
    } else if (jury > cont) {
        quitf(_fail, "Jury has worse answer (jury: %I64d, contestant: %I64d).", jury, cont);
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
