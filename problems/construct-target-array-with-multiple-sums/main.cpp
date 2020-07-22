// https://leetcode.com/problems/construct-target-array-with-multiple-sums/

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
#define rep1(i, to) for (ll i = 1; i <= (to); ++i)
#define repf(i, from, to) for (ll i = from; i < (to); ++i)
#define repr(i, from) for (ll i = from - 1; i >= 0; --i)
#define all(vec) vec.begin(), vec.end()
#define unless(cond) if (!(cond))
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
  bool isPossible(vector<int> &target) {
    sort(all(target));
    ll sum = accumulate(all(target), 0ll);

    priority_queue<ll> q;

    for (auto v : target) {
      q.push(v);
    }

    while (sum > target.size()) {
      ll n = q.top();
      q.pop();
      ll new_n = n - (sum - n);
      if (new_n <= 0) return false;
      sum -= n - new_n;
      q.push(new_n);
    }

    return q.top() == 1;
  }
};
