// https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

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
  int minSwaps(vector<vector<int>>& grid) {
    ll N = grid.size();
    VL nums(N);

    rep(i, N) {
      auto row = grid[i];
      ll ct = 0;
      repr(j, N) {
        if (row[j] == 0) ct++;
        if (row[j] == 1) break;
      }

      nums[i] = N - 1 - ct;
    }

    ll res = 0;

    rep(i, N) {
      if (nums[i] <= i) {
        continue;
      }

      bool found = false;
      repf(j, i + 1, N) {
        if (nums[j] <= i) {
          found = true;
          for (int k = j - 1; k >= i; k--) {
            swap(nums[k], nums[k + 1]);
            res++;
          }
          break;
        }
      }

      if (!found) return -1;
    }

    return res;
  }
};
