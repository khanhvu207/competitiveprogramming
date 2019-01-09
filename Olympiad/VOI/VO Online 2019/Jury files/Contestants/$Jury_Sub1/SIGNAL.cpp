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

struct Person {
    int x, y, s;

    Person() {
        x = y = s = 0;
    }

    void input(void) {
        scanf("%d%d%d", &x, &y, &s);
    }
};

struct Area {
    double minX, maxX, minY, maxY;

    Area(double _minX = 0, double _maxX = 0, double _minY = 0, double _maxY = 0) {
        minX = _minX; maxX = _maxX; minY = _minY; maxY = _maxY;
    }

    // X stands for x + y; Y stands for x - y
    Area(const Person &p, double r) {
        minX = p.x + p.y - p.s * r;
        maxX = p.x + p.y + p.s * r;
        minY = p.x - p.y - p.s * r;
        maxY = p.x - p.y + p.s * r;
    }

    Area join(const Area &a) const {
        return Area(max(minX, a.minX), min(maxX, a.maxX), max(minY, a.minY), min(maxY, a.maxY));
    }

    bool havePoint(void) const {
        return minX <= maxX && minY <= maxY;
    }

    void printPoint(void) const {
        double x = (minX + maxX) / 2, y = (minY + maxY) / 2;
        printf("%.3lf %.3lf\n", (x + y) / 2, (x - y) / 2);
    }
};

const double INF = 1e8;
#define MAX   100100
Person people[MAX];
int numPerson;

void init(void) {
    scanf("%d", &numPerson);
    int k; scanf("%d", &k);
    FOR(i, 1, numPerson) people[i].input();
}

bool ok(double r) {
    Area area(people[1], r);
    FOR(i, 2, numPerson) {
        area = area.join(Area(people[i], r));
        if (!area.havePoint()) return false;
    }
    return area.havePoint();
}

double process(void) {
    double L = 0, R = INF;
    REP(love, 55) {
        double M = (L + R) / 2;
        if (ok(M)) R = M; else L = M;
    }

//    printf("FINAL: %.3lf - %.3lf\n", L, R);
    return (L + R) / 2.0;
}

int main(void) {
    #ifdef THEMIS
    freopen("SIGNAL.INP", "r", stdin);
    freopen("SIGNAL.OUT", "w", stdout);
    #else
    freopen("sample.txt", "r", stdin);
    #endif // THEMIS
    init();
    cout << fixed << setprecision(9) << process() << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/
