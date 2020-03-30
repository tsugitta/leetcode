// https://leetcode.com/contest/weekly-contest-182/problems/design-underground-system/

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

struct AccRecord {
  ll num, total_time;
};

struct CheckIn {
  string station;
  ll time;
};

class UndergroundSystem {
 public:
  map<string, map<string, AccRecord>> acc_m;
  map<ll, CheckIn> pend_m;

  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    pend_m[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    auto pend = pend_m[id];

    if (acc_m.count(pend.station) == 0) {
      acc_m[pend.station] = map<string, AccRecord>();
    }

    auto& acc = acc_m[pend.station][stationName];
    acc.num++;
    acc.total_time += (t - pend.time);

    pend_m.erase(id);
  }

  double getAverageTime(string startStation, string endStation) {
    auto m = acc_m[startStation][endStation];
    return (double)m.total_time / m.num;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

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
