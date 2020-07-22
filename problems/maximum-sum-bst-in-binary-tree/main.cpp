// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct SubTreeProps {
  bool isBST;
  int sum;
  int min_v;
  int max_v;
};

class Solution {
 public:
  ll res = 0;

  SubTreeProps dfs(TreeNode* root) {
    if (!root) return {true, 0, 0, 0};

    auto l = dfs(root->left);
    bool l_satisfied = !root->left || l.max_v < root->val;
    auto r = dfs(root->right);
    bool r_satisfied = !root->right || r.min_v > root->val;

    if (l.isBST && r.isBST && l_satisfied && r_satisfied) {
      ll sum = l.sum + r.sum + root->val;
      chmax(res, sum);
      return {true, sum, root->left ? l.min_v : root->val,
              root->right ? r.max_v : root->val};
    }

    return {false, 0, 0, 0};
  }

  int maxSumBST(TreeNode* root) {
    dfs(root);
    return res;
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
