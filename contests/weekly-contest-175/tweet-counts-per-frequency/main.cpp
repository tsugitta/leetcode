// https://leetcode.com/contest/weekly-contest-175/problems/tweet-counts-per-frequency/

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

class TweetCounts {
  unordered_map<string, multiset<int>> tweets;

 public:
  TweetCounts() {}

  void recordTweet(string tweetName, int time) {
    tweets[tweetName].insert(time);
  }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                         int startTime, int endTime) {
    int d;

    if (freq == "minute") {
      d = 60;
    } else if (freq == "hour") {
      d = 60 * 60;
    } else if (freq == "day") {
      d = 24 * 60 * 60;
    }

    V<int> res((endTime - startTime) / d + 1);
    const auto s_it = tweets.find(tweetName);

    if (s_it != tweets.end()) {
      auto s = s_it->se;
      auto it = s.lower_bound(startTime);

      while (it != s.end() && *it <= endTime) {
        ++res[(*it - startTime) / d];
        ++it;
      }
    }

    return res;
  }
};
