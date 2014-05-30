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
class Ethernet
{
public:
  int connect(vector <int> parent, vector <int> dist, int maxDist);
};
const int N = 57;
const int M = 507;
const int inf = N;
vector<pair<int,int> >  p[N];
int dp[N][M];
void dfs( int v, int from, const int &md )
{
  if( !p[v].empty() )
    {
      dp[v][0] = 1;
      return ;
    }
  int sum[M] = {0};
  for( int i = 0; i < p[v].size(); ++i )
    {
      int t = p[v][i].first;
      if( t != from )
	{
	  dfs( t, v, md );
	  int dis = p[v][i].second;
	  for( int j = 0; j <= dis; ++j )
	    sum[0] += dp[t][0];
	  for( int j = 1; j + dis <= md; ++j )
	    sum[ j + dis ] += dp[t][j];
	}
    }
  for( int i = 0; i <= md; ++i )
    dp[v][i] = inf;
  for( int i = 0; i < p[v].size(); ++i )
    {
      int t = p[v][i].first;
      if( t != from )
	{
	  int dis = p[v][i].second;
	  for( int j = 0; j <= md; ++j )
	    {
	      int tmp;
	      if( j <= dis )
		tmp = dp[t][0];
	      else
		tmp = dp[t][ j - dis ];
	      tmp += sum[ md - j ];
	      if( md - j <= dis )
		tmp -= dp[t][0];
	      else tmp -= dp[t][ md - j - dis ];
	      dp[v][j] = min( dp[v][j], tmp );
	      dp[v][0] = min( dp[v][0], 1 + tmp );
	    }
	}
    }
  for( int i = 1; i <= md; ++i )
    dp[v][i] = min( dp[v][i], dp[v][ i - 1 ] );
}
int Ethernet::connect(vector <int> par, vector <int> dst, int md)
{
  int n = par.size() + 1;
  for( int i = 1; i < n; ++i )
    {
      int a = i;
      int b = par[ i - 1 ];
      p[a].push_back( make_pair( b, dst[ i - 1 ] ) );
      p[b].push_back( make_pair( a, dst[ i - 1 ] ) );
    }
  dfs( 0, 0, md );
  return dp[0][0];
}
int main()
{
  Ethernet a;
  // int b[] = {0, 0, 0};
  // int c[] = {1, 1, 1};
  int b[] = {0,0,0,0,0,0,0};
  int c[] = {1,2,3,4,5,6,7};
  vector<int> bb, cc;
  for( int i = 0; i < sizeof(b) / sizeof(b[0]); ++i )
    bb.push_back( b[i] ),
      cc.push_back( c[i] );
  cout << a.connect( bb, cc, 2 ) << endl;
  return 0;
}
