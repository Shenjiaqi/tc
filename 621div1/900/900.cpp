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
class StringsNightmareAgain
{
public:
  long long UniqueSubstrings(int a, int b, int c, int d, int n);
};
const int N = 1e5 + 7;
char s[N];
struct e
{
  int g[2];
  int pre;
  int len;
  int lft, rht;
  int cnt;
}p[N * 2];
int lst, poi;
void init()
{
  lst = poi = 0;
  memset( &p[0], -1, sizeof( p[0] ) );
  p[0].len = 0;
  p[0].lft = p[0].rht = 0;
  p[0].cnt = 0;
}
void add( int v, int pos )
{
  ++lst;
  memset( &p[lst], -1, sizeof( p[lst] ) );
  p[lst].len = p[poi].len + 1;
  p[lst].lft = p[lst].rht = pos;
  p[lst].cnt = 0;
  int i = poi;
  poi = lst;
  for( ; i >= 0 && p[i].g[v] < 0; i = p[i].pre )
    p[i].g[v] = lst;
  if( i < 0 )
    {
      p[poi].pre = 0;
    }
  else
    {
      int j = p[i].g[v];
      if( p[j].len == p[i].len + 1 )
	{
	  p[poi].pre = j;
	  ++p[j].cnt;
	}
      else
	{
	  ++lst;
	  memcpy( &p[lst], &p[j], sizeof( p[lst] ) );
	  p[lst].len = p[i].len + 1;
	  // --p[ p[j].pre ].cnt;
	  // cout << p[j].pre << ' ' << lst << "!" << endl;
	  p[j].pre = p[poi].pre = lst;
	  p[lst].cnt = 2;
	  for( ; i >= 0 && p[i].g[v] == j; i = p[i].pre )
	    {
	      p[i].g[v] = lst;
	    }
	}
    }
}
long long StringsNightmareAgain::UniqueSubstrings(int a, 
						  int b, 
						  int c, 
						  int d, 
						  int n)
{
  vector<int> val;
  val.resize(n);
  init();
  for( int i = 0; i < a; ++i )
    {
      b = ( (ll)b * (ll)c + d ) % n;
      val[b] = 1;
    }
  for( int i = 0; i < n; ++i )
    {
      add( val[i], i );
    }
  queue<int> que;
  for( int i = 1; i <= lst; ++i )
    {
      // cout << i << ' ' << p[i].pre << ' ' << p[i].cnt << endl;
      if( p[i].cnt == 0 )
  	que.push(i);
    }
  ll ans(0);
  cout << ' ' << p[9].cnt << endl;
  for( ; !que.empty(); que.pop() )
    {
      int j = que.front();
      int pre = p[j].pre;
      cout << ' ' << j << ' ' << pre << endl;
      if( 0 == --p[pre].cnt )
	que.push( pre );
      p[pre].rht = max( p[pre].rht, p[j].rht);
      int maxL = p[j].len;
      int minL = p[pre].len + 1;
      if( maxL == 2 && minL == 2 )
	cout << p[j].rht << ' ' << p[j].lft << endl;
      if( minL <= p[j].rht - p[j].lft )
	{
	  cout << j << ' ' << maxL << ' ' << minL << endl;
	  ans += min( p[j].rht - p[j].lft, maxL ) - minL + 1; 
	}
    }
  for( int i = 1; i <= lst; ++i )
    if( p[i].cnt != 0 )
      cout << i << endl;
  return ans;
}
int main()
{
  StringsNightmareAgain a;
  // cout << a.UniqueSubstrings( 0, 0, 0 , 0, 4) << endl;
  cout << a.UniqueSubstrings( 4, 3, 3 , 3, 10) << endl;
  return 0;
}
