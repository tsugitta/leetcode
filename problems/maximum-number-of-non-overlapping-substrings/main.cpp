// https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/

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
  vector<string> maxNumOfSubstrings(string s) {
    ll N = s.size();
    ll char_ct = 'z' - 'a' + 1;

    VL ls(char_ct, INF);
    VL rs(char_ct, -INF);

    rep(i, N) {
      ll c = s[i] - 'a';
      chmin(ls[c], i);
      chmax(rs[c], i);
    }

    auto get_right = [&](ll left) -> ll {
      ll left_ch = s[left] - 'a';
      ll right = rs[left_ch];

      for (ll i = left; i <= right; i++) {
        ll ch = s[i] - 'a';

        if (ls[ch] < left) return -1;
        chmax(right, rs[ch]);
      }

      return right;
    };

    V<string> res;

    ll cur_left = -1;
    ll cur_right = INF;

    rep(i, N) {
      ll ch = s[i] - 'a';

      if (i == ls[ch]) {
        ll right = get_right(i);

        if (right == -1) continue;

        if (chmin(cur_right, right)) {
          cur_left = i;
        }
      }

      if (i == cur_right) {
        string _res = string(s.begin() + cur_left, s.begin() + cur_right + 1);
        res.push_back(_res);
        cur_right = INF;
      }
    }

    return res;
  }
};
