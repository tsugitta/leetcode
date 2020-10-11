// https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/

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
  vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
    V<int> res(n - 1);

    VV<int> edge_list(n, V<int>());

    for (auto& e : edges) {
      int u = e[0];
      int v = e[1];
      --u, --v;
      edge_list[u].push_back(v);
      edge_list[v].push_back(u);
    }

    rep(bit, 1 << n) {
      int node_ct = __builtin_popcountll(bit);
      if (node_ct <= 1) continue;

      auto is_included = [&](int u) -> bool { return bit & (1 << u); };

      int root = 0;
      while (!is_included(root)) root++;

      auto is_tree = [&]() -> bool {
        int ct = 0;

        auto dfs = [&](auto self, int u, int p) -> void {
          ++ct;

          for (auto v : edge_list[u]) {
            if (v == p || !is_included(v)) continue;
            self(self, v, u);
          }
        };

        dfs(dfs, root, -1);
        return ct == node_ct;
      };

      if (!is_tree()) continue;

      auto get_most_farthest =
          [&](int from_id) -> P<int, int> {  // (id, distance)
        int max_dist = 0;
        int max_dist_id = -1;

        auto dfs = [&](auto self, int u, int p, int dist) -> void {
          if (chmax(max_dist, dist)) {
            max_dist_id = u;
          }

          for (auto v : edge_list[u]) {
            if (v == p || !is_included(v)) continue;
            self(self, v, u, dist + 1);
          }
        };

        dfs(dfs, from_id, -1, 0);

        return {max_dist_id, max_dist};
      };

      auto [farthest_id, tmp] = get_most_farthest(root);
      auto [tmp2, dist] = get_most_farthest(farthest_id);

      res[dist - 1]++;
    }

    return res;
  }
};
