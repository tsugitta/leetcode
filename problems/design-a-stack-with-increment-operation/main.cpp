// https://leetcode.com/problems/design-a-stack-with-increment-operation/

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

class CustomStack {
  // increments[i]: sum it to 0 ~ i
  vector<int> stack, incs;
  int maxSize;

 public:
  CustomStack(int maxSize) : maxSize(maxSize) { incs.resize(maxSize); }

  void push(int x) {
    if (stack.size() < maxSize) stack.push_back(x);
  }

  int pop() {
    unless(stack.size() > 0) return -1;
    int i = stack.size() - 1;
    int val = stack.back() + incs[i];
    if (i > 0) incs[i - 1] += incs[i];
    incs[i] = 0;
    stack.pop_back();
    return val;
  }

  void increment(int k, int val) {
    int i = min<int>(k, stack.size()) - 1;
    if (i >= 0) incs[i] += val;
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

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
