#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <cmath>
#include <bitset>
#include <list>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
using namespace std;
#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}


#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;


#if __cplusplus >= 201703L
    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif


ll prefixs(int ind, vector<int> &fenwick) {
    ll sum = 0;
    while (ind > 0) {
        sum += fenwick[ind]; //global
        ind -= (ind & -ind);
    }
    return sum;
}
void update(int ind, int v, vector<int>& fenwick){
    int n = fenwick.size(); 
    while(ind <= n){  //can also remove'='
        fenwick[ind] += v;
        ind += (ind & -ind);
    }
}

class DSU {
    vector<int> parent, size, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n+1,n);
        iota(parent.begin(), parent.end(), 0);
    }
    int findparent(int n) {
        if (n == parent[n]) return n;
        return parent[n] = findparent(parent[n]);
    }
    void Unionbyrank(int a, int b){
        int pa = findparent(a), pb =  findparent(b);
        if(rank[pa] == rank[pb]) return;
        else if(rank[pa] < rank[pb]) parent[pa] = pb;
        else{ parent[pb] = pa; rank[pa]++; }
    }
    void Unionbysize(int a, int b) {
        int pa = findparent(a), pb = findparent(b);
        if (pa == pb) return;
        if (size[pa] < size[pb]) swap(pa, pb);
        parent[pb] = pa;
        size[pa] += size[pb];
    }
};

struct Seg {
  int n; vector<ll> t;
  Seg(int _n): n(_n), t(4*n) {}
  void upd(int v,int tl,int tr,int pos,ll val){
    if (tl==tr) t[v]=val;
    else{
      int tm=(tl+tr)/2;
      if (pos<=tm) upd(v*2,tl,tm,pos,val);
      else       upd(v*2+1,tm+1,tr,pos,val);
      t[v]=max(t[v*2],t[v*2+1]);
    }
  }
  ll qry(int v,int tl,int tr,int l,int r){
    if (l>r) return LLONG_MIN;
    if (l<=tl && tr<=r) return t[v];
    int tm=(tl+tr)/2;
    return max(qry(v*2,tl,tm,l,min(r,tm)),
               qry(v*2+1,tm+1,tr,max(l,tm+1),r));
  }
};

template<typename T>
T isqrt(T x) {
    T left = 0, right = x, ans = 0;
    while (left <= right) {
        T mid = left + (right - left) / 2;
        if (mid * mid <= x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

ll fastexp(ll a, ll b, ll m = 1000000007) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1}; 
int main() {
    fast; //ios_base::sync_with_stdio(false);  cin.tie(NULL);
    
    return 0;
}
