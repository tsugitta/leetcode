// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

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

int diff[20];

class Solution {
 public:
  int maximumRequests(int N, vector<vector<int>>& requests) {
    int RN = requests.size();
    ll MAX_BIT = 1ll << RN;

    int res = 0;

    rep(bit, MAX_BIT) {
      fill(&diff[0], &diff[0] + sizeof(diff) / sizeof(diff[0]), 0);

      int pop_ct = 0;

      rep(i, RN) {
        if (bit & (1 << i)) {
          auto& r = requests[i];
          diff[r[0]]--;
          diff[r[1]]++;
          ++pop_ct;
        }
      }

      ll ok = true;
      rep(i, N) if (diff[i] != 0) {
        ok = false;
        break;
      }

      if (ok) {
        chmax(res, pop_ct);
      }
    }

    return res;
  }
};
