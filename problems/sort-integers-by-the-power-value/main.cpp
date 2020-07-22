// https://leetcode.com/problems/sort-integers-by-the-power-value/

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
  unordered_map<ll, int> memo;

  int get_value(ll num) {
    if (memo.count(num)) return memo[num];

    if (num == 1) return 0;

    ll value = 1 + (num % 2 == 0 ? get_value(num / 2) : get_value(3 * num + 1));
    memo[num] = value;

    return value;
  }

  int getKth(int lo, int hi, int k) {
    memo = unordered_map<ll, int>();

    rep1(num, 1000) { get_value(num); }

    VPL arr(0);
    repf(num, lo, hi + 1) arr.emplace_back(memo[num], num);

    sort(all(arr));

    return arr[k - 1].se;
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
