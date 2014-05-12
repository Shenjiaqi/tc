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
#include <unordered_set>
#include <unordered_map>
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
class PairGame
{
public:
  int maxSum(int a, int b, int c, int d);
};
const int N = 1e6 + 7;
int PairGame::maxSum(int a, int b, int c, int d)
{
  unordered_set<ll> st;
  for( ; ; )
    {
      st.insert( (ll)a * (ll)N + b );
      if( a == 0 || b == 0 )
  	break;
      if( a >= b )
  	a -= b;
      else b -= a;
    }
  int ans(-1);
  for( ; ; )
    {
      if( st.find( (ll)c * (ll)N + d ) != st.end() )
  	{
  	  ans = c + d;
  	  break;
  	}
      if( c == 0 || d == 0 )
  	break;
      if( c >= d )
  	c -= d;
      else
  	d -= c;
    }
  return ans;
}
// int main()
// {
//   return 0;
// }
