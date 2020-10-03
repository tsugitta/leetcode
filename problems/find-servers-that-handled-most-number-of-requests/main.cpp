// https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

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
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    vector<int> cts(k);

    set<int> availables;
    rep(i, k) availables.insert(i);

    asc_pq<tuple<int, int>> to_be_availables;  // (time, server)

    int N = arrival.size();

    rep(i, N) {
      while (to_be_availables.size() &&
             get<0>(to_be_availables.top()) <= arrival[i]) {
        auto [_, id] = to_be_availables.top();
        to_be_availables.pop();
        availables.insert(id);
      }

      if (availables.empty()) continue;

      int want_id = i % k;
      auto it = availables.lower_bound(want_id);
      if (it == availables.end()) it = availables.begin();

      auto id = *it;
      availables.erase(id);
      cts[id]++;
      to_be_availables.emplace(arrival[i] + load[i], id);
    }

    int max_ct = -1;
    vector<int> res;

    rep(i, k) {
      if (cts[i] == max_ct) res.push_back(i);
      if (cts[i] > max_ct) {
        max_ct = cts[i];
        res = vector<int>{(int)i};
      }
    }

    return res;
  }
};
