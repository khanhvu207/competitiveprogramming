#include <bits/stdc++.h>

#include <ranges>
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

#ifdef LOCAL
#include "../debug.h"
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

namespace cp_algo::random {
uint64_t rng() {
    static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    return rng();
}
}  // namespace cp_algo::random

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

namespace cp_algo::linalg {
template <class vec, typename base>
struct valarray_base : std::valarray<base> {
    using Base = std::valarray<base>;
    using Base::Base;

    valarray_base(base const& t) : Base(t, 1) {}

    auto begin() { return std::begin(to_valarray()); }
    auto begin() const { return std::begin(to_valarray()); }
    auto end() { return std::end(to_valarray()); }
    auto end() const { return std::end(to_valarray()); }

    bool operator==(vec const& t) const { return std::ranges::equal(*this, t); }
    bool operator!=(vec const& t) const { return !(*this == t); }

    vec operator-() const { return Base::operator-(); }

    static vec from_range(auto const& R) {
        vec res(std::ranges::distance(R));
        std::ranges::copy(R, res.begin());
        return res;
    }
    Base& to_valarray() { return static_cast<Base&>(*this); }
    Base const& to_valarray() const { return static_cast<Base const&>(*this); }
};

template <class vec, typename base>
vec operator+(valarray_base<vec, base> const& a, valarray_base<vec, base> const& b) {
    return a.to_valarray() + b.to_valarray();
}
template <class vec, typename base>
vec operator-(valarray_base<vec, base> const& a, valarray_base<vec, base> const& b) {
    return a.to_valarray() - b.to_valarray();
}

template <class vec, typename base>
struct vec_base : valarray_base<vec, base> {
    using Base = valarray_base<vec, base>;
    using Base::Base;

    static vec ei(size_t n, size_t i) {
        vec res(n);
        res[i] = 1;
        return res;
    }

    virtual void add_scaled(vec const& b, base scale, size_t i = 0) {
        if (scale != base(0)) {
            for (; i < size(*this); i++) {
                (*this)[i] += scale * b[i];
            }
        }
    }
    virtual vec const& normalize() { return static_cast<vec&>(*this); }
    virtual base normalize(size_t i) { return (*this)[i]; }
    void read() {
        for (auto& it : *this) {
            std::cin >> it;
        }
    }
    void print() const {
        std::ranges::copy(*this, std::ostream_iterator<base>(std::cout, " "));
        std::cout << "\n";
    }
    static vec random(size_t n) {
        vec res(n);
        std::ranges::generate(res, random::rng);
        return res;
    }
    // Concatenate vectors
    vec operator|(vec const& t) const {
        vec res(size(*this) + size(t));
        res[std::slice(0, size(*this), 1)] = *this;
        res[std::slice(size(*this), size(t), 1)] = t;
        return res;
    }

    // Generally, vec shouldn't be modified
    // after its pivot index is set
    std::pair<size_t, base> find_pivot() {
        if (pivot == size_t(-1)) {
            pivot = 0;
            while (pivot < size(*this) && normalize(pivot) == base(0)) {
                pivot++;
            }
            if (pivot < size(*this)) {
                pivot_inv = base(1) / (*this)[pivot];
            }
        }
        return {pivot, pivot_inv};
    }
    void reduce_by(vec& t) {
        auto [pivot, pinv] = t.find_pivot();
        if (pivot < size(*this)) {
            add_scaled(t, -normalize(pivot) * pinv, pivot);
        }
    }

   private:
    size_t pivot = -1;
    base pivot_inv;
};

template <typename base>
struct vec : vec_base<vec<base>, base> {
    using Base = vec_base<vec<base>, base>;
    using Base::Base;
};

template <math::modint_type base>
struct vec<base> : vec_base<vec<base>, base> {
    using Base = vec_base<vec<base>, base>;
    using Base::Base;

    void add_scaled(vec const& b, base scale, size_t i = 0) override {
        if (scale != base(0)) {
            for (; i < size(*this); i++) {
                (*this)[i].add_unsafe(scale.getr() * b[i].getr());
            }
            if (++counter == 8) {
                for (auto& it : *this) {
                    it.pseudonormalize();
                }
                counter = 0;
            }
        }
    }
    vec const& normalize() override {
        for (auto& it : *this) {
            it.normalize();
        }
        return *this;
    }
    base normalize(size_t i) override { return (*this)[i].normalize(); }

