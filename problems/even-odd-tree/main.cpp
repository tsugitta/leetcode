// https://leetcode.com/problems/even-odd-tree/

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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    int level = 0;

    while (!q.empty()) {
      queue<TreeNode*> nq;
      vector<int> vals;

      while (!q.empty()) {
        auto node = q.front();
        q.pop();
        vals.push_back(node->val);
        if (node->left) nq.push(node->left);
        if (node->right) nq.push(node->right);
      }

      rep(i, vals.size()) {
        if (level % 2 == 0) {
          unless(vals[i] % 2 == 1) return false;
        } else {
          unless(vals[i] % 2 == 0) return false;
        }
      }

      rep(i, (int)vals.size() - 1) {
        if (level % 2 == 0) {
          unless(vals[i] < vals[i + 1]) return false;
        } else {
          unless(vals[i] > vals[i + 1]) return false;
        }
      }

      swap(q, nq);

      ++level;
    }

    return true;
  }
};
