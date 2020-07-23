// https://leetcode.com/problems/k-empty-slots/

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
  int kEmptySlots(vector<int>& bulbs, int K) {
    ll N = bulbs.size();
    VL days(N);

    rep(i, N) days[bulbs[i] - 1] = i;

    ll left = 0;
    auto get_right = [&]() { return left + K + 1; };
    ll res = INF;

    rep(i, N) {
      ll right = get_right();
      unless(right < N) break;
      ll max_day = max(days[left], days[right]);

      ll ok = true;
      repf(j, i + 1, right) {
        ll day = days[j];
        if (day < max_day) {
          left = j;
          ok = false;
          break;
        }
      }

      if (ok) {
        chmin(res, max_day);
        left = right;
      }
    }

    if (res == INF) return -1;
    return res + 1;
  }
};

class Solution2 {
 public:
  int kEmptySlots(vector<int>& bulbs, int K) {
    ll N = bulbs.size();
    set<ll> s;

    rep(i, N) {
      ll b = bulbs[i];
      s.insert(b);

      auto it = s.find(b);
      it++;

      if (it != s.end() && *it == b + K + 1) {
        return i + 1;
      }

      it--;
      if (it == s.begin()) continue;

      it--;

      if (*it == b - K - 1) {
        return i + 1;
      }
    }

    return -1;
  }
};

struct MinQueue {
  deque<ll> q;
  deque<ll> mins;

  void push(ll v) {
    q.push_back(v);
    while (mins.size() && mins.back() > v) mins.pop_back();
    mins.push_back(v);
  }

  void pop() {
    if (q.size() == 0) return;

    if (mins.front() == q.front()) mins.pop_front();
    q.pop_front();
  }

  ll get_min() {
    if (mins.size() == 0) return INF;

    return mins[0];
  }

  ll size() { return q.size(); }
};

class Solution3 {
 public:
  int kEmptySlots(vector<int>& bulbs, int K) {
    ll N = bulbs.size();

    VL days(N);
    rep(i, N) days[bulbs[i] - 1] = i;

    MinQueue q;

    ll res = INF;

    rep(i, N) {
      q.push(days[i]);
      if (q.size() > K) q.pop();

      ll left = i - K;
      ll right = i + 1;
      unless(left >= 0 && right < N) continue;

      ll max_day = max(days[left], days[right]);
      if (q.get_min() >= max_day) {
        chmin(res, max_day);
      }
    }

    if (res == INF) return -1;
    return res + 1;
  }
};

class Solution4 {
 public:
  int kEmptySlots(vector<int>& bulbs, int K) {
    ll N = bulbs.size();

    VL days(N);
    rep(i, N) days[bulbs[i] - 1] = i;

    set<ll> s;

    ll res = INF;

    rep(i, N) {
      s.insert(days[i]);
      if (s.size() > K) s.erase(s.find(days[i - K]));

      ll left = i - K;
      ll right = i + 1;
      unless(left >= 0 && right < N) continue;

      ll max_day = max(days[left], days[right]);
      if (s.size() == 0 || *s.begin() >= max_day) {
        chmin(res, max_day);
      }
    }

    if (res == INF) return -1;
    return res + 1;
  }
};
