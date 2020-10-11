// https://leetcode.com/problems/split-two-strings-to-make-palindrome/

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
  bool checkPalindromeFormation(string a, string b) {
    auto is_palindrome = [](string s) -> bool {
      for (auto i = 0; i < s.size() / 2; ++i) {
        unless(s[i] == s[s.size() - 1 - i]) return false;
      }

      return true;
    };

    auto is_ok = [&](string& S, string& T) -> bool {
      int i = 0, j = S.size() - 1;

      while (i < j && S[i] == T[j]) {
        ++i;
        --j;
      }
      return is_palindrome(S.substr(i, j - i + 1)) ||
             is_palindrome(T.substr(i, j - i + 1));
    };
    return is_ok(a, b) || is_ok(b, a);
  }
};
