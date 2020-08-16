// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

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
using ll = long long;
using ld = long double;
template <typename T>
using V = vector<T>;
using VL = V<ll>;
template <typename T>
using VV = V<V<T>>;
using VVL = VV<ll>;
template <typename T>
using VVV = VV<V<T>>;
template <typename T, typename U>
using P = pair<T, U>;
using PL = P<ll, ll>;
using VPL = V<PL>;
template <typename T>
using asc_pq = priority_queue<T, V<T>, greater<T>>;
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
  int minDays(int n) {
    V<unordered_map<ll, ll>> mp(3);

    auto dfs = [&](auto self, ll num, ll cur, ll used_one) -> ll {
      if (num == 0) return cur;
      if (mp[used_one].count(num)) return mp[used_one][num] + cur;

      ll _res = INF;

      if (used_one <= 1) {
        chmin(_res, self(self, num - 1, cur + 1, used_one + 1));
      }
      if (num % 3 == 0) {
        chmin(_res, self(self, num - 2 * (num / 3), cur + 1, 0));
      }
      if (num % 2 == 0) {
        chmin(_res, self(self, num / 2, cur + 1, 0));
      }

      mp[used_one][num] = _res - cur;
      return _res;
    };

    ll res = dfs(dfs, n, 0, 0);

    return res;
  }
};
