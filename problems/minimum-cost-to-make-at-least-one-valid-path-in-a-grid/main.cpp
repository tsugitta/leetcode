// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

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

int dirs[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct Pos {
  int x, y;
};

class Solution {
 public:
  int H, W;
  VVL costs;
  V<V<int>> grid;

  int minCost(vector<vector<int>>& _grid) {
    grid = _grid;
    H = grid.size();
    W = grid[0].size();
    costs = VVL(H, VL(W, INF));

    queue<Pos> q;

    dfs(Pos{0, 0}, 0, q);

    while (!q.empty()) {
      Pos n = q.front();
      q.pop();

      for (auto dir : dirs) {
        ll nx = n.x + dir[0];
        ll ny = n.y + dir[1];
        unless(0 <= nx && nx < W && 0 <= ny && ny < H) continue;

        Pos nn = Pos{nx, ny};
        dfs(nn, costs[n.y][n.x] + 1, q);
      }
    }

    return costs[H - 1][W - 1];
  }

  void dfs(Pos st, int curCost, queue<Pos>& q) {
    if (costs[st.y][st.x] <= curCost) return;
    costs[st.y][st.x] = curCost;
    q.push(st);

    int dir = grid[st.y][st.x];

    ll nx = st.x + dirs[dir][0];
    ll ny = st.y + dirs[dir][1];

    unless(0 <= nx && nx < W && 0 <= ny && ny < H) return;

    Pos np = Pos{nx, ny};
    return dfs(np, curCost, q);
  }
};
