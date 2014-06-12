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
vector<pair<int,int> > dp[N];
multiset<int, greater<int> > sett;
int ans, kk;
bool same;
void ddfs( int v, int from, int lev, int md, int sum )
{
  if( lev == p[v].size() )
    {
      int tAns = sum;
      if( !sett.empty() )
	{
	  for(auto i =sett.begin() ; tAns < ans; )
	    {
	      ++tAns;
	      auto j = i;
	      ++j;
	      if( j == sett.end() )
		break;
	      if( *i + *j <= kk )
		break;
	      i = j;
	    }
	}
      else if( md < 0 )
	{
	  ++tAns;
	}
      // if( v == 4 && md == 5 )
      // 	cout << sum << ' ' << *sett.begin() << ' ' << tAns << endl;
      ans = min( ans, tAns);
    }
  else
    {
      int t = p[v][lev].first;
      if( t != from )
	{
	  for( int i = 0; i < dp[t].size(); ++i )
	    {
	      int tDis = dp[t][i].first;
	      bool need = false;
	      bool setSame = false;
	      if( tDis == md )
		{
		  if( same )
		    {
		      if( tDis > kk - md )
			need = true;
		    }
		  else same = setSame = true;
		}
	      else if( tDis > md || tDis > kk - md )
		need = true;
	      if( need )
		sett.insert( tDis );
	      ddfs( v, from, lev + 1, md, sum + dp[t][i].second );
	      if( need )
		sett.erase( sett.find( tDis ) );
	      if( setSame )
		same = false;
	    }
	}
      else
	ddfs( v, from, lev + 1, md, sum);
    }
}
void dfs( int v, int from, const int &md )
{
  for( int i = 0; i < p[v].size(); ++i )
    {
      int t = p[v][i].first;
      if( t != from )
	{
	  dfs( t, v, md);
	}
    }
  vector<int> lst;
  lst.push_back(-1);
  lst.push_back(0);
  for( int i = 0; i < p[v].size(); ++i )
    {
      int t = p[v][i].first;
      if( t != from )
	{
	  int dis = p[v][i].second;
	  for( int j = 1; j < dp[t].size(); ++j )
	    {
	      int tDis = dis + dp[t][j].first;
	      if( tDis > md )
		{
		  dp[t].resize( j );
		  break;
		}
	      dp[t][j].first = tDis;
	      lst.push_back( tDis );
	    }
	}
    }
  sort( lst.begin(), lst.end() );
  lst.resize( unique( lst.begin(), lst.end() ) - lst.begin() );
  for( int i = 0; i < lst.size(); ++i )
    {
      ans = inf;
      ddfs( v, from, 0, lst[i], 0);
      dp[v].push_back( make_pair( lst[i], ans ) );
    }
}
int Ethernet::connect(vector <int> par, vector <int> dst, int md)
{
  kk = md;
  int n = par.size() + 1;
  for( int i = 1; i < n; ++i )
    {
      int a = i;
      int b = par[ i - 1 ];
      p[a].push_back( make_pair( b, dst[ i - 1 ] ) );
      p[b].push_back( make_pair( a, dst[ i - 1 ] ) );
    }
  dfs( 0, 0, md );
  return dp[0][0].second;
}
int main()
{
  Ethernet a;
  // int b[] = {0, 0, 0};
  // int c[] = {1, 1, 1};

  // int b[] = {0,0,0,0,0,0,0};
  // int c[] = {1,2,3,4,5,6,7};

  int b[] = {0,1,2,3,4,5};
  int c[] = {1,2,3,4,5,6};

  // int b[] = {0,1,0,3,0,5,0,6,0,6,0,6,4,6,9,4,5,5,2,5,2};
  // int c[] = {93,42,104,105,59,73,161,130,30,81,62,93,131,
  // 	     133,139,5,13,34,25,111,4};

  // int b[] = {0,0,0,1,1};
  // int c[] = {1,1,1,1,1};
  vector<int> bb, cc;
  for( int i = 0; i < sizeof(b) / sizeof(b[0]); ++i )
    bb.push_back( b[i] ),
      cc.push_back( c[i] );
  cout << a.connect( bb, cc, 6 ) << endl;
  for( auto i : dp[4] )
    cout << i.first << ' ' << i.second << endl;
  return 0;
}
