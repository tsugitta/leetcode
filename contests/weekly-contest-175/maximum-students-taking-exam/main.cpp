// https://leetcode.com/contest/weekly-contest-175/problems/maximum-students-taking-exam/

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
  int maxStudents(vector<vector<char>>& seats) {
    ll H = seats.size();
    ll W = seats[0].size();

    VL available_masks(H);

    rep(h, H) rep(w, W) {
      unless(seats[h][w] == '.') continue;
      available_masks[h] |= 1 << w;
    }

    VVL dp(H + 1, VL(1 << W));

    auto satisfied = [&](ll prev_bit, ll next_bit) {
      rep(i, W) {
        unless(next_bit & (1 << i)) continue;

        if (i - 1 >= 0) {
          if (prev_bit & (1 << (i - 1))) return false;
          if (next_bit & (1 << (i - 1))) return false;
        }
        if (i + 1 < W) {
          if (prev_bit & (1 << (i + 1))) return false;
          if (next_bit & (1 << (i + 1))) return false;
        }
      }

      return true;
    };

    rep(h, H) rep(bit, 1 << W) {
      if (h > 0 && (bit & ~available_masks[h - 1]) != 0) continue;

      rep(next_bit, 1 << W) {
        if ((next_bit & ~available_masks[h]) != 0) continue;

        unless(satisfied(bit, next_bit)) continue;

        ll bit_ct = 0;
        rep(i, W) if ((next_bit & (1 << i)) > 0) bit_ct++;

        chmax(dp[h + 1][next_bit], dp[h][bit] + bit_ct);
      }
    }

    ll res = 0;
    rep(bit, 1 << W) chmax(res, dp[H][bit]);

    return res;
  };
};
