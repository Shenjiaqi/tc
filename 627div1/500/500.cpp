#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
//#include <unordered_set>
//#include <unordered_map>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
class GraphInversions
{
public:
  int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K);
};
const int K = 1007;
const int N = 1007;
vector<int> q[N];
int p[K];
int val[N];
int sum;
bool vis[N];
int ans;
void add( int a, int b)
{
  q[a].push_back(b);
  q[b].push_back(a);
}
int que( int v )
{
  int r(0);
  for( ; v; v ^= ( v & (-v) ) )
    r += p[v];
  return sum - r;
}
void addd( int v, int val )
{
  sum += val;
  for( ; v < K; v += ( v & (-v) ) )
    p[v] += val;
}
void dfs( int v, int left, int num)
{
  if( left == 0 )
    {
      ans = num;
      return;
    }
  if( vis[v] )
    return;
  num += que(val[v]);
  if( num < ans )
    {
      vis[v] = true;
      addd( val[v], 1);
      for( auto i : q[v] )
	dfs(i, left - 1, num);
      addd( val[v], -1);
      vis[v] = false;
    }
}
int GraphInversions::getMinimumInversions(vector <int> a, vector <int> b,
					  vector <int> v, int k)
{
  int n = a.size();
  for( int i = 0 ; i < n ; ++i )
    {
      add( a[i], b[i]);
      val[i] = v[i];
    }
  ans = 1e9;
  for( int i = 0 ; i < n ; ++i )
    dfs(i, k, 0);
  return ans > n * n ? -1 : ans;
}
int main()
{
  GraphInversions aaa;
  int a[] = {5, 2, 2, 5, 3, 5};
  int b[] = {1, 4, 0, 4, 4, 2};
  int c[] = {4, 6, 1, 3, 3, 9};
  vector<int> aa, bb, cc;
  for( int i = 0 ; i < sizeof(a) / sizeof( a[0] ); ++i )
    {
      aa.push_back( a[i] );
      bb.push_back( b[i] );
      cc.push_back( c[i] );
    }
  cout << aaa.getMinimumInversions( aa, bb, cc, 5 );
  return 0;
}
