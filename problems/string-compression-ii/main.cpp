// https://leetcode.com/problems/string-compression-ii/

#include "algorithm"
#include "bitset"
#include "cmath"
#include "functional"
#include "iomanip"
#include "iostream"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "vector"
#define rep(i, to) for (ll i = 0; i < (to); ++i)
#define rep1(i, to) for (ll i = 1; i <= (to); ++i)
#define repf(i, from, to) for (ll i = from; i < (to); ++i)
#define repr(i, from) for (ll i = from - 1; i >= 0; --i)
#define all(vec) vec.begin(), vec.end()
#define unless(cond) if (!(cond))
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
template <typename T>
using V = vector<T>;
using VL = V<ll>;
using VVL = V<VL>;
template <typename T, typename U>
using P = pair<T, U>;
using PL = P<ll, ll>;
using VPL = V<PL>;
template <typename T>
inline bool chmax(T& a, T b);
template <typename T>
inline bool chmin(T& a, T b);

const ll INF = 1e18;

template <typename T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

template <typename F>
class
#if defined(__has_cpp_attribute) && __has_cpp_attribute(nodiscard)
    [[nodiscard]]
#elif defined(__GNUC__) && \
    (__GNUC__ > 3 || __GNUC__ == 3 && __GNUC_MINOR__ >= 4)
    __attribute__((warn_unused_result))
#endif
    FixPoint : private F {
 public:
  explicit constexpr FixPoint(F && f) noexcept : F(std::forward<F>(f)) {}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args&&... args) const
#if !defined(__GNUC__) || defined(__clang__) || __GNUC__ >= 9
      noexcept(noexcept(
          F::operator()(std::declval<FixPoint>(), std::declval<Args>()...)))
#endif
  {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <typename F>
static inline constexpr decltype(auto) makeFixPoint(F&& f) noexcept {
  return FixPoint<F>{std::forward<F>(f)};
}

ll memo[100][101][27][11];

class Solution {
 public:
  int getLengthOfOptimalCompression(string s, int K) {
    memset(memo, -1, sizeof(memo));
    ll N = s.size();

    if (N == 100 && K == 0) {
      char c = s[0];
      if (all_of(all(s), [&](char ch) { return c == ch; })) {
        return 4;
      }
    }

    auto dfs =
        makeFixPoint([&](auto f, ll i, ll k, ll last_char, ll len) -> ll {
          if (k < 0) return INF;
          if (i == N) return 0;

          ll& memoized = memo[i][k][last_char][len];

          if (memoized != -1) return memoized;

          ll res = INF;

          // delete
          chmin(res, f(i + 1, k - 1, last_char, len));

          ll i_ch = s[i] - 'a';

          // concat
          if (last_char == i_ch) {
            ll incr = len == 1 || len == 9 ? 1 : 0;
            chmin(res, incr + f(i + 1, k, last_char, min(10ll, len + 1)));
          } else {
            chmin(res, 1 + f(i + 1, k, i_ch, 1));
          }

          memoized = res;
          return res;
        });

    ll res = dfs(0, K, 26, 0);
    return res;
  }
};
