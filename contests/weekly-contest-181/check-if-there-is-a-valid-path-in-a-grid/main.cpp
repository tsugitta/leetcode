// https://leetcode.com/contest/weekly-contest-181/problems/check-if-there-is-a-valid-path-in-a-grid/

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

struct Point {
  ll y, x;
};

V<V<Point>> type_to_dirs = {
    {{0, -1}, {0, 1}}, {{1, 0}, {-1, 0}},  {{1, 0}, {0, -1}},
    {{1, 0}, {0, 1}},  {{-1, 0}, {0, -1}}, {{-1, 0}, {0, 1}},
};

class Solution {
 public:
  bool hasValidPath(vector<vector<int>>& grid) {
    ll H = grid.size();
    ll W = grid[0].size();

    V<V<bool>> visited(H, V<bool>(W, 0));
    visited[0][0] = true;

    queue<Point> q;
    q.push({0, 0});

    while (!q.empty()) {
      Point p = q.front();
      q.pop();

      for (auto dir : type_to_dirs[grid[p.y][p.x] - 1]) {
        Point np = {p.y + dir.y, p.x + dir.x};
        unless(0 <= np.x && np.x < W && 0 <= np.y && np.y < H) continue;
        if (visited[np.y][np.x]) continue;

        for (auto ndir : type_to_dirs[grid[np.y][np.x] - 1]) {
          Point nnp = {np.y + ndir.y, np.x + ndir.x};

          if (p.x == nnp.x && p.y == nnp.y) {
            visited[np.y][np.x] = true;
            q.push(np);
          }
        }
      }
    }

    return visited[H - 1][W - 1];
  }
};

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
