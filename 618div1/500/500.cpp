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
class LongWordsDiv1
{
public:
  int count(int n);
};
const int N = 5007;
const int MOD = 1e9 + 7;
int dp[N];
int addM( int a, int b)
{
  return ( (ll)a + (ll)b ) % MOD;
}
int subM( int a, int b)
{
  return ( ( ( (ll)a - (ll)b ) % MOD ) + MOD ) % MOD;
}
int mulM( int a, int b)
{
  return ( (ll)a * (ll)b ) % MOD;
}
int LongWordsDiv1::count(int n)
{
  dp[1] = 1;
  for( int i = 2; i <= n; ++i )
    {
      dp[i] = dp[ i - 1 ];
      for( int j = 1; j < i - 1; ++j )
	{
	  dp[i] = addM( dp[i], mulM( dp[ i - 1 - j ], dp[j] ) );
	}
    }
  for( int i = n; i > 1; --i )
    dp[n] = mulM( dp[n], i);
  return dp[n];
}
int main()
{
  LongWordsDiv1 a;
  cout << a.count(100) << endl;
  return 0;
}
