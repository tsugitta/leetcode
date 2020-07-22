// https://leetcode.com/problems/balance-a-binary-search-tree/

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

class Solution {
 public:
  V<int> sorted;

  TreeNode* balanceBST(TreeNode* root) {
    pushSorted(root);
    return sortedToBST(0, sorted.size() - 1);
  }

  void pushSorted(TreeNode* node) {
    if (node == NULL) return;

    pushSorted(node->left);
    sorted.push_back(node->val);
    pushSorted(node->right);
  }

  TreeNode* sortedToBST(int fromIndex, int toIndex) {
    unless(fromIndex <= toIndex) return NULL;
    int midIndex = (fromIndex + toIndex) / 2;

    TreeNode* node = new TreeNode(sorted[midIndex]);
    node->left = sortedToBST(fromIndex, midIndex - 1);
    node->right = sortedToBST(midIndex + 1, toIndex);
    return node;
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
