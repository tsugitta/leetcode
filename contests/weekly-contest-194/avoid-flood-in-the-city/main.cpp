// https://leetcode.com/contest/weekly-contest-194/problems/avoid-flood-in-the-city/

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

class Solution {
 public:
  vector<int> avoidFlood(vector<int>& rains) {
    ll N = rains.size();
    V<int> res(N, -1);

    // Lake number -> day on which it became full
    unordered_map<ll, ll> lake_full_map;
    set<ll> dry_days;

    rep(i, N) {
      if (rains[i] == 0) {
        dry_days.insert(i);
        res[i] = 1;
        continue;
      }

      ll lake = rains[i];

      if (lake_full_map.count(lake)) {
        ll last_full_day = lake_full_map[lake];
        auto it = dry_days.lower_bound(last_full_day);

        if (it == dry_days.end()) {
          return {};
        }

        res[*it] = lake;
        dry_days.erase(it);
      }

      lake_full_map[lake] = i;
    }

    return res;
  }
};
