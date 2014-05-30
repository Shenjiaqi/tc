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
class BuildingRoutes
{
public:
  int build(vector <string> dist, int T);
};
const int N = 57;
int p[N][N], bk[N][N];
int cnt[N][N];
bool vis[N];
int BuildingRoutes::build(vector <string> dist, int T)
{
  int n = dist.size();
  for( int i = 0 ; i < n; ++i )
    for( int j = 0 ; j  < n; ++j )
      p[i][j] = dist[i][j] - '0';
  memcpy( bk, p, sizeof(bk) );
  for( int k = 0; k < n; ++k )
    for( int i = 0 ; i < n; ++i )
      if( i != k )
	for( int j = 0; j < n; ++j )
	  if( j != i && j != k )
	    p[i][j] = min( p[i][j], p[i][k] + p[k][j] );
  int ans(0);
  for( int i = 0; i < n; ++i )
    for( int j = 0; j < n; ++j )
      if( i != j )
	{
	  memset( vis, 0, sizeof(vis) );
	  queue<int> que;
	  que.push( i );
	  vis[i] = true;
	  for( ; !que.empty(); que.pop() )
	    {
	      int v = que.front();
	      for( int k = 0; k < n; ++k )
		if( k != v && bk[v][k] + p[k][j] == p[v][j] )
		  {
		    ++cnt[v][k];
		    if( !vis[k] )
		      {
			que.push( k );
			vis[k] = true;
		      }
		  }
	    }
	}
  for( int i = 0 ; i < n; ++i )
    for( int j = 0; j < n; ++j )
      if( cnt[i][j] >= T )
	ans += bk[i][j];
  return ans;
}
int main()
{
  
  return 0;
}
