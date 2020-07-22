// https://leetcode.com/problems/making-file-names-unique/

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
  vector<string> getFolderNames(vector<string>& names) {
    map<string, ll> largest_number_map;

    V<string> res(0);

    auto get_name = [](string s, ll number) {
      if (number == 0) return s;

      string res = s;
      res += "(" + to_string(number) + ")";
      return res;
    };

    for (string name : names) {
      ll next = largest_number_map[name];

      while (largest_number_map[get_name(name, next)]) {
        ++next;
      }

      ++largest_number_map[name];
      largest_number_map[get_name(name, next)] = 1;
      res.push_back(get_name(name, next));
    }

    return res;
  }
};
