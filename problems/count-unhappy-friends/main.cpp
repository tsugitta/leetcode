// https://leetcode.com/problems/count-unhappy-friends/

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
  int unhappyFriends(int n, vector<vector<int>>& preferences,
                     vector<vector<int>>& pairs) {
    V<unordered_map<ll, ll>> to_distance(n);

    rep(i, n) rep(j, preferences[i].size()) {
      to_distance[i][preferences[i][j]] = j;
    }

    VL dist(n);

    for (auto& p : pairs) {
      dist[p[0]] = to_distance[p[0]][p[1]];
      dist[p[1]] = to_distance[p[1]][p[0]];
    }

    ll res = 0;

    rep(i, n) {
      rep(d, dist[i]) {
        ll j = preferences[i][d];

        rep(d1, dist[j]) {
          if (i == preferences[j][d1]) {
            ++res;
            d = d1 = n;
          }
        }
      }
    }

    return res;
  }
};
