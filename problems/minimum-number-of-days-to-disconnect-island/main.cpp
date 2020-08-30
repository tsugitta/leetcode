// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

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

struct UnionFind {
  vector<ll> parents;

  UnionFind(ll n) : parents(vector<ll>(n, -1)) {}

  ll root(ll a) {
    if (parents[a] < 0) {
      return a;
    }

    auto r = root(parents[a]);
    parents[a] = r;
    return r;
  }

  bool same(ll a, ll b) { return root(a) == root(b); }

  void merge(ll a, ll b) {
    ll ar = root(a);
    ll br = root(b);

    if (ar == br) {
      return;
    }

    // make less index one as a root
    if (ar > br) {
      swap(ar, br);
    }

    parents[ar] += parents[br];
    parents[br] = ar;
  }

  ll size(ll a) { return -parents[root(a)]; }

  ll group_count() {
    ll res = 0;

    for (auto s : parents) {
      if (s < 0) {
        res++;
      }
    }

    return res;
  }
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

class Solution {
 public:
  int minDays(vector<vector<int>>& grid) {
    int H = grid.size();
    int W = grid[0].size();

    auto is_connected = [&]() {
      int N = H * W;
      UnionFind uf(N);

      rep(h, H) rep(w, W) {
        unless(grid[h][w]) continue;

        rep(i, 4) {
          int nh = h + dy[i];
          int nw = w + dx[i];

          unless(0 <= nw && nw < W) continue;
          unless(0 <= nh && nh < H) continue;
          unless(grid[nh][nw]) continue;

          uf.merge(h + w * H, nh + nw * H);
        }
      }

      set<int> parents;

      rep(h, H) rep(w, W) {
        unless(grid[h][w]) continue;

        int id = h + w * H;
        int r = uf.root(id);

        parents.insert(r);
      }

      return parents.size() == 1;
    };

    if (!is_connected()) return 0;

    rep(h, H) rep(w, W) {
      unless(grid[h][w]) continue;

      grid[h][w] = 0;

      if (!is_connected()) return 1;

      grid[h][w] = 1;
    }

    return 2;
  }
};
