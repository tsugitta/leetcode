// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

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
  int maxEvents(vector<vector<int>> &events) {
    struct Event {
      ll time, type, start, end, id;
    };

    const ll ADD = 0;
    const ll DELETE = 1;

    V<Event> es;
    rep(i, events.size()) {
      auto v = events[i];
      es.push_back({v[0], ADD, v[0], v[1], i});
      es.push_back({v[1] + 1, DELETE, v[0], v[1], i});
    }

    sort(all(es), [](Event a, Event b) { return a.time < b.time; });

    set<PL> s;
    ll next_e_index = 0;

    ll res = 0;

    rep1(ti, 1e5 + 1) {
      while (1) {
        unless(next_e_index < es.size()) break;
        auto n_e = es[next_e_index];
        unless(n_e.time <= ti) break;

        if (n_e.type == ADD) {
          s.insert({n_e.end, n_e.id});
        } else {
          if (s.count({n_e.end, n_e.id})) {
            s.erase({n_e.end, n_e.id});
          }
        }
        next_e_index++;
      }

      if (s.size() > 0) {
        res++;
        s.erase(s.begin());
      }
    }

    return res;
  }
};
