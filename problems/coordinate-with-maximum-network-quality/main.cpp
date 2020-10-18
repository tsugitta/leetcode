// https://leetcode.com/problems/coordinate-with-maximum-network-quality/

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
  vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    ld ma = 0;
    tuple<ll, ll> ma_p;

    ll N = towers.size();

    rep(x, 51) rep(y, 51) {
      ld sum = 0;

      rep(i, N) {
        ll tx = towers[i][0];
        ll ty = towers[i][1];
        ld dist = sqrt((tx - x) * (tx - x) + (ty - y) * (ty - y));
        unless(dist <= radius) continue;

        ll q = towers[i][2];
        sum += floor(q / (1 + dist));
      }

      if (chmax(ma, sum)) {
        ma_p = {x, y};
      }
    }

    auto [rx, ry] = ma_p;
    vector<int> res(2);
    res[0] = rx;
    res[1] = ry;

    return res;
  }
};
