// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

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
  int numSplits(string s) {
    ll N = s.size();
    ll res = 0;

    ll CHAR_CT = 26;

    VL first_index(CHAR_CT, INF);
    VL last_index(CHAR_CT, -INF);

    rep(i, N) {
      ll ch = s[i] - 'a';

      chmin(first_index[ch], i);
      chmax(last_index[ch], i);
    }

    rep(i, N - 1) {
      ll l_ct = 0;
      ll r_ct = 0;

      rep(ch, CHAR_CT) {
        if (first_index[ch] != INF && first_index[ch] <= i) {
          ++l_ct;
        }

        if (last_index[ch] != INF && last_index[ch] >= i + 1) {
          ++r_ct;
        }
      }

      if (l_ct == r_ct) res++;
    }

    return res;
  }
};
