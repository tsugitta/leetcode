// https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/

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
inline bool chmax(T &a, T b);
template <typename T>
inline bool chmin(T &a, T b);

const ll INF = 1e18;

template <typename T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <typename T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class Monoid, class Action>
struct LazySegTree {
  using FuncMonoid = function<Monoid(Monoid, Monoid)>;
  using FuncAction = function<void(Monoid &, Action)>;
  using FuncLazy = function<void(Action &, Action)>;
  FuncMonoid FM;
  FuncAction FA;
  FuncLazy FL;
  Monoid UNITY_MONOID;
  Action UNITY_LAZY;
  ll SIZE, HEIGHT;
  vector<Monoid> dat;
  vector<Action> lazy;

  LazySegTree(ll n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
              const Monoid &unity_monoid, const Action &unity_lazy)
      : FM(fm),
        FA(fa),
        FL(fl),
        UNITY_MONOID(unity_monoid),
        UNITY_LAZY(unity_lazy) {
    SIZE = 1;
    HEIGHT = 0;
    while (SIZE < n) SIZE <<= 1, ++HEIGHT;
    dat.assign(SIZE * 2, UNITY_MONOID);
    lazy.assign(SIZE * 2, UNITY_LAZY);
  }

  void init(ll n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid &unity_monoid, const Action &unity_lazy) {
    FM = fm;
    FA = fa;
    FL = fl;
    UNITY_MONOID = unity_monoid;
    UNITY_LAZY = unity_lazy;
    SIZE = 1;
    HEIGHT = 0;
    while (SIZE < n) SIZE <<= 1, ++HEIGHT;
    dat.assign(SIZE * 2, UNITY_MONOID);
    lazy.assign(SIZE * 2, UNITY_LAZY);
  }

  void set(ll a, const Monoid &v) { dat[a + SIZE] = v; }
  void build() {
    for (ll k = SIZE - 1; k > 0; --k) dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
  }

  inline void evaluate(ll k) {
    if (lazy[k] == UNITY_LAZY) return;
    if (k < SIZE) FL(lazy[k * 2], lazy[k]), FL(lazy[k * 2 + 1], lazy[k]);
    FA(dat[k], lazy[k]);
    lazy[k] = UNITY_LAZY;
  }

  inline void update(ll a, ll b, const Action &v, ll k, ll l, ll r) {
    evaluate(k);
    if (a <= l && r <= b)
      FL(lazy[k], v), evaluate(k);
    else if (a < r && l < b) {
      update(a, b, v, k * 2, l, (l + r) >> 1),
          update(a, b, v, k * 2 + 1, (l + r) >> 1, r);
      dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
    }
  }

  /* [a, b) */
  inline void update(ll a, ll b, const Action &v) {
    update(a, b, v, 1, 0, SIZE);
  }

  inline Monoid get(ll a, ll b, ll k, ll l, ll r) {
    evaluate(k);
    if (a <= l && r <= b)
      return dat[k];
    else if (a < r && l < b)
      return FM(get(a, b, k * 2, l, (l + r) >> 1),
                get(a, b, k * 2 + 1, (l + r) >> 1, r));
    else
      return UNITY_MONOID;
  }

  /* [a, b) */
  inline Monoid get(ll a, ll b) { return get(a, b, 1, 0, SIZE); }

  inline Monoid operator[](ll a) { return get(a, a + 1); }
};

class Solution {
 public:
  string minInteger(string num, int k) {
    ll N = num.size();
    V<queue<ll>> num_indices(10, queue<ll>());

    rep(i, N) num_indices[num[i] - '0'].push(i);

    string res = "";

    auto fm = [](ll a, ll b) { return a + b; };
    auto fa = [](ll &a, ll b) { a = a + b; };
    auto fl = [](ll &a, ll b) { a = a + b; };
    LazySegTree<ll, ll> st(N, fm, fa, fl, 0, 0);

    ll rest = k;

    rep(i, N) {
      rep(num, 10) {
        unless(num_indices[num].size() > 0) continue;

        ll index = num_indices[num].front();
        ll shift_ct = st.get(0, index + 1);

        unless(index - shift_ct <= rest) continue;

        rest -= index - shift_ct;

        num_indices[num].pop();
        st.update(index, index + 1, 1);
        res.push_back('0' + num);

        break;
      }
    }

    return res;
  }
};
