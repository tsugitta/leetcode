// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

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

int MOD = 1e9 + 7;
const int W_LEN = 1005;
const int T_LEN = 1005;
int char_i_ct[26][W_LEN];
// i 文字目を最後に使って j 文字目まで作れる通り
ll dp[W_LEN][T_LEN];

class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    rep(i, 26) rep(j, W_LEN) char_i_ct[i][j] = 0;
    rep(i, W_LEN) rep(j, T_LEN) dp[i][j] = 0;

    for (auto& w : words) {
      for (int i = 0; i < w.size(); ++i) {
        int ci = w[i] - 'a';
        char_i_ct[ci][i]++;
      }
    }

    int TN = target.size();

    rep(ti, TN) {
      // ti-1 における ci 未満の総和
      ll sum = 0;

      char tc = target[ti];
      int tci = tc - 'a';

      rep(ci, W_LEN) {
        unless(char_i_ct[tci][ci] > 0) {
          if (ti > 0) sum += dp[ci][ti - 1];
          sum %= MOD;
          continue;
        }

        if (ti == 0) {
          dp[ci][ti] = char_i_ct[tci][ci];
        } else {
          dp[ci][ti] += sum * char_i_ct[tci][ci];
          dp[ci][ti] %= MOD;
          if (ti > 0) sum += dp[ci][ti - 1];
          sum %= MOD;
        }
      }
    }

    ll res = 0;

    rep(i, W_LEN) {
      res += dp[i][TN - 1];
      res %= MOD;
    }

    return res;
  }
};
