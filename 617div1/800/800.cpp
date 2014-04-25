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
class FarStrings
{
public:
  vector <string> find(string t);
};
const int N = 26;
const int inf = 1e9;
bool in[N];
int dp[N][N];
int test( const string & a, const string &b, int pos )
{
  int n = a.size();
  for( int i = pos; i <= n; ++i )
    for( int j = 1; j <= n; ++j )
      dp[i][j] = min( dp[i - 1][ j - 1 ] + ( a[i - 1] == b[j - 1] ? 0 : 1 ),
		      min( dp[i - 1][j], dp[i][j - 1] ) + 1 );
  return dp[n][n];
}
int test2( const string & a, const string &b, int pos )
{
  int n = a.size();
  for( int i = pos; i <= n; ++i )
    for( int j = 1; j <= n; ++j )
      dp[i][j] = min( dp[ i - 1 ][ j - 1 ],
		      min( dp[ i - 1 ][j], dp[i][ j - 1 ] ) + 1 );
  return dp[n][n];
}
vector <string> FarStrings::find(string t)
{
  int n = t.size();
  for( int i = 0; i < n; ++i )
    in[ t[i] - 'a' ] = true;
  int notIn(0);
  for( int i = 0; ; ++i )
    if( !in[i] )
      {
	notIn = i;
	break;
      }
  vector<string> ans;
  for( int i = 0; i <= n; ++i )
    dp[i][0] = dp[0][i] = i;
  for( int i = 1; i <= n; ++i )
    {
      string s, s2;
      for( int j = 0; j < n; ++j )
	s.push_back( notIn + 'a' );
      s2 = t;
      for( int j = 0; j < n; ++j )
	for( int k = 0; k < N; ++k )
	  {
	    s2[j] = s[j] = k + 'a' ;
	    int tmp = test( s, t, j + 1);
	    int tmp2 = test( s2, t, j + 1);
	    // if( i == 1 && j ==  )
	    //   cout <<
	    if( ( ( j != n - 1 && tmp >= i ) ||
		  tmp == i ) && ( j == n - 1 || tmp2 <= i ) )
	      break;
	  }
      cout << s << endl;
      ans.push_back(s);
    }
  return ans;
}
int main()
{
  class FarStrings a;
  string t = "bcdab";
  a.find(t);
  return 0;
}
