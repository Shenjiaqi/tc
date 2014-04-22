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
class PieOrDolphin
{
public:
  vector <int> Distribute(vector <int> choice1, vector <int> choice2);
};
const int N = 57;
const int M = 1007;
int s[N];
int du[N];
int p[M * 2][3], poi;
int ans[M];
vector<int> c1, c2;
void add( int f, int t, int id )
{
  ++poi;
  ++du[f];
  p[poi][0] = t, p[poi][1] = id, p[poi][2] = s[f], s[f] = poi;
}
void dfs( int v)
{
  for( ; s[v] && p[s[v]][0] < 0; s[v] = p[s[v]][2] )
    ;
  int tmp = s[v];
  s[v] = p[tmp][2];
  --du[v];
  int id = p[tmp][1];
  ans[id] = c1[id] == v ? 1 : 2;
  int t = p[tmp][0];
  --du[t];
  int pir = tmp + ( tmp & 1 ? 1 : -1 );
  p[pir][0] = -1;
  if( du[t] & 1 )
    dfs( t );
}
void dfs2( int v )
{
  for( ; s[v]; )
    {
      int tmp = s[v];
      s[v] = p[s[v]][2];
      int t = p[tmp][0];
      if( t >= 0 )
	{
	  int id = p[tmp][1];
	  ans[id] = ( c1[id] == v ? 1 : 2 );
	  --du[v];
	  int pir = tmp + ( tmp & 1 ? 1 : -1 );
	  p[pir][0] = -1;
	  --du[t];
	  dfs2(t);
	}
    }
}
vector <int> PieOrDolphin::Distribute(vector <int> choice1, 
				      vector <int> choice2)
{
  int n = choice1.size();
  for( int i = 0; i < n; ++i )
    {
      int a = choice1[i], b = choice2[i];
      add( a, b, i );
      add( b, a, i );
    }
  c1 = choice1;
  for( int i = 0; i < 50; ++i )
    for( ; du[i] & 1; )
      {
	dfs(i);
	// cout << "!" << endl;
      }
  for( int i = 0; i < 50; ++i )
    for( ; du[i]; )
      dfs2(i);
  vector<int> r;
  for( int i = 0; i < n; ++i )
    {
      cout << ans[i] << ' ';
      r.push_back( ans[i] );
    }
  return r;
}
int main()
{
  class PieOrDolphin a;
  // int c1[] = {10, 20, 10};
  // int c2[] = {20, 30, 20};
  // int c1[] = {0, 1, 2, 3, 5, 6, 7, 8};
  // int c2[] = {8, 7, 6, 5, 3, 2, 1, 0};
  int c1[] = {49, 0, 48, 1};
  int c2[] = {3, 4, 5, 6};
  vector<int> cc1, cc2;
  for( int i = 0; i < sizeof( c1 ) / sizeof( c1[0] ); ++i )
    cc1.push_back( c1[i] ), cc2.push_back( c2[i] );
  a.Distribute( cc1, cc2 );
  return 0;
}
