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
struct e
{
  int gt['z' - 'a' + 1];
  int pre, len, cnt;
  bool ed;
};
const int N = 100007;
e p[N * 2];
int lst, poi;
char s[N];
void add( int v )
{
  ++lst;
  memset( &p[lst], -1, sizeof( p[lst] ) );
  p[lst].len = p[poi].len + 1;
  p[lst].ed = true;
  p[lst].cnt = 0;
  int i = poi;
  poi = lst;
  for(; i >= 0 && p[i].gt[v] < 0; i = p[i].pre )
    p[i].gt[v] = lst;
  if( i < 0 )
    {
      p[poi].pre = 0;
    }
  else
    {
      int j = p[i].gt[v];
      if( p[j].len == p[i].len + 1 )
	{
	  p[poi].pre = j;
	  // ++p[j].cnt;
	}
      else
	{
	  ++lst;
	  memcpy( &p[lst], &p[j], sizeof( p[lst] ) );
	  p[lst].len = p[i].len + 1;
	  p[lst].ed = false;
	  p[poi].pre = p[j].pre = lst;
	  for( ; i >= 0 && p[i].gt[v] == j; i = p[i].pre )
	    {
	      p[i].gt[v] = lst;
	    }
	}
    }
}
void init()
{
  memset( &p[0], -1, sizeof(p[0]) );
  p[0].ed = true;
  p[0].len = 0;
  p[0].cnt = 0;
  lst = poi = 0;
}
int main()
{
  scanf("%s", s);
  init();
  for( int i = 0; s[i]; ++i )
    {
      add( s[i] - 'a');
    }
  for( int i = lst; i > 0; --i )
    {
      ++p[i].cnt;
      int pre = p[i].pre;
      p[pre].cnt += p[i].cnt;
    }
  cout << "!" << p[3].cnt << ' ' << p[6].cnt << ' ' << p[9].cnt << lst << endl;
  // for( int i = 0; i <= lst; ++i )
  //   {
  //     for( int j = 0; j < 'z' - 'a' + 1; ++j )
  // 	if( p[i].gt[j] >= 0 )
  // 	  {
  // 	    cout << "C_" << i << " -> C_" << p[i].gt[j] ;
  // 	    cout << "[ label = \"" << (char)(j + 'a') << "\" ];" << endl;
  // 	  }
  //     if( i != 0 )
  // 	cout << "C_" << i << " -> C_" << p[i].pre << "[ style = dotted ];" << endl;
  //   }
  scanf("%s", s );
  int maxLen(0);
  for( int i(0), len(0), idx(0); s[i]; ++i )
    {
      int tmp = s[i] - 'a';
      if( p[idx].gt[tmp] >= 0 )
	{
	  idx = p[idx].gt[tmp];
	  ++len;
	}
      else
	{
	  for( ; idx >= 0 && p[idx].gt[tmp] < 0; idx = p[idx].pre )
	    ;
	  if( idx >= 0 )
	    {
	      len = min( len, p[idx].len ) + 1;
	      idx = p[idx].gt[tmp];
	    }
	  else
	    {
	      len = 0;
	      idx = 0;
	    }
	}
      printf("%d %d %d %d\n", i, len, idx, p[idx].cnt );
      maxLen = max( maxLen, len );
    }
  printf("%d", maxLen);
  return 0;
}
