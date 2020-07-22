// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

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

class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    VL mod_cts(k);

    auto get_mod = [](ll a, ll b) {
      if (a > 0) return a % b;

      ll na = a + (abs(floor(a / b)) + 1) * b;
      return na % b;
    };

    for (ll v : arr) {
      ++mod_cts[get_mod(v, k)];
    }

    if (mod_cts[0] % 2 == 1) {
      return false;
    }

    rep1(mod, k - 1) {
      ll pair = k - mod;
      if (mod_cts[mod] != mod_cts[pair]) {
        return false;
      }
    }

    return true;
  }
};
