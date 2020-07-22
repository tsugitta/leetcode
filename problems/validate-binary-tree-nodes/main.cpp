// https://leetcode.com/problems/validate-binary-tree-nodes/

#include "algorithm"
#include "iomanip"
#include "iostream"
#include "queue"
#include "string"
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
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                               vector<int>& rightChild) {
    VL in_cts(n);
    rep(i, n) {
      if (leftChild[i] != -1) in_cts[leftChild[i]]++;
      if (rightChild[i] != -1) in_cts[rightChild[i]]++;
    }

    ll root = -1;
    rep(i, n) {
      if (in_cts[i] == 0) {
        if (root != -1) return false;
        root = i;
      }
    }

    if (root == -1) return false;

    VL visited(n);
    queue<ll> q;
    q.push(root);

    while (!q.empty()) {
      ll next = q.front();
      q.pop();

      if (visited[next]) return false;
      visited[next] = true;

      if (leftChild[next] != -1) q.push(leftChild[next]);
      if (rightChild[next] != -1) q.push(rightChild[next]);
    }

    rep(i, n) if (!visited[i]) return false;
    return true;
  }
};
