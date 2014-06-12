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
class CatchTheBeat
{
public:
  int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset);
};
int CatchTheBeat::maxCatched(int n, 
	       int x0, int y0, int a, int b, int c, int d, 
	       int mod1, int mod2, int offset)
{
  vector<int> x, y;
  x.push_back( x0 ), y.push_back( y0 );
  for( int i = 1; i < n; ++i )
    {
      x.push_back( ( (ll)x[ i - 1 ] * a + b ) % mod1 );
      y.push_back( ( (ll)y[ i - 1 ] * c + d ) % mod2 );
    }
  for( auto & i : x )
    i -= offset;
  vector<pair<int,int> > xy;
  map<int,int> mp;
  for( int i = 0; i < n; ++ i )
    {
      if( x[i] + y[i] >= 0 && y[i] - x[i] >= 0 )
	{
	  xy.push_back( make_pair( x[i] + y[i], y[i] - x[i] ) );
	  mp[ y[i] - x[i] ] = 0;
	}
    }
  int cnt(0);
  for( auto & i : mp )
    i.second = ++cnt;
  sort( xy.begin(), xy.end() );
  int ans(0);
  map<int,int> mapp;
  mapp[0] = 0;
  for( int i = 0; i < xy.size(); )
    {
      int j = i;
      for( ; j < xy.size() && xy[i].first == xy[j].first; ++j )
	{
	  int z = mp[ xy[j].second ];
	  auto ite = mapp.upper_bound( z );
	  if( ite != mapp.begin() )
	    --ite;
	  int t = ite->second + 1;
	  ans = max( ans, t );
	  mapp[z] = max( mapp[z], t);
	  ite = mapp.find(z);
	  ++ite;
	  // cout << ans << endl;
	  for( ; ite != mapp.end(); )
	    {
	      if( ite->second <= t )
		{
		  auto ii = ite;
		  ++ite;
		  mapp.erase(ii);
		}
	      else break;
	    }
	}
      i = j;
    }
  return ans;
}
int main()
{
// 100
// 0
// 0
// 1
// 1
// 1
// 1
// 3
// 58585858
  CatchTheBeat a;
  cout << a.maxCatched(100, 0, 0, 1, 1, 1, 1, 3, 58585858, 1);
  return 0;
}
