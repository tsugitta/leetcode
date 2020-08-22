// https://leetcode.com/problems/detect-cycles-in-2d-grid/

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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class Solution {
 public:
  bool containsCycle(vector<vector<char>>& grid) {
    int H = grid.size();
    int W = grid[0].size();

    VV<bool> visited(H, V<bool>(W));

    rep(start_h, H) rep(start_w, W) {
      if (visited[start_h][start_w]) continue;

      queue<P<PL, PL>> q;
      q.emplace(make_pair(start_h, start_w), make_pair(-1, -1));

      while (!q.empty()) {
        auto [cur, prev] = q.front();
        q.pop();

        auto [ch, cw] = cur;
        auto [ph, pw] = prev;

        if (visited[ch][cw]) continue;
        visited[ch][cw] = true;

        for (int i = 0; i < 4; ++i) {
          int nh = ch + dy[i];
          int nw = cw + dx[i];

          unless(0 <= nh && nh < H && 0 <= nw && nw < W) continue;
          unless(grid[nh][nw] == grid[ch][cw]) continue;
          if (nh == ph && nw == pw) continue;

          if (visited[nh][nw]) return true;
          q.emplace(make_pair(nh, nw), make_pair(ch, cw));
        }
      }
    }

    return false;
  }
};
