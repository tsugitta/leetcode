// https://leetcode.com/contest/weekly-contest-180/problems/maximum-performance-of-a-team/

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

struct Emp {
  ll speed;
  ll efficiency;
};

const ll MOD = 1e9 + 7;

class Solution {
 public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                     int k) {
    V<Emp> es(n);

    rep(i, n) es[i] = {speed[i], efficiency[i]};

    sort(all(es), [](Emp a, Emp b) { return a.efficiency >= b.efficiency; });

    ll res = 0;
    ll sum_s = 0;
    ll min_e = INF;

    priority_queue<ll, VL, greater<ll>> min_speed_pq;

    rep(i, k) {
      sum_s += es[i].speed;
      min_e = es[i].efficiency;
      min_speed_pq.push(es[i].speed);
      chmax(res, sum_s * min_e);
    }

    repf(i, k, n) {
      unless(es[i].speed > min_speed_pq.top()) continue;

      ll to_be_removed = min_speed_pq.top();
      sum_s -= to_be_removed;
      min_speed_pq.pop();

      min_speed_pq.push(es[i].speed);
      sum_s += es[i].speed;
      min_e = es[i].efficiency;

      chmax(res, sum_s * min_e);
    }

    return res % MOD;
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
