// https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

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
  int maxProductPath(vector<vector<int>>& grid) {
    int H = grid.size();
    int W = grid[0].size();
    vector<vector<ll>> ma(H, vector<ll>(W, -1e18));
    vector<vector<ll>> mi(H, vector<ll>(W, 1e18));

    ma[0][0] = grid[0][0];
    mi[0][0] = grid[0][0];

    for (int h = 0; h < H; ++h) {
      for (int w = 0; w < W; ++w) {
        vector<vector<int>> dirs{{0, 1}, {1, 0}};

        for (auto d : dirs) {
          int nh = h + d[1];
          int nw = w + d[0];

          if (!(0 <= nh && nh < H && 0 <= nw && nw < W)) continue;

          ma[nh][nw] = max(ma[nh][nw], max(ma[h][w] * grid[nh][nw],
                                           mi[h][w] * grid[nh][nw]));
          mi[nh][nw] = min(mi[nh][nw], min(ma[h][w] * grid[nh][nw],
                                           mi[h][w] * grid[nh][nw]));
        }
      }
    }

    if (ma[H - 1][W - 1] < 0) return -1;
    ll mo = 1e9 + 7;
    return ma[H - 1][W - 1] % mo;
  }
};
