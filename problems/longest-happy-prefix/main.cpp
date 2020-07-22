// https://leetcode.com/problems/longest-happy-prefix/

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

// // KMP
class Solution2 {
 public:
  string longestPrefix(string& s) {
    // dp[i]: the matched prefix length the i is the last index
    VL dp(s.size());

    ll j = 0;

    rep1(i, s.size() - 1) {
      if (s[i] == s[j])
        dp[i] = ++j;
      else if (j > 0) {
        j = dp[j - 1];
        --i;
      }
    }

    return s.substr(0, j);
  }
};

// O(|S|)
// res[i]: S と S[i:] が先頭から何文字一致しているか
VL z_algorithm(const string& S) {
  ll N = S.size();
  VL res(N);
  res[0] = N;
  ll i = 1, j = 0;

  while (i < N) {
    while (i + j < N && S[j] == S[i + j]) ++j;
    res[i] = j;

    if (j == 0) {
      ++i;
      continue;
    }

    ll k = 1;
    while (i + k < N && k + res[k] < j) res[i + k] = res[k], ++k;
    i += k, j -= k;
  }

  return res;
}

class Solution {
 public:
  string longestPrefix(string& s) {
    ll N = s.size();
    if (N == 0) return "";

    VL lcp = z_algorithm(s);

    rep1(i, N - 1) {
      if (lcp[i] == N - i) return s.substr(i, N - i);
    }

    return "";
  }
};

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
