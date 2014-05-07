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
class GoodCompanyDivOne
{
public:
  int minimumCost(vector <int> superior, vector <int> training);
};
const int N =37;
int GoodCompanyDivOne::minimumCost(vector <int> su, 
				   vector <int> tr)
{
  int n = su.size();
  int k = tr.size();
  vector<int > ch[N];
  int ans(0);
  sort( tr.begin(), tr.end() );
  for( int i = n - 1; i >= 0; --i )
    {
      sort( ch[i].begin(), ch[i].end() );
      int val = max( 1, (int)ch[i].size() );
      if( val + 1 > k )
	return -1;
      if( i )
	ch[ su[i] ].push_back(val);
      for( int j = 1; j < ch[i].size(); ++j )
	if( j + 1 > ch[i][j] )
	  ans += tr[ j + 1 ] - tr[ ch[i][j] ];
      ans += tr[1] + tr[0];
    }
  return ans;
}
int main()
{
  class GoodCompanyDivOne a;
  // int ss[] = {-1};
  // int tt[] = { 1, 2};
  // int ss[] = {-1, 0, 0};
  // int tt[] = {1, 2, 3};
  // int ss[] = {-1, 0, 0, 0};
  // int tt[] =  {1, 2, 3};
  int ss[] = {-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3};
  int tt[] = {4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4};
 vector<int> s, t;
  for( int i = 0; i < sizeof(ss) / sizeof(ss[0]); ++i )
    s.push_back( ss[i] );
  for( int i = 0; i < sizeof(tt) / sizeof(tt[0]); ++i )
    t.push_back( tt[i] );
  cout << a.minimumCost( s, t);
  return 0;
}
