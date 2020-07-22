// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

#include "algorithm"
#include "cmath"
#include "functional"
#include "iostream"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "vector"
#define rep(i, to) for (ll i = 0; i < (to); ++i)
#define repf(i, from, to) for (ll i = from; i < (to); ++i)
#define repr(i, from) for (ll i = from - 1; i >= 0; --i)
#define all(vec) vec.begin(), vec.end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
template <typename T>
using V = vector<T>;
using VL = V<ll>;
using VVL = V<VL>;
template <typename T, typename U>
using P = pair<T, U>;
using PL = P<ll, ll>;
using VPL = V<PL>;
template <typename T>
inline bool chmax(T &a, T b);
template <typename T>
inline bool chmin(T &a, T b);

template <typename T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

class Solution {
 public:
  int countNegatives(vector<vector<int>> &grid) {
    ll res = 0;

    for (auto vec : grid)
      for (auto val : vec) {
        if (val < 0) res++;
      }

    return res;
  }
};
