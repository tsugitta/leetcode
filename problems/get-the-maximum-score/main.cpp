// https://leetcode.com/problems/get-the-maximum-score/

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
  int maxSum(vector<int>& nums1, vector<int>& nums2) {
    ll i1 = 0;
    ll i2 = 0;
    ll N1 = nums1.size();
    ll N2 = nums2.size();

    ll cur1 = 0;
    ll cur2 = 0;
    ll res = 0;
    ll MOD = 1e9 + 7;

    while (i1 < N1 || i2 < N2) {
      if (i1 < N1 && (i2 == N2 || nums1[i1] < nums2[i2])) {
        cur1 += nums1[i1++];
      } else if (i2 < N2 && (i1 == N1 || nums2[i2] < nums1[i1])) {
        cur2 += nums2[i2++];
      } else {
        res += max(cur1, cur2) + nums1[i1];
        res %= MOD;
        i1++, i2++;
        cur1 = 0, cur2 = 0;
      }
    }

    return (res + max(cur1, cur2)) % MOD;
  }
};
