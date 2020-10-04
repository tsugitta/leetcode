// https://leetcode.com/problems/maximum-number-of-visible-points/

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

const ld PI = acos(-1);

class Solution {
 public:
  int visiblePoints(vector<vector<int>>& points, int angle,
                    vector<int>& location) {
    int P_CT = points.size();
    vector<ld> args;

    ll same_location_ct = 0;

    rep(i, P_CT) {
      int x = points[i][0] - location[0];
      int y = points[i][1] - location[1];

      if (x == 0 && y == 0) {
        same_location_ct++;
        continue;
      }

      ld arg = atan2(y, x);
      if (arg < 0) arg += 2 * PI;
      args.push_back(arg);
    }

    ll N = args.size();

    ld angle_rad = 2 * PI * angle / 360;

    sort(all(args));

    {
      vector<ld> args2(N);
      rep(i, N) args2[i] = args[i] + 2 * PI;
      args.insert(args.end(), all(args2));
    }

    ll res = 0;
    ll right = 0;

    rep(left, N) {
      while (right < left || (right + 1 < args.size() &&
                              args[right + 1] <= args[left] + angle_rad)) {
        ++right;
      }

      chmax(res, right - left + 1 + same_location_ct);
    }

    return res;
  }
};
