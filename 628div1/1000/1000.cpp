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
class DoraemonPuzzleGame
{
public:
  double solve(vector <int> X, vector <int> Y, int m);
};
const int N = 2007;
ld p[N];
double DoraemonPuzzleGame:: solve(vector <int> x, vector <int> y, int m)
{
  int n = x.size();
  vector<ppi> z;
  for( int i = 0 ; i < n ; ++i )
    {
      z.push_back( make_pair( y[i], x[i] ) );
    }
  sort( z.begin(), z.end() );
  ld ans(0);
  memset( p, 0, sizeof(p) );
  p[0] = 1;
  ld c(0);
  for( int i = 0 ; i < n ; ++i )
    {
      ld xi = z[i].second, yi = z[i].first;
      ans += (ld)1000.0 / ( xi + yi );
      c += 1000.0 / (xi + yi );
      // cout << xi + yi << ' ' << ( 1000 / ( xi + yi ) ) << endl;
      for( int j = n; j >= 0 ; --j )
	{
	  if( j + 1 > 2 * n - m )
	    {
	      ld tmp = p[j] * (ld)1000.0 / yi * ( xi / ( xi + yi ) );
	      // cout << j << ' ' << p[j] << ' ' << 1000.0 / yi << ' '
	      // 	   << ( xi / (xi + yi ) ) << endl
	      // 	;
	      ans += tmp;
	    }
	  p[j] = ( j > 0 ? p[j - 1] * xi / (xi + yi ) : 0 ) + p[j] * yi / ( xi + yi );
	}
    }
  // cout << c << endl;
  return ans;
}

int main()
{
  DoraemonPuzzleGame a;
  // int x[] = {800};
  // int y[] = {200};
  // int m = 2;

  // int x[] = {1,999,999};
  // int y[] = {999,1,1};
  // int m = 3;

  // int x[] = {500,500};
  // int y[] = {500,500};
  // int m = 3;
  
  // int x[] = {250,250,250,250};
  // int y[] = {250,250,250,250};
  // int m = 5;

  // int x[] = {250,500,250};
  // int y[] = {500,250,500};
  // int m = 5;

  int x[] = {600,900,800,500,900,200,400,100,800,300,900,300,800,700,800,600,800,900,400,100,100,700,600,100,500,
	     800,700,600,900,600,300,100,300,100,700,500,900,200,800,400,300,700,300,400,700,300,400,800,300,200};
  int y[] = {400,100,200,500,100,800,600,900,200,700,100,700,200,300,200,400,200,100,600,900,900,300,400,900,500,
	     200,300,400,100,400,700,900,700,900,300,500,100,800,200,600,700,300,700,600,300,700,600,200,700,800};
  int m = 95;

  vector<int> X, Y;
  for( int i = 0 ; i < sizeof(x) / sizeof(x[0]) ; ++i )
    {
      X.push_back( x[i] );
      Y.push_back( y[i] );
    }
  cout << a.solve( X, Y, m );
  return 0;
}
