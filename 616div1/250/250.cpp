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
class WakingUp
{
public:
  int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D);
};
int gcd( int a, int b)
{
  return b == 0 ? a : gcd( b, a % b );
}
const int inf = 57 * 10007 + 7;
int WakingUp::maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D)
{
  int ans = -1;
  int T = 1;
  for( auto i : period )
    T = T * i / gcd( i, T );
  for( int f = 0, t = inf * ( T + 17 ); f <= t; )
    {
      int m = ( (ll) f + t ) / 2;
      vector<int> s = start;
      for( int i = 1; i < 10 && m > 0; ++i )
	{
	  m += D;
	  for( int j = 0; j < s.size(); ++j )
	    if( s[j] == i )
	      m -= volume[j], s[j] += period[j];
	}
      if( m > 0 )
	{
	  int rm = m;
	  for( int i = 10; i < T + 10 && m > 0; ++i )
	    {
	      m += D;
	      for( int j = 0; j < s.size(); ++j )
		if( s[j] == i )
		  m -= volume[j], s[j] += period[j];
	    }
	  if( m < rm )
	    m = 0;
	}
      int tmp = ( (ll)f + t ) / 2;
      // if( tmp == 1 )
      // 	cout << m << endl;
      if( m <= 0 )
	ans = tmp, f = tmp + 1;
      else t = tmp - 1;
    }
  return ans >= inf * ( T + 17 ) ? -1 : ans;
}
int main()
{
  WakingUp tmp;
  vector<int> p, s, v;
  // int a[] = { 2, 3 };
  // int b[] = { 1, 2 };
  // int c[] = { 3, 4 };
  // int a[] = {9, 2, 5, 5, 7};
  // int b[] = {6, 1, 4, 1, 6};
  // int c[] = {71, 66, 7, 34, 6};
  int a[] = {7, 10, 7, 2, 9, 8, 6, 4, 2, 4, 3, 8, 1, 3, 6, 7, 5, 7, 2};
  int b[] = {1, 9, 7, 1, 7, 5, 4, 4, 1, 3, 3, 1, 1, 1, 3, 7, 2, 1, 1};
  int c[] = {21, 22, 27, 4, 19, 30, 8, 1, 24, 21, 28, 26, 20, 19, 17, 6, 3, 16, 20};
  for( int i = 0; i < sizeof( a ) / sizeof( a[0] ); ++i )
    p.push_back( a[i] ), s.push_back( b[i] ), v.push_back( c[i] );
  cout << tmp.maxSleepiness( p, s, v, 91 ) << endl;
  return 0;
}