   private:
    size_t counter = 0;
};
}  // namespace cp_algo::linalg

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

namespace cp_algo::linalg {
enum gauss_mode { normal, reverse };
template <typename base_t>
struct matrix : valarray_base<matrix<base_t>, vec<base_t>> {
    using base = base_t;
    using Base = valarray_base<matrix<base>, vec<base>>;
    using Base::Base;

    matrix(size_t n) : Base(vec<base>(n), n) {}
    matrix(size_t n, size_t m) : Base(vec<base>(m), n) {}

    size_t n() const { return size(*this); }
    size_t m() const { return n() ? size(row(0)) : 0; }
    auto dim() const { return std::array{n(), m()}; }

    auto& row(size_t i) { return (*this)[i]; }
    auto const& row(size_t i) const { return (*this)[i]; }

    matrix& operator*=(base t) {
        for (auto& it : *this) it *= t;
        return *this;
    }
    matrix operator*(base t) const { return matrix(*this) *= t; }

    // Make sure the result is matrix, not Base
    matrix& operator*=(matrix const& t) { return *this = *this * t; }

    void read() {
        for (auto& it : *this) {
            it.read();
        }
    }
    void print() const {
        for (auto const& it : *this) {
            it.print();
        }
    }

    static matrix block_diagonal(std::vector<matrix> const& blocks) {
        size_t n = 0;
        for (auto& it : blocks) {
            assert(it.n() == it.m());
            n += it.n();
        }
        matrix res(n);
        n = 0;
        for (auto& it : blocks) {
            for (size_t i = 0; i < it.n(); i++) {
                res[n + i][std::slice(n, it.n(), 1)] = it[i];
            }
            n += it.n();
        }
        return res;
    }
    static matrix random(size_t n, size_t m) {
        matrix res(n, m);
        std::ranges::generate(res, std::bind(vec<base>::random, m));
        return res;
    }
    static matrix random(size_t n) { return random(n, n); }
    static matrix eye(size_t n) {
        matrix res(n);
        for (size_t i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        return res;
    }

    // Concatenate matrices
    matrix operator|(matrix const& b) const {
        assert(n() == b.n());
        matrix res(n(), m() + b.m());
        for (size_t i = 0; i < n(); i++) {
            res[i] = row(i) | b[i];
        }
        return res;
    }
    matrix submatrix(auto slicex, auto slicey) const {
        matrix res = (*this)[slicex];
        for (auto& row : res) {
            row = vec<base>(row[slicey]);
        }
        return res;
    }

    matrix T() const {
        matrix res(m(), n());
        for (size_t i = 0; i < n(); i++) {
            for (size_t j = 0; j < m(); j++) {
                res[j][i] = row(i)[j];
            }
        }
        return res;
    }

    matrix operator*(matrix const& b) const {
        assert(m() == b.n());
        matrix res(n(), b.m());
        for (size_t i = 0; i < n(); i++) {
            for (size_t j = 0; j < m(); j++) {
                res[i].add_scaled(b[j], row(i)[j]);
            }
        }
        return res.normalize();
    }

    vec<base> apply(vec<base> const& x) const { return (matrix(x) * *this)[0]; }

    matrix pow(uint64_t k) const {
        assert(n() == m());
        return bpow(*this, k, eye(n()));
    }

    matrix& normalize() {
        for (auto& it : *this) {
            it.normalize();
        }
        return *this;
    }
    template <gauss_mode mode = normal>
    void eliminate(size_t i, size_t k) {
        auto kinv = base(1) / row(i).normalize()[k];
        for (size_t j = (mode == normal) * i; j < n(); j++) {
            if (j != i) {
                row(j).add_scaled(row(i), -row(j).normalize(k) * kinv);
            }
        }
    }
    template <gauss_mode mode = normal>
    void eliminate(size_t i) {
        row(i).normalize();
        for (size_t j = (mode == normal) * i; j < n(); j++) {
            if (j != i) {
                row(j).reduce_by(row(i));
            }
        }
    }
    template <gauss_mode mode = normal>
    matrix& gauss() {
        for (size_t i = 0; i < n(); i++) {
            eliminate<mode>(i);
        }
        return normalize();
    }
    template <gauss_mode mode = normal>
    auto echelonize(size_t lim) {
        return gauss<mode>().sort_classify(lim);
    }
    template <gauss_mode mode = normal>
    auto echelonize() {
        return echelonize<mode>(m());
    }

    size_t rank() const {
        if (n() > m()) {
            return T().rank();
        }
        return size(matrix(*this).echelonize()[0]);
    }

    base det() const {
        assert(n() == m());
        matrix b = *this;
        b.echelonize();
        base res = 1;
        for (size_t i = 0; i < n(); i++) {
            res *= b[i][i];
        }
        return res;
    }

    std::optional<matrix> inv() const {
        assert(n() == m());
        matrix b = *this | eye(n());
        if (size(b.echelonize<reverse>(n())[0]) < n()) {
            return std::nullopt;
        }
        for (size_t i = 0; i < n(); i++) {
            b[i] *= base(1) / b[i][i];
        }
        return b.submatrix(std::slice(0, n(), 1), std::slice(n(), n(), 1));
    }

    // Can also just run gauss on T() | eye(m)
    // but it would be slower :(
    auto kernel() const {
        auto A = *this;
        auto [pivots, free] = A.template echelonize<reverse>();
        matrix sols(size(free), m());
        for (size_t j = 0; j < size(pivots); j++) {
            base scale = base(1) / A[j][pivots[j]];
            for (size_t i = 0; i < size(free); i++) {
                sols[i][pivots[j]] = A[j][free[i]] * scale;
            }
        }
        for (size_t i = 0; i < size(free); i++) {
            sols[i][free[i]] = -1;
        }
        return sols;
    }

    // [solution, basis], transposed
    std::optional<std::array<matrix, 2>> solve(matrix t) const {
        matrix sols = (*this | t).kernel();
        if (sols.n() < t.m() ||
            sols.submatrix(std::slice(sols.n() - t.m(), t.m(), 1), std::slice(m(), t.m(), 1)) != -eye(t.m())) {
            return std::nullopt;
        } else {
            return std::array{sols.submatrix(std::slice(sols.n() - t.m(), t.m(), 1), std::slice(0, m(), 1)),
                              sols.submatrix(std::slice(0, sols.n() - t.m(), 1), std::slice(0, m(), 1))};
        }
    }

   private:
    // To be called after a gaussian elimination run
    // Sorts rows by pivots and classifies
    // variables into pivots and free
    auto sort_classify(size_t lim) {
        size_t rk = 0;
        std::vector<size_t> free, pivots;
        for (size_t j = 0; j < lim; j++) {
            for (size_t i = rk + 1; i < n() && row(rk)[j] == base(0); i++) {
                if (row(i)[j] != base(0)) {
                    std::swap(row(i), row(rk));
                    row(rk) = -row(rk);
                }
            }
            if (rk < n() && row(rk)[j] != base(0)) {
                pivots.push_back(j);
                rk++;
            } else {
                free.push_back(j);
            }
        }
        return std::array{pivots, free};
    }
};
}  // namespace cp_algo::linalg

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

using namespace cp_algo::math;
using namespace cp_algo::linalg;
const int MOD = 1e9 + 7;
using base = modint<MOD>;

void solve() {
    int n, k;
    while (cin >> n >> k) {
        matrix<base> m(k + 2, k + 2);
        for (int i = 0; i < k + 2; ++i) {
            auto& row = m.row(i);
            row[0] = base(1);
            if (i < 1) continue;
            for (int j = 1; j < i + 1; ++j) {
                row[j] = binom<base>(i - 1, j - 1);
            }
            // row.print();
        }
        m = m.pow(n - 1);
        // m.print();
        base res = 0;
        for (int i = 0; i < k + 2; ++i) {
            const auto& row = m.row(k + 1);
            res += row[i];
        }
        cout << res << el;
    }
}

const bool is_multitest = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
