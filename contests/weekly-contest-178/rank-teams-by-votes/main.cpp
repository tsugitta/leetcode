// https://leetcode.com/contest/weekly-contest-178/problems/rank-teams-by-votes/

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
  string rankTeams(vector<string>& votes) {
    ll vote_ct = votes.size();
    ll char_ct = votes[0].size();

    V<unordered_map<char, ll>> ct_maps(char_ct);  // ct_maps[rank][char]

    for (auto vote : votes) {
      rep(rank, char_ct) {
        char c = vote[rank];
        ++ct_maps[rank][c];
      }
    }

    string res = votes[0];

    sort(all(res), [&](char a, char b) {
      rep(rank, char_ct) {
        ll a_ct = ct_maps[rank][a];
        ll b_ct = ct_maps[rank][b];
        if (a_ct == b_ct) continue;
        return a_ct > b_ct;
      }

      return a < b;  // alphabetical order
    });

    return res;
  }
};
