#include <bits/stdc++.h>

#include <ranges>
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

#ifdef LOCAL
#include "../../debug.h"
#else
#define debug(...) 42
#endif

namespace utils {
template <typename T>
bool chMax(T& target, const T& value) {
    if (value > target) {
        target = value;
        return true;
    }
    return false;
}

template <typename T>
bool chMin(T& target, const T& value) {
    if (value < target) {
        target = value;
        return true;
    }
    return false;
}
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';

vector<bool> send_packet(vector<bool> A);

void send_message(vector<bool> M, vector<bool> C) {
    int S = (int)M.size();
    
    // Idea 1: Communicate C with <= 31 packets
    vector<int> goodPos;
    int badPos = 0;
    for (int i = 0; badPos < 15;) {
        if (goodPos.empty()) {
            if (C[i] == false) {
                send_packet(vector<bool>(31, true));
                goodPos.push_back(i);
            }
            else {
                send_packet(vector<bool>(31, false));
                ++badPos;
            }
            ++i;
        }
        else {
            vector<bool> P(31, false);
            vector<int> newGoodPos;
            for (int j : goodPos) {
                if (C[i] == false) {
                    P[j] = true;
                    newGoodPos.push_back(i);
                }
                else {
                    ++badPos;
                }
                ++i;
                if (i >= 31) break;
            }
            send_packet(P);
            for (int x : newGoodPos) {
                goodPos.push_back(x);
            }
        }
    }

    // Communicate S
    vector<bool> P(31, false);
    for (int i = 0, j = 0; i < 31; ++i) {
        if (C[i] == false) {
            if (S & (1 << j)) {
                P[i] = true;
            }
            ++j;
        }
    } 
    send_packet(P);

    for (int i = 0; i < S;) {
        vector<bool> P(31, false);
        for (int j = 0; j < 31 && i < S; ++j) {
            if (C[j] == false) {
                P[j] = M[i++];
            }
        }
        send_packet(P);
    }
}

vector<bool> receive_message(vector<vector<bool>> R) {
    int N = (int)R.size();

    // Decode C
    vector<bool> C(31, false);
    vector<int> goodPos;
    int badPos = 0;
    int id = 0;
    for (int i = 0; badPos < 15;) {
        if (goodPos.empty()) {
            int cnt = 0;
            for (bool b : R[id]) {
                cnt += b;
            }
            if (cnt >= 16) {
                C[i] = false;
                goodPos.push_back(i);
            }
            else {
                C[i] = true;
                ++badPos;
            }
            ++id;
            ++i;
        }
        else {
            vector<int> newGoodPos;
            for (int j : goodPos) {
                if (R[id][j] == true) {
                    C[i] = false;
                    newGoodPos.push_back(i);
                }
                else {
                    C[i] = true;
                    ++badPos;
                }
                ++i;
                if (i >= 31) break;
            }
            for (int x : newGoodPos) {
                goodPos.push_back(x);
            }
            ++id;
        }
    }

    // Decode S
    const vector<bool>& codeS = R[id];
    int S = 0;
    for (int i = 0, j = 0; i < 31; ++i) {
        if (C[i] == false) {
            if (codeS[i] == true) {
                S += (1 << j);
            }
            ++j;
        }
    }
    ++id;

    vector<bool> res(S, false);
    int k = 0;
    for (int i = id; i < N && k < S; ++i) {
        for (int j = 0; j < 31 && k < S; ++j) {
            if (C[j] == false) {
                res[k++] = R[i][j];
            }
        }
    }
    return res;
}