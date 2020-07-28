// https://leetcode.com/problems/long-pressed-name/

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
  V<P<char, ll>> get_char_pairs(string str) {
    V<P<char, ll>> res;
    ll N = str.size();

    rep(i, N) {
      ll ct = 1;
      while (str[i + ct] == str[i]) ct++;

      res.emplace_back(str[i], ct);

      i += ct - 1;
    }

    return res;
  }

  bool isLongPressedName(string name, string typed) {
    auto name_pairs = this->get_char_pairs(name);
    auto typed_pairs = this->get_char_pairs(typed);

    if (name_pairs.size() != typed_pairs.size()) return false;

    rep(i, name_pairs.size()) {
      unless(name_pairs[i].fi == typed_pairs[i].fi) return false;
      unless(name_pairs[i].se <= typed_pairs[i].se) return false;
    }

    return true;
  }
};
