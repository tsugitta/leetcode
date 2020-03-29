// https://leetcode.com/contest/weekly-contest-182/problems/count-number-of-teams/

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
  int numTeams(vector<int>& rating) {
    ll res = 0;
    ll N = rating.size();

    rep(i, N) {
      ll left_greater = 0;
      ll left_less = 0;
      ll right_greater = 0;
      ll right_less = 0;

      rep(j, N) {
        if (i == j) continue;

        if (i < j) {
          if (rating[i] < rating[j]) {
            right_greater++;
          } else {
            right_less++;
          }
        } else {
          if (rating[i] < rating[j]) {
            left_greater++;
          } else {
            left_less++;
          }
        }
      }

      res += left_greater * right_less + left_less * right_greater;
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
