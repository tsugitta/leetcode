// https://leetcode.com/contest/weekly-contest-198/problems/find-a-value-of-a-mysterious-function-closest-to-target/

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
  int closestToTarget(vector<int>& arr, int target) {
    ll N = arr.size();
    ll bit_ct = 25;
    VVL bit_indices(bit_ct, VL());

    rep(i, N) {
      rep(bit, bit_ct) {
        if (arr[i] & (1 << bit)) {
          bit_indices[bit].push_back(i);
        }
      }
    }

    VL dp(N);
    ll res = abs(arr[0] - target);

    ll left = N - 1;

    repr(i, N) {
      rep(bit, bit_ct) {
        if (arr[i] & (1 << bit)) continue;

        auto& indices = bit_indices[bit];
        while (!indices.empty() && indices.back() > i) {
          dp[indices.back()] -= 1 << bit;
          indices.pop_back();
        }
      }

      dp[i] = arr[i];

      while (left > i && dp[left] < target) left--;
      chmin(res, abs(target - dp[left]));
      if (left + 1 < N) chmin(res, abs(target - dp[left + 1]));
    }

    return res;
  }
};
