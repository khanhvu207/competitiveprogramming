#include <bits/stdc++.h>

#include <ranges>
using namespace std;

#ifdef LOCAL
#include "../../debug.h"
#else
#define debug(...) 42
#endif

namespace utils {
template <typename T, typename... Args>
void setValues(const T& value, T& first, Args&... args) {
    first = value;
    if constexpr (sizeof...(args) > 0) {
        setValues(value, args...);
    }
}

template <typename T>
void setMax(T& target, const T& value) {
    if (value > target) {
        target = value;
    }
}

template <typename T>
void setMin(T& target, const T& value) {
    if (value < target) {
        target = value;
    }
}
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';
const bool is_multitest = false;


void solve() {
    ll totalScore = 0;
    vector<vector<ll>> a(3, vector<ll>(3));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
            totalScore += a[i][j];
        }
    }

    function<bool(vector<int>)> checkWinning = [](const vector<int>& playerMoves) {
        bool isWinning = false;
        for (int i = 0; i < 3; ++i) {
            bool straight = true;
            straight &= (playerMoves[0] >> i) & 1;
            straight &= (playerMoves[1] >> i) & 1;
            straight &= (playerMoves[2] >> i) & 1;
            isWinning |= straight;
            isWinning |= playerMoves[i] == 7;
        }

        bool mainDiag = true;
        mainDiag &= (playerMoves[0] >> 2) & 1;
        mainDiag &= (playerMoves[1] >> 1) & 1;
        mainDiag &= (playerMoves[2] >> 0) & 1;
        isWinning |= mainDiag;

        bool offDiag = true;
        offDiag &= (playerMoves[0] >> 0) & 1;
        offDiag &= (playerMoves[1] >> 1) & 1;
        offDiag &= (playerMoves[2] >> 2) & 1;
        isWinning |= offDiag;

        return isWinning;
    };

    const ll INF = numeric_limits<ll>::max();
    vector<int> takaMoves(3);
    vector<int> aokiMoves(3);

    function<ll(int)> solve = [&](int turn) {
        if (turn == 9) {
            if (checkWinning(takaMoves)) return INF;
            else {
                ll takaScore = 0;
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if ((takaMoves[i] >> j) & 1) {
                            takaScore += a[i][2-j];
                        }
                    }
                }
                return takaScore;
            }
        }

        // Maximize when it's Takahashi's turn, and minimize otherwise
        bool isMinimize = turn & 1;
        ll optimalScore = isMinimize ? INF : -INF;
        vector<int>& curPlayer = (turn & 1) ? aokiMoves : takaMoves;
        vector<int>& otherPlayer = (turn & 1) ? takaMoves : aokiMoves;

        if (checkWinning(otherPlayer)) {
            return optimalScore;
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (!((curPlayer[i] >> j) & 1) && !((otherPlayer[i] >> j) & 1)) {
                    curPlayer[i] ^= (1 << j);

                    if (isMinimize) {
                        setMin(optimalScore, solve(turn + 1));
                    }
                    else {
                        setMax(optimalScore, solve(turn + 1));
                    }

                    curPlayer[i] ^= (1 << j);
                }
            }
        }
        return optimalScore;
    };

    ll takaScore = solve(0);
    cout << (takaScore * 2LL > totalScore ? "Takahashi" : "Aoki") << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
