#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <unordered_set>
#include <unordered_map>
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
const int N = 1e6 + 7;
queue<int> chgList[N];
int passed[N];
class LeftAndRightHandedDiv1
{
 public:
  long long countSwaps(string Y, int A, int B, int C, int D, int N);
};
long long LeftAndRightHandedDiv1::countSwaps(string Y, int A, int B, int C, int D, int N)
{
  vector<int> posL;
  for( int i = 0 ; i < N ; ++i )
    {
      char c = Y[ A % (int)Y.length() ];
      if( i > 0 )
	passed[i] += passed[ i - 1 ];
      if( c == 'L' )
	{
	  posL.push_back(i);
	  ++passed[ i + 1 ];
	}
      A = ( (ll)A * (ll)B + C ) % D;
    }
  if( posL.size() < 2 || posL.size() >= N - 1 )
    return 0;
  vector<int> dir;
  vector<int> dirList[2];
  ll cnt(0);
  for( int i = 0 ; i < posL.size(); ++i )
    {
      int pos = posL[i] - posL[0];
      int d1 = pos - i;
      int d2 = N - pos - 1 - ( posL.size() - i - 1);
      // cout << min( d1, d2 ) << endl;
      if( d1 <= d2 )
	{
	  cnt += d1;
	  dirList[0].push_back(i);
	}
      else
	{
	  cnt += d2;
	  dirList[1].push_back(i);
	}
    }
  for( int i = 0, j = 0 ; i < dirList[0].size(); ++i )
    {
      chgList[1].push( dirList[0][i] );
      j = max( j, i + 1 );
      for( ; j < n ; ++j )
	{
	  int d1 = 
	}
    }
  ll ans = (ll)1e19;
  int passed(0), on(0);
  for( int i = 0; i < N; ++i )
    {
      passed += on, on = 0;
      if( !dirList[0].empty() )
	{

	  int v = *dirList[0].begin();
	  if( posL[v] - posL[0] == i )
	    {
	      dirList[0].erase( dirList[0].begin() );
	      dirList[1].insert(v);
	      on = 1;
	    }
	}
      for( ; !dirList[1].empty(); )
	{
	  int v = *dirList[1].begin();
	  int pos = posL[v] - posL[0];
      // int d1 = pos - i;
      // int d2 = N - pos - 1 - ( posL.size() - i - 1);
	  int d1 = pos - i - ( v - passed - on );
	  int d2 = i + N - pos - 1 - ( posL.size() - v - passed );
	  cout << d1 << " " << d2 << endl;
	  if( d2 >= d1 )
	    {
	      dirList[1].erase( dirList[1].begin() );
	      dirList[0].insert(v);
	      if( d2 > d1 )
		cnt += d1 - d2;
	    }
	  else break;
	}
      ans = min( ans, cnt );
      cout << "!" << dirList[0].size() << ' ' << dirList[1].size() << endl;
      cnt += dirList[1].size() - dirList[0].size();
    }
  return ans;
}
int main()
{
  class LeftAndRightHandedDiv1 a;
  // a.countSwaps(string Y, int A, int B, int C, int D, int N);
  // cout << a.countSwaps("LR", 1, 0, 1, 2, 1);
  // cout << a.countSwaps("LRLR", 1, 1, 2, 3, 4);
  cout << a.countSwaps("LRRLLR", 2, 3, 4, 5, 6);
  return 0;
}
