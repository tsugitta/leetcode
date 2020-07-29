// https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

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

class Solution {
 public:
  int countPairs(TreeNode* root, int distance) {
    ll res = 0;

    auto dfs = makeFixPoint([&](auto f, TreeNode* r) -> VL {
      VL leaves;
      if (r == NULL) return leaves;

      VL ls = f(r->left);
      VL rs = f(r->right);

      for (auto l : ls) {
        for (auto r : rs) {
          if (l + r + 2 <= distance) res++;
        }
      }

      if (ls.size() == 0 && rs.size() == 0) {
        leaves.push_back(0);
      }

      for (auto l : ls) leaves.push_back(l + 1);
      for (auto r : rs) leaves.push_back(r + 1);

      return leaves;
    });

    dfs(root);

    return res;
  }
};

class Solution2 {
 public:
  int countPairs(TreeNode* root, int distance) {
    ll res = 0;

    auto dfs = makeFixPoint([&](auto f, TreeNode* r) -> map<ll, ll> {
      map<ll, ll> res_map;
      if (r == NULL) return res_map;

      map<ll, ll> ls = f(r->left);
      map<ll, ll> rs = f(r->right);

      if (ls.size() > 0 && rs.size() > 0) {
        for (auto l_it = ls.begin(); l_it != ls.end(); l_it++) {
          ll l_val = l_it->first;
          ll l_ct = l_it->second;

          for (auto r_it = rs.begin(); r_it != rs.end(); r_it++) {
            ll r_val = r_it->first;
            ll r_ct = r_it->second;

            ll n_d = l_val + r_val + 2;

            if (n_d <= distance) {
              res += l_ct * r_ct;
            } else {
              break;
            }
          }
        }
      }

      if (ls.size() == 0 && rs.size() == 0) {
        res_map[0] = 1;
      }

      for (auto l_it : ls) {
        auto [l_val, l_ct] = l_it;
        res_map[l_val + 1] += l_ct;
      }

      for (auto r_it : rs) {
        auto [r_val, r_ct] = r_it;
        res_map[r_val + 1] += r_ct;
      }

      return res_map;
    });

    dfs(root);

    return res;
  }
};
