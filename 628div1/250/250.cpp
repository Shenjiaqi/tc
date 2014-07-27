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
class DivisorsPower
{
public:
  long long findArgument(long long n);
};
ll pow( ll a, int b)
{
  ll r = 1;
  for( ; b; b >>= 1, a *= a)
    if( b & 1 )
      r *= a;
  return r;
}
bool powLt( ll v, int b, ll lim )
{
  bool ok = v <= lim;
  for(ll val = 1; b; b >>= 1)
    {
      if( b & 1 )
	{
	  // if( !ok || v > lim || v * val > lim || val > lim ||
	  //     v * val < v )
	  if( !ok || ( lim / v ) < val )
	    return false;
	  val *= v;
	}
      if( v > 1e9 + 7 )
	{
	  ok = false;
	}
      v *= v;
    }
  return true;
}
ll sqr( ll n )
{
  ll r = 1;
  for( ll f = 1, t = n; f <= t; )
    {
      ll mid = ( f + t ) / 2;
      if( mid > n / mid )
	{
	  t = mid - 1;
	}
      else
	{
	  f = mid + 1;
	  r = mid;
	}
    }
  return r;
}
ll cal( ll n, int b )
{
  // r ^ b == n
  // b > 1
  ll r = 1;
  for( ll f = 1, t = sqr(n) + 1; f <= t; )
    {
      ll mid = ( f + t ) / 2;
      if( powLt( mid, b, n) )
	{
	  r = mid, f = mid + 1;
	}
      else
	{
	  t = mid - 1;
	}
    }
  return r;
}
ll DivisorsPower::findArgument(long long n)
{
  for( int po = 2; ; ++po )
    {
      ll num = cal( n, po );
      ll rnum = num;
      // cout << num << ' ' << n << ' ' << po << ' ' << endl;
      if( pow( num, po ) == n )
	{
	  int cnt(0);
	  ll tmp = sqr( num );
	  // cout << rnum << ' ' << cnt << ' ' << po << endl;
	  for( ll i = 1; i <= tmp && cnt <= po ; ++i )
	    {
	      if( ( num % i ) == 0 )
		{
		  ++cnt;
		  if( num != i * i )
		    ++cnt;
		}
	    }
	  if( po == cnt )
	    return rnum;
	}
      if( num <= 2 )
	return -1;
    }
}
int main()
{
  DivisorsPower a;
  cout << a.findArgument(2498388559757689LL) << endl;
  return 0;
}
