// https://leetcode.com/contest/biweekly-contest-21/problems/find-the-longest-substring-containing-vowels-in-even-counts/

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
  int findTheLongestSubstring(string s) {
    auto char_to_mask = [](char c) -> ll {
      string vowels = "aeiou";
      auto it = find(all(vowels), c);

      if (it == vowels.end()) return 0;

      ll index = distance(vowels.begin(), it);

      return 1 << index;
    };

    ll res = 0;
    ll cur_parity = 0;

    unordered_map<ll, ll> parity_to_index_map;
    parity_to_index_map[cur_parity] = -1;

    rep(i, s.size()) {
      cur_parity ^= char_to_mask(s[i]);

      if (parity_to_index_map.count(cur_parity)) {
        chmax(res, i - parity_to_index_map[cur_parity]);
      }

      unless(parity_to_index_map.count(cur_parity)) {
        parity_to_index_map[cur_parity] = i;
      }
    }

    return res;
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
