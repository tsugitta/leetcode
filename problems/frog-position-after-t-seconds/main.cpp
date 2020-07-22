// https://leetcode.com/problems/frog-position-after-t-seconds/

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

class Solution {
 public:
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    V<V<int>> edgeList = V<V<int>>(n, V<int>(0));

    for (auto e : edges) {
      edgeList[e[0] - 1].emplace_back(e[1] - 1);
      edgeList[e[1] - 1].emplace_back(e[0] - 1);
    }

    queue<int> q;
    q.push(0);

    V<bool> visited(n);
    visited[0] = true;

    V<double> probs(n);
    probs[0] = 1;

    V<int> steps(n);
    steps[0] = 0;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      int child_ct = u == 0 ? edgeList[u].size() : edgeList[u].size() - 1;

      for (auto v : edgeList[u]) {
        if (visited[v]) continue;

        visited[v] = true;
        probs[v] = probs[u] / child_ct;
        steps[v] = steps[u] + 1;
        q.push(v);
      }
    }

    --target;
    if (steps[target] > t) {
      return 0;
    } else if (steps[target] == t) {
      return probs[target];
    } else {
      int child_ct =
          target == 0 ? edgeList[target].size() : edgeList[target].size() - 1;
      return child_ct == 0 ? probs[target] : 0;
    }
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
