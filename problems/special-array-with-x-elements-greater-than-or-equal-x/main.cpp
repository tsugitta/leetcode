// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

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
  int specialArray(vector<int>& nums) {
    int N = nums.size();
    sort(all(nums));

    if (nums.back() == 0) return -1;

    int ok = 1;
    int ng = N + 1;

    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;

      auto it = lower_bound(all(nums), mid);
      int less = it - nums.begin();
      int non_less = N - less;
      if (non_less >= mid) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    {
      auto it = lower_bound(all(nums), ok);
      int less = it - nums.begin();
      int non_less = N - less;

      if (non_less != ok) return -1;
    }

    return ok;
  }
};
