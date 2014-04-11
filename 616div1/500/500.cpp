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
class ColorfulCoins
{
public:
  int minQueries(vector<long long> values);
};
int ColorfulCoins::minQueries(vector<long long> values)
{
  map<ll, int> mapp;
  for( int i = 0; i < values.size() - 1; ++i )
    ++mapp[ values[ i + 1 ] / values[i] ];
  int ans = 1;
  ll lc = 1, left = 0;
  int n = values.size();
  for( auto i : mapp )
    {
      if( left >= i.second )
	left -= i.second;
      else
	{
	  i.second -= left;
	  ll c = 1;
	  for( int j = 0; j < ans ; ++j )
	    {
	      c *= i.first;
	      if( c - lc > n )
		return ans;
	    }
	  for( ; c - lc < i.second; ++ans)
	    c *= i.first;
	  left = c - lc - i.second;
	  lc = c;
	}
      // cout << i.first << ' ' << i.second << ' ' << ans << ' ' << left << endl;
    }
  return ans;
}
int main()
{
  // ll a[] = {1, 2, 6, 30, 90, 270, 810, 2430, 7290, 29160, 87480, 262440, 
  // 	     787320, 3149280, 9447840, 28343520, 56687040, 170061120, 
  // 	     510183360, 1530550080, 3061100160, 9183300480, 27549901440,
  // 	     82649704320, 247949112960, 1239745564800, 3719236694400,
  // 	     14876946777600, 44630840332800, 223154201664000, 669462604992000,
  // 	     2008387814976000, 6025163444928000, 12050326889856000, 
  // 	     24100653779712000, 72301961339136000, 289207845356544000, 
  // 	     867623536069632000};
  ll a[] = {1};
  vector<ll> aa;
  for( int i = 0; i < sizeof( a ) / sizeof( a[0] ); ++i )
    aa.push_back( a[i] );
  ColorfulCoins aaa;
  cout << aaa.minQueries(aa) << endl;
  return 0;
}
