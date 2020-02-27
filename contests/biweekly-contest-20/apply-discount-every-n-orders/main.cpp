// https://leetcode.com/contest/biweekly-contest-20/problems/apply-discount-every-n-orders/

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

class Cashier {
 public:
  int mod, dis, cur = 0;
  unordered_map<int, int> price_map;

  Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
    mod = n;
    dis = discount;

    rep(i, products.size()) { price_map[products[i]] = prices[i]; }
  }

  double getBill(vector<int> product, vector<int> amount) {
    cur++;

    ld res = 0;

    rep(i, product.size()) res += price_map[product[i]] * amount[i];

    if (cur % mod == 0) {
      res *= (100.0 - dis) / 100;
    }

    return res;
  }
};
