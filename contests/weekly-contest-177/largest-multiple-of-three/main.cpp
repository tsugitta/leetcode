// https://leetcode.com/contest/weekly-contest-177/problems/largest-multiple-of-three/

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
  string largestMultipleOfThree(vector<int>& digits) {
    V<int> cts(10);
    for (auto d : digits) cts[d]++;

    auto get_res = [&]() {
      string res = "";

      for (int d = 9; d >= 1; d--) {
        res += string(cts[d], '0' + d);
      }

      res += string(res.size() > 0 ? cts[0] : min(cts[0], 1), '0');

      return res;
    };

    auto reduce_ct = [&](ll mod, ll ct) -> bool {
      ll mod_ct = 0;
      rep(i, 10) if (i % 3 == mod) mod_ct += cts[i];
      unless(ct <= mod_ct) return false;

      int to_be_reduced = ct;

      rep(d, 10) {
        unless(d % 3 == mod) continue;
        unless(cts[d]) continue;
        ll can_reduce = min(cts[d], to_be_reduced);
        cts[d] -= can_reduce;
        to_be_reduced -= can_reduce;
        if (to_be_reduced == 0) break;
      }

      return true;
    };

    ll sum = accumulate(all(digits), 0ll);

    if (sum % 3 == 0) {
      return get_res();
    } else if (sum % 3 == 1) {
      if (reduce_ct(1, 1)) return get_res();
      if (reduce_ct(2, 2)) return get_res();
      return "";
    } else if (sum % 3 == 2) {
      if (reduce_ct(2, 1)) return get_res();
      if (reduce_ct(1, 2)) return get_res();
      return "";
    }

    return "";
  };
};
