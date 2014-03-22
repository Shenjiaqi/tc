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
class RandomGCD
{
public:
  int countTuples(int N, int K, int low, int high);
};
const int D = 1e5 + 7;
const int mod = 1e9 + 7;
int cnt[D];
int addM( int a, int b)
{
  return ( a + b ) % mod;
}
int subM( int a, int b )
{
  return addM( ( a - b ) % mod, mod );
}
int mulM( ll a, ll b)
{
  return ( a * b ) % mod;
}
int powM( ll a, int b)
{
  int r = 1;
  for( ; b; b >>= 1, a = mulM( a, a ) )
    if( b & 1 )
      r = mulM( r, a );
  return r;
}
int choose( int num, int n )
{
  if( num == 0 )
    return 0;
  return powM( num, n );
}
int RandomGCD::countTuples(int N, int K, int low, int high)
{
  int left = ( low + K - 1 ) / K;
  int right = high / K;
  if( right == 0 )
    return 0;
  int num = right - left + 1;
  int ans = subM( choose( num, N ), num );
  for( int i = 2; i <= num; ++i )
    {
      int v = subM( cnt[i], 1);
      for( int j = i * 2; j <= num; j +=i )
	cnt[j] = subM( cnt[j], v );
      int num =  right / i - ( left + i - 1 ) / i + 1;
      int tmp = subM( choose( num, N ), num ) ;
      ans = addM( mulM( v, tmp ), ans );
    }
  if( low <= K && K <= high )
    ans = addM( ans, 1 );
  return ans;
}
int main()
{
  RandomGCD a;
  cout << a.countTuples( 2, 1, 5, 7) << endl;
  // cout << a.countTuples( 2, 2, 2, 4) << endl;
  // cout << a.countTuples( 2, 100, 2, 4) << endl;
  cout << a.countTuples( 222, 222, 222, 22222) << endl;
  return 0;
}
