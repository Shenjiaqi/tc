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
class MinimumSquare
{
public:
  long long minArea(vector <int> x, vector <int> y, int K);
};
vector<int> xx, yy;
bool test( ll len , int K,
	   const vector<int> &x, const vector<int> &y)
{
  for( auto i : xx )
    for( auto j : yy )
      {
	int cnt = 0;
	for( int k = 0; k < x.size() ; ++k )
	  if( x[k] > i && y[k] > j &&
	      x[k] < i + len && y[k] < j + len )
	    {
	      ++cnt;
	      if( cnt >= K )
		return true;
	    }
      }
  return false;
}
long long MinimumSquare::minArea(vector <int> x, vector <int> y, int K)
{
  for( int i = 0; i < x.size(); ++i )
    for( int j = -1; j < 2; ++j )
      if( j )
	xx.push_back( x[i] + j ),
	  yy.push_back( y[i] + j ) ;
  sort( xx.begin(), xx.end() );
  sort( yy.begin(), yy.end() );
  int ansLen = 2e9 + 7;
  for( ll f = 0, t = 2e9 + 7; f <= t; )
    {
      int m = ( f + t ) / 2;
      if( test( m, K, x, y ) )
	{
	  t = m - 1, ansLen = m;
	}
      else f = m + 1;
    }
  return (ll)ansLen * (ll) ansLen;
}
int main()
{
  vector<int> x, y;
  int xx[] = {990000000, 990000000, 990000000, 1000000000, 1000000000};
  int yy[] = {1000000000, 0, -1000000000, 1000000000, -1000000000 };
  for( int i = 0 ;i < sizeof(xx) / sizeof( xx[0] ); ++i )
    x.push_back( xx[i] ),
      y.push_back( yy[i] );
  MinimumSquare a;
  cout << a.minArea( x, y, 4 );
  return 0;
}
