// https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/

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
  int connectTwoGroups(vector<vector<int>>& cost) {
    ll N1 = cost.size();
    ll N2 = cost[0].size();

    VL min_cost_from_two(N2, INF);

    rep(i1, N1) rep(i2, N2) chmin(min_cost_from_two[i2], (ll)cost[i1][i2]);

    VL dp(1 << N2, INF);
    dp[0] = 0;

    rep(i1, N1) {
      VL ndp(1 << N2, INF);

      rep(bit, 1 << N2) {
        rep(i2, N2) chmin(ndp[bit | (1 << i2)], dp[bit] + cost[i1][i2]);
      }

      swap(dp, ndp);
    }

    ll res = INF;

    rep(bit, 1 << N2) {
      ll r = dp[bit];

      rep(i2, N2) {
        if ((bit & (1 << i2)) == 0) {
          r += min_cost_from_two[i2];
        }
      }

      chmin(res, r);
    }

    return res;
  }
};
