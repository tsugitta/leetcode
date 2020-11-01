// https://leetcode.com/problems/count-substrings-that-differ-by-one-character/

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
#define repr1(i, from) for (ll i = from; i >= 1; --i)
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
  int countSubstrings(string s, string t) {
    int SN = s.size();
    int TN = t.size();

    vector dp_end(SN + 1, vector<int>(TN + 1, 0));    // 1-indexed
    vector dp_begin(SN + 1, vector<int>(TN + 1, 0));  // 0-indexed

    rep1(si, SN) rep1(ti, TN) {
      if (s[si - 1] == t[ti - 1]) {
        dp_end[si][ti] = 1 + dp_end[si - 1][ti - 1];
      }
    }

    repr1(si, SN) repr1(ti, TN) {
      if (s[si - 1] == t[ti - 1]) {
        dp_begin[si - 1][ti - 1] = 1 + dp_begin[si][ti];
      }
    }

    ll res = 0;

    rep(si, SN) rep(ti, TN) {
      if (s[si] != t[ti]) {
        res += (dp_end[si][ti] + 1) * (dp_begin[si + 1][ti + 1] + 1);
      }
    }

    return res;
  }
};
