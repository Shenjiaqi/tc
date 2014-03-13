#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <unordered_set>
#include <tuple>
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
class EmoticonsDiv1
{
public:
  int printSmiles(int smiles);
};
const int N = 2e3 + 7;
int dp[N];
bool in[N];
int EmoticonsDiv1::printSmiles(int smiles)
{
  memset( dp, 1 << 6, sizeof(dp) );
  int inf = dp[0];
  dp[1] = 0;
  queue<int> que;
  que.push(1);
  in[1] = true;
  for( ; !que.empty(); )
    {
      int v = que.front();
      que.pop();
      in[v] = false;
      for( int num = 2 + dp[v], t = v * 2; t < N; ++num, t += v )
	{
	  if( dp[t] > num )
	    {
	      dp[t] = num;
	      if( !in[t] )
		{
		  in[t] = true;
		  que.push(t);
		}
	    }
	}
      for( int num = 1 + dp[v], t = v - 1; t > 0; ++num, --t )
	if( dp[t] > num )
	  {
	    dp[t] = num;
	    if( !in[t] )
	      {
		in[t] = true;
		que.push(t);
	      }
	  }
	else break;
    }
  return dp[smiles];
}
