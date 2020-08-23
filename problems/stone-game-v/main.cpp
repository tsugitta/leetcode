// https://leetcode.com/problems/stone-game-v/

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
  int stoneGameV(vector<int>& stoneValue) {
    int N = stoneValue.size();
    V<int> acc(N + 1);

    VV<int> dp(N + 1, V<int>(N + 1, -1));

    rep(i, N) acc[i + 1] = acc[i] + stoneValue[i];

    auto dfs = [&](auto self, int l, int r) -> int {
      if (r - l <= 1) return 0;
      if (r - l == 2) {
        int res = min(stoneValue[l], stoneValue[l + 1]);
        return res;
      }

      if (dp[l][r] != -1) return dp[l][r];

      int part = 0;

      for (int sep_r = l + 1; sep_r < r; sep_r++) {
        int ls = acc[sep_r] - acc[l];
        int rs = acc[r] - acc[sep_r];

        if (ls <= rs) {
          int next = self(self, l, sep_r, 0);
          chmax(part, next + ls);
        }

        if (ls >= rs) {
          int next = self(self, sep_r, r, 0);
          chmax(part, next + rs);
        }
      }

      dp[l][r] = part;
      return part;
    };

    return dfs(dfs, 0, N);
  }
};
