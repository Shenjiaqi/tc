#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <unordered_map>
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
class SpecialCells
{
public:
  int guess(vector <int> x, vector <int> y);
};
const int N = 51 * 2 + 7;
const int M = N * N + 7;
int edge[M][4],edgeI;
int s[N];
int deg[N];
int S, T;
queue<int> que;
bool in[N];
int from[N][2];
int dis[N];
ll mat( ll a, ll b)
{
  return ( a << 30 ) | b;
}
void add( int from, int to, int cost, int cap )
{
  ++edgeI, edge[edgeI][0] = to, edge[edgeI][1] = cap, 
    edge[edgeI][2] = s[from], s[from] = edgeI, edge[edgeI][3] = cost;
  ++edgeI, edge[edgeI][0] = from, edge[edgeI][1] = 0,
    edge[edgeI][2] = s[to], s[to] = edgeI, edge[edgeI][3] = -cost;
}
int SpecialCells::guess(vector <int> x, vector <int> y)
{
  int n = x.size();
  unordered_map<int,int> mapX, mapY;
  unordered_set<ll> match;
  int cntX = 0, cntY = n;
  for( int i = 0 ; i < n; ++i )
    {
      if( mapX.find( x[i] ) == mapX.end() )
	mapX[ x[i] ] = cntX++;
      x[i] = mapX[ x[i] ];
      if( mapY.find( y[i] ) == mapY.end() )
	mapY[ y[i] ] = cntY++;
      y[i] = mapY[ y[i] ];
      match.insert( mat( x[i], y[i] ) );
      ++deg[ x[i] ];
      ++deg[ y[i] ];
    }
  unordered_set<ll> linked;
  for( int i = 0 ; i < n ; ++i )
    for( int j = 0 ; j < n ; ++j )
      {
	ll tmp = mat(x[i], y[j] );
	if( linked.find(tmp)  == linked.end() )
	  {
	    linked.insert(tmp);
	    int c = 0;
	    if( match.find(tmp) != match.end() )
	      c = 1;
	    add( x[i], y[j], c, 1 );
	  }
      }
  S = 2 * n, T = S + 1;
  for( int i = 0 ; i < cntX ; ++i )
    add( S, i, 0, deg[i] );
  for( int i = n ; i < cntY ; ++i )
    add( i , T, 0, deg[i] );
  // cout << cntX << ' ' << cntY << ' ' << n << endl;
  int ans = 0;
  int mf(0);
  for(;;)
    {
      memset( dis, 1 << 6, sizeof(dis) );
      int inf = dis[T];
      dis[S] = 0;
      in[S] = true;
      que.push(S);
      for(; !que.empty() ;)
	{
	  int v = que.front();
	  in[v] = false;
	  que.pop();
	  for( int i = s[v]; i ; i = edge[i][2] )
	    if( edge[i][1] > 0 )
	      {
		int t = edge[i][0];
		int d = dis[v] + edge[i][3];
		if( d < dis[t] )
		  {
		    dis[t] = d;
		    from[t][0] = v;
		    from[t][1] = i;
		    if( !in[t] )
		      {
			in[t] = true;
			que.push(t);
		      }
		  }
	      }
	}
      if( dis[T] < inf )
	{
	  for( int i = T; i != S ; i = from[i][0] )
	    {
	      int usdE = from[i][1];
	      --edge[ usdE ][1];
	      ++edge[ usdE + ( ( usdE & 1 ) ? 1 : -1 ) ][1];
	    }
	  ans += dis[T];
	}
      else break;
      ++mf;
    }
  // cout << mf << endl;
  return ans;
}
int main()
{
  class SpecialCells a;
  vector<int> x ;
  vector<int> y ;
  // int xx[] = {1,2,1,2,1,2};
  // int yy[] = {1,2,3,1,2,3};
  // int xx[] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9};
  // int yy[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3};
  int xx[] = {1,100000};
  int yy[] = {1,100000};
 for( int i = 0 ; i < sizeof(xx) / sizeof(xx[0]); ++i )
    x.push_back( xx[i] ), y.push_back( yy[i] );
  cout << a.guess(x, y) << endl;
  return 0;
}
