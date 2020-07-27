// https://leetcode.com/problems/rotated-digits/

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
  int rotatedDigits(int N) {
    int dp[10][2][2];  // i 桁目、 tight, valid 使ったか
    memset(dp, 0, sizeof(dp));
    dp[0][1][0] = 1;

    int max_length = to_string(N).size();

    rep(i, max_length) rep(tight, 2) rep(valid_used, 2) rep(num, 10) {
      if (num == 3 || num == 4 || num == 7) continue;
      int max_digit_num = to_string(N)[i] - '0';
      if (tight && num > max_digit_num) continue;
      bool next_tight = tight && num == max_digit_num;
      bool next_valid_used =
          valid_used || (num == 2 || num == 5 || num == 6 || num == 9);

      dp[i + 1][next_tight][next_valid_used] += dp[i][tight][valid_used];
    }

    int res = 0;
    rep(i, 2) res += dp[max_length][i][1];
    return res;
  }
};
