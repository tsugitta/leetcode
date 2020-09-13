// https://leetcode.com/problems/min-cost-to-connect-all-points/

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

class UnionFind {
 public:
  vector<int> data;  // sizeとparを同時に管理する
  UnionFind(int size) : data(size, -1) {}

  int find(int x) { return data[x] < 0 ? x : data[x] = find(data[x]); }

  void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
      if (data[py] < data[px]) swap(px, py);
      data[px] += data[py];
      data[py] = px;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int x) { return -data[find(x)]; }
};

struct Edge {
  int cost, from, to;
  Edge() {}
  Edge(int c, int f, int t) : cost(c), from(f), to(t) {}
  friend bool operator<(const Edge& lhs, const Edge& rhs) {
    return lhs.cost < rhs.cost;
  };
  friend bool operator>(const Edge& lhs, const Edge& rhs) { return rhs < lhs; };
  friend bool operator<=(const Edge& lhs, const Edge& rhs) {
    return !(lhs > rhs);
  };
  friend bool operator>=(const Edge& lhs, const Edge& rhs) {
    return !(lhs < rhs);
  };
};

struct MinimumSpanningTree {
  struct UnionFind uf;
  uint64_t weight;
  MinimumSpanningTree(int V, vector<Edge>& edges) : uf(V), weight(0) {
    sort(edges.begin(), edges.end());
    for (auto e : edges) {
      if (uf.same(e.from, e.to)) continue;
      uf.unite(e.from, e.to);
      weight += e.cost;
    }
  }
};
class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int N = points.size();

    V<Edge> edges;

    rep(j, N) rep(i, j) {
      ll c =
          abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

      edges.emplace_back(c, i, j);
    }

    MinimumSpanningTree mst(N, edges);
    ll res = mst.weight;
    return res;
  }
};
