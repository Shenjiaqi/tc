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
const int N = 37;
const int K = 37;
const int C = 107;
int dp[N][N];
vector<int> ch[N];
int k;
bool cmp( int a, int b)
{
  int ia = 1;
  for( ; ia + 1 < k && dp[a][ia] == dp[a][ia + 1]; ++ia)
    ;
  int ib = 1;
  for( ; ib + 1 < k && dp[b][ib] == dp[b][ib + 1]; ++ib)
    ;
  return ia < ib;
}
int GoodCompanyDivOne::minimumCost(vector <int> su, 
				   vector <int> tr)
{
  int n = su.size();
  k = tr.size();
  sort( tr.begin(), tr.end() );
  for( int i = n - 1; i >= 0; --i )
    {
      sort( ch[i].begin(), ch[i].end(), cmp );
      for( int j = 1; j < k; ++j )
	{
	  dp[i][j] = tr[j] + tr[0];
	  if( j == 1 )
	    {
	      for( int l = 0; l < ch[i].size(); ++l )
		{
		  if( l + 1 >= k )
		    return -1;
		  dp[i][j] += dp[ ch[i][l] ][l + 1];
		}
	    }
	  else
	    {
	      for( int l = 0; l < min( (int)ch[i].size(), 2); ++l )
		dp[i][j] += dp[ ch[i][l] ][1];
	      for( int l = 2, m = 2; l < ch[i].size(); ++l, ++m )
		{
		  if( m == j )
		    ++m;
		  if( m >= k )
		    return -1;
		  dp[i][j] += dp[ ch[i][l] ][m];
		}
	    }
	}
      if( i > 0 )
	ch[ su[i] ].push_back(i);
    }
  int ans = N * C;
  for( int i = 1; i < k; ++i )
    ans = min( ans, dp[0][i] );
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
