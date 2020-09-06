// https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

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
  int findLengthOfShortestSubarray(vector<int>& arr) {
    ll N = arr.size();

    ll f_lis_size = 0;
    ll b_lis_size = 0;

    rep(i, N) {
      unless(i == 0 || arr[i] >= arr[i - 1]) break;
      f_lis_size++;
    }

    repr(i, N) {
      unless(i == N - 1 || arr[i] <= arr[i + 1]) break;
      b_lis_size++;
    }

    ll ng = -1;
    ll ok = N - 1;

    auto is_ok = [&](ll ct) -> bool {
      repf(left_last_i, -1, N) {
        ll right_first_i = left_last_i + ct + 1;
        unless(left_last_i + 1 <= f_lis_size) continue;
        unless((N - right_first_i) >= b_lis_size) continue;
        unless(left_last_i < 0 || right_first_i >= N ||
               arr[left_last_i] <= arr[right_first_i]) continue;
        return true;
      }

      return false;
    };

    while (ok - ng > 1) {
      ll mid = ng + (ok - ng) / 2;
      if (is_ok(mid)) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    return ok;
  }
};

class Solution2 {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    ll N = arr.size();

    ll f_lis_size = 0;
    ll b_lis_size = 0;

    rep(i, N) {
      unless(i == 0 || arr[i] >= arr[i - 1]) break;
      f_lis_size++;
    }

    repr(i, N) {
      unless(i == N - 1 || arr[i] <= arr[i + 1]) break;
      b_lis_size++;
    }

    ll res = INF;

    chmin(res, N - f_lis_size);
    chmin(res, N - b_lis_size);

    if (f_lis_size == 0 || b_lis_size == 0) return res;
    if (f_lis_size == N) return res;

    ll middle = N - f_lis_size - b_lis_size;
    ll bi = N - b_lis_size;
    rep(fi, f_lis_size) {
      while (bi < N && arr[fi] > arr[bi]) bi++;
      if (bi == N) break;

      ll to_be_removed_f = f_lis_size - fi - 1;
      ll to_be_removed_b = bi - (N - b_lis_size);

      ll to_be_removed = to_be_removed_f + to_be_removed_b + middle;
      chmin(res, to_be_removed);
    }

    return res;
  }
};
