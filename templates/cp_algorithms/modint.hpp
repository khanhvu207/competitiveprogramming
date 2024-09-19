// https://cp-algorithms.github.io/cp-algorithms-aux/cp-algo/math/modint.hpp

#include <cstdint>
#include <functional>
#include <iostream>

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
template <typename modint>
struct modint_base {
    static int64_t mod() { return modint::mod(); }
    modint_base() : r(0) {}
    modint_base(int64_t rr) : r(rr % mod()) { r = std::min(r, r + mod()); }
    modint inv() const { return bpow(to_modint(), mod() - 2); }
    modint operator-() const { return std::min(-r, mod() - r); }
    modint& operator/=(const modint& t) { return to_modint() *= t.inv(); }
    modint& operator*=(const modint& t) {
        if (mod() <= uint32_t(-1)) {
            r = r * t.r % mod();
        } else {
            r = __int128(r) * t.r % mod();
        }
        return to_modint();
    }
    modint& operator+=(const modint& t) {
        r += t.r;
        r = std::min(r, r - mod());
        return to_modint();
    }
    modint& operator-=(const modint& t) {
        r -= t.r;
        r = std::min(r, r + mod());
        return to_modint();
    }
    modint operator+(const modint& t) const { return modint(to_modint()) += t; }
    modint operator-(const modint& t) const { return modint(to_modint()) -= t; }
    modint operator*(const modint& t) const { return modint(to_modint()) *= t; }
    modint operator/(const modint& t) const { return modint(to_modint()) /= t; }
    auto operator<=>(const modint_base& t) const = default;
    int64_t rem() const { return 2 * r > (uint64_t)mod() ? r - mod() : r; }

    // Only use if you really know what you're doing!
    uint64_t modmod() const { return 8ULL * mod() * mod(); };
    void add_unsafe(uint64_t t) { r += t; }
    void pseudonormalize() { r = std::min(r, r - modmod()); }
    modint const& normalize() {
        if (r >= (uint64_t)mod()) {
            r %= mod();
        }
        return to_modint();
    }
    uint64_t& setr() { return r; }
    uint64_t getr() const { return r; }

   private:
    uint64_t r;
    modint& to_modint() { return static_cast<modint&>(*this); }
    modint const& to_modint() const { return static_cast<modint const&>(*this); }
};
template <typename modint>
std::istream& operator>>(std::istream& in, modint_base<modint>& x) {
    return in >> x.setr();
}
template <typename modint>
std::ostream& operator<<(std::ostream& out, modint_base<modint> const& x) {
    return out << x.getr();
}

template <typename modint>
concept modint_type = std::is_base_of_v<modint_base<modint>, modint>;

template <int64_t m>
struct modint : modint_base<modint<m>> {
    static constexpr int64_t mod() { return m; }
    using Base = modint_base<modint<m>>;
    using Base::Base;
};

struct dynamic_modint : modint_base<dynamic_modint> {
    static int64_t mod() { return m; }
    static void switch_mod(int64_t nm) { m = nm; }
    using Base = modint_base<dynamic_modint>;
    using Base::Base;

    // Wrapper for temp switching
    auto static with_mod(int64_t tmp, auto callback) {
        struct scoped {
            int64_t prev = mod();
            ~scoped() { switch_mod(prev); }
        } _;
        switch_mod(tmp);
        return callback();
    }

   private:
    static int64_t m;
};
int64_t dynamic_modint::m = 0;
}  // namespace cp_algo::math