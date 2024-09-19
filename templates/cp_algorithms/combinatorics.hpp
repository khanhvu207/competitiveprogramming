// https://cp-algorithms.github.io/cp-algorithms-aux/cp-algo/math/combinatorics.hpp

#include <cassert>
#include <cstdint>
#include <functional>

namespace cp_algo::math {
#ifdef CP_ALGO_MAXN
const int maxn = CP_ALGO_MAXN;
#else
const int maxn = 1 << 19;
#endif
const int magic = 64;  // threshold for sizes to run the naive algo

auto bpow(auto const& x, int64_t n, auto const& one, auto op) {
    if (n == 0) {
        return one;
    } else {
        auto t = bpow(x, n / 2, one, op);
        t = op(t, t);
        if (n % 2) {
            t = op(t, x);
        }
        return t;
    }
}
auto bpow(auto x, int64_t n, auto ans) { return bpow(x, n, ans, std::multiplies{}); }
template <typename T>
T bpow(T const& x, int64_t n) {
    return bpow(x, n, T(1));
}
}  // namespace cp_algo::math

namespace cp_algo::math {
// fact/rfact/small_inv are caching
// Beware of usage with dynamic mod
template <typename T>
T fact(int n) {
    static std::vector<T> F(maxn);
    static bool init = false;
    if (!init) {
        F[0] = T(1);
        for (int i = 1; i < maxn; i++) {
            F[i] = F[i - 1] * T(i);
        }
        init = true;
    }
    return F[n];
}
// Only works for modint types
template <typename T>
T rfact(int n) {
    static std::vector<T> F(maxn);
    static bool init = false;
    if (!init) {
        int t = std::min<int64_t>(T::mod(), maxn) - 1;
        F[t] = T(1) / fact<T>(t);
        for (int i = t - 1; i >= 0; i--) {
            F[i] = F[i + 1] * T(i + 1);
        }
        init = true;
    }
    return F[n];
}
template <typename T>
T small_inv(int n) {
    static std::vector<T> F(maxn);
    static bool init = false;
    if (!init) {
        for (int i = 1; i < maxn; i++) {
            F[i] = rfact<T>(i) * fact<T>(i - 1);
        }
        init = true;
    }
    return F[n];
}
template <typename T>
T binom_large(T n, int r) {
    assert(r < maxn);
    T ans = 1;
    for (int i = 0; i < r; i++) {
        ans = ans * T(n - i) * small_inv<T>(i + 1);
    }
    return ans;
}
template <typename T>
T binom(int n, int r) {
    if (r < 0 || r > n) {
        return T(0);
    } else if (n >= maxn) {
        return binom_large(T(n), r);
    } else {
        return fact<T>(n) * rfact<T>(r) * rfact<T>(n - r);
    }
}
}  // namespace cp_algo::math