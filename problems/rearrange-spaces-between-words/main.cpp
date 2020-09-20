// https://leetcode.com/problems/rearrange-spaces-between-words/

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
  string reorderSpaces(string text) {
    vector<string> words;
    int space_ct = 0;

    string cur = "";

    rep(i, text.size()) {
      if (text[i] == ' ') {
        if (cur.size() > 0) {
          words.push_back(cur);
          cur = "";
        }

        space_ct++;
      } else {
        cur += text[i];
      }
    }

    if (cur.size()) words.push_back(cur);
    int wct = words.size();

    if (wct == 1) {
      string res = words[0];
      res += string(space_ct, ' ');
      return res;
    }
    int divided = space_ct / (wct - 1);
    int last = space_ct - divided * (wct - 1);

    string res = "";

    rep(i, words.size()) {
      string w = words[i];
      res += w;
      if (i + 1 < words.size()) res += string(divided, ' ');
    }

    res += string(last, ' ');

    return res;
  }
};
