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
class MyLongCake
{
public:
  int cut(int n);
};
int m[1<<20];
bool v[100007];
int MyLongCake::cut(int n)
{
  int num(0);
  for( int i = 2; i <= n; ++i )
    {
      if( !v[i] && ( n % i ) == 0 )
	{
	  m[ 1 << num ] = i;
	  ++num;
	  for( ll j = (ll)i * i; j <= n; j += i )
	    v[j] = true;
	}
    }
  m[0] = 1;
  int ans(0);
  for( int i = 1; i < ( 1 << num ); ++i )
    {
      int t = i & (- i);
      m[i] = m[ i ^ t ] * m[t];
      int tmp = n / m[i];
      if( __builtin_popcount(i) & 1 )
	ans += tmp;
      else ans -= tmp;
    }
  return ans;
}
int main()
{
  MyLongCake a;
  cout << a.cut(15) << endl;
  return 0;
}
