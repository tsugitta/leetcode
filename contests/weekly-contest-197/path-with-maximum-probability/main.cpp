// https://leetcode.com/contest/weekly-contest-197/problems/path-with-maximum-probability/

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
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start, int end) {
    ll N = n;
    V<V<P<ll, ld>>> edge_list(N, V<P<ll, ld>>());

    rep(i, edges.size()) {
      auto edge = edges[i];
      ll u = edge[0];
      ll v = edge[1];
      ld prob = succProb[i];

      if (prob == 0) continue;

      // log を取ってマイナスをかけたものをコストとするとコストの和を最小化する
      // 問題に帰着でき、ダイクストラで解ける
      ld log_prob = -log(prob);
      edge_list[u].emplace_back(v, log_prob);
      edge_list[v].emplace_back(u, log_prob);
    }

    const ld INF = 1e18;

    V<ld> dists(N, INF);

    priority_queue<P<ld, ll>, V<P<ld, ll>>, greater<P<ld, ll>>> q;
    q.push({0, start});

    while (!q.empty()) {
      auto p = q.top();
      q.pop();

      ld cost = p.fi;
      ll u = p.se;

      if (cost > dists[u]) continue;

      for (auto vp : edge_list[u]) {
        ll v = vp.fi;
        ld nc = vp.se;

        ld n_cost = cost + nc;
        if (chmin(dists[v], n_cost)) {
          q.emplace(n_cost, v);
        }
      }
    }

    if (dists[end] == INF) return 0;

    ld res = exp(-dists[end]);
    return res;
  }
};
