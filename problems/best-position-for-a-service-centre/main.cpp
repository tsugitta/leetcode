// https://leetcode.com/problems/best-position-for-a-service-centre/

#include "algorithm"
#include "bitset"
#include "cmath"
#include "complex"
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
  double getMinDistSum(vector<vector<int>>& positions) {
    ld left = 100;
    ld bottom = 100;
    ld right = 0;
    ld top = 0;

    V<complex<ld>> points;

    for (auto& p : positions) {
      points.emplace_back(p[0], p[1]);
    }

    for (auto& p : points) {
      chmin(left, p.real());
      chmin(bottom, p.imag());
      chmax(right, p.real());
      chmax(top, p.imag());
    }

    if (left == right && bottom == top) return 0;

    ld res = INF;
    complex<ld> res_p(0, 0);

    while ((right - left) > 1e-7 || (top - bottom) > 1e-7) {
      ll delta_size = 3;
      ld delta_x = (right - left) / delta_size;
      ld delta_y = (top - bottom) / delta_size;

      rep(xi, delta_size + 1) {
        rep(yi, delta_size + 1) {
          ld x = left + delta_x * xi;
          ld y = bottom + delta_y * yi;

          auto target = complex(x, y);

          ld d = 0;
          for (auto& p : points) d += abs(p - target);

          if (chmin(res, d)) {
            res_p = target;
          }
        }
      }

      ld delta_x_with_eps = delta_x * 1.1;
      ld delta_y_with_eps = delta_y * 1.1;

      left = res_p.real() - delta_x_with_eps;
      bottom = res_p.imag() - delta_y_with_eps;
      right = res_p.real() + delta_x_with_eps;
      top = res_p.imag() + delta_y_with_eps;
    }

    return res;
  }
};
