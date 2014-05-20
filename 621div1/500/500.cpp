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
class TreesAnalysis
{
public:
  long long treeSimilarity(vector <int> tree1, vector <int> tree2);
};
const int N = 4007;
int n;
// ll ap1[N][ N / 64 + 2 ];
ll ap2[N][ N / 64 + 2 ];
char ct[N][N];
int fm1[N], fm2[N];
int num1[N], num2[N];
vector<int> p1[N], p2[N];
void dfs1( int v, int from )
{
  fm1[v] = from;
  // ap1[v][ v / 64 ] |= 1LL << ( v % 64 );
  num1[v] = 1;
  for( auto i : p1[v] )
    if( i != from )
      {
	dfs1( i, v);
	// for( int j = 0; j < n / 64 + 1; ++j )
	//   ap1[v][j] |= ap1[i][j];
	num1[v] += num1[i];
      }
}
void dfs2( int v, int from )
{
  fm2[v] = from;
  ap2[v][ v / 64 ] |= 1LL << ( v % 64 );
  num2[v] = 1;
  for( auto i : p2[v] )
    if( i != from )
      {
	dfs2( i, v);
	for( int j = 0; j < n / 64 + 1; ++j )
	  ap2[v][j] |= ap2[i][j];
	num2[v] += num2[i];
      }
}
int dp[N][N];
int cal( int a, int b )
{
  if( dp[a][b] < 0)
    {
      int cnt(0);
      for( auto i : p1[a] )
	if( i != fm1[a] )
	  cnt += cal( i, b );
      if( a == b || ( ap2[b][ a / 64 ] & ( 1LL << ( a % 64 ) ) ) )
      	++cnt;
      // if( ap2[b][ a / 64 ] & ( 1LL << ( a % 64 ) ) )
      // 	++cnt;
      // if( ap1[a][ b / 64 ] & ( 1LL << ( b % 64 ) ) )
      // 	++cnt;
      // if( a == b )
      // 	--cnt;
      dp[a][b] = cnt;
    }
  return dp[a][b];
}
long long TreesAnalysis::treeSimilarity(vector <int> t1,
					vector <int> t2)
{
  n = t1.size() + 1;
  for( int i = 0; i < t1.size(); ++i )
    {
      p1[i].push_back( t1[i] );
      p1[ t1[i] ].push_back( i );
      p2[i].push_back( t2[i] );
      p2[ t2[i] ].push_back( i );
    }
  dfs1( 0, 0);
  dfs2( 0, 0);
  ll ans(0);
  memset( dp, 1 << 7, sizeof(dp) );
  for( int i = 1; i < n; ++i )
    for( int j = 1; j < n; ++j )
      {
	ll tmp = cal( i, j );
	// assert( ( tmp & 1 ) == 0 );
	int size1 = num1[i];
	int size2 = num2[j];
	tmp = max( max( tmp, n - size1 - size2 + tmp ), 
		   max( size2 - tmp, size1 - tmp ) );
	// cout << i << ' ' << j << ' ' << size1 << ' ' << size2 << ' ' << tmp << endl;
	ans += tmp * tmp;
      }
  return ans;
}
int main()
{
  // int a[] = {1};
  // int b[] = {1};
  int a[] = {2, 4, 1, 0};
  int b[] = {1, 4, 4, 4};
  vector<int> aa, bb;
  for( int i = 0; i < sizeof(a) / sizeof(a[0] ); ++i )
    aa.push_back( a[i] ), bb.push_back( b[i] );
  TreesAnalysis t;
  cout << t.treeSimilarity( aa, bb ) << endl;
  return 0;
}
