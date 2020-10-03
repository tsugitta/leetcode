// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/

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
  int convert(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));

    int t = h * 60 + m;
    return t;
  }

  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    map<string, V<int>> mp;

    rep(i, keyName.size()) mp[keyName[i]].push_back(convert(keyTime[i]));

    for (auto& [_, times] : mp) {
      sort(all(times));
    }

    V<string> res;

    for (auto& [name, times] : mp) {
      repf(i, 2, times.size()) {
        if (times[i] - times[i - 1] <= 60 && times[i] - times[i - 2] <= 60) {
          res.push_back(name);
          break;
        }
      }
    }

    return res;
  }
};
