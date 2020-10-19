// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

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
  string findLexSmallestString(string s, int a, int b) {
    string res = s;
    int N = s.size();

    rep(odd_act, 11) {
      rep(even_act, 11) {
        if (b % 2 == 0 && even_act > 0) continue;

        rep(shift_i, N) {
          string r = s;

          rep(i, N) {
            int val = s[i] - '0';
            if (i % 2 == 0) val += (even_act * a);
            if (i % 2 == 1) val += (odd_act * a);
            val %= 10;
            int ni = i + shift_i * b;
            ni %= N;
            r[ni] = '0' + val;
          }

          chmin(res, r);
        }
      }
    }

    return res;
  }
};
