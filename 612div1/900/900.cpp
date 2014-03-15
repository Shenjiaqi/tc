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
const int maxN = 1e6 + 7;
vector<int> posL;
class LeftAndRightHandedDiv1
{
 public:
  long long countSwaps(string Y, int A, int B, int C, int D, int N);
};
int dL( int to, int from, int n)
{
  int pT = posL[to];
  int pF = posL[from];
  if( pT <= pF )
    return pF - pT - ( from - to );
  return pF + n - pT - ( from + posL.size() - to );
}
int dR( int to, int from, int n )
{
  int pT = posL[to];
  int pF = posL[from];
  if( pT >= pF )
    return pT - pF - ( to - from );
  return pT + n - pF - ( to + posL.size() - from );
}
long long LeftAndRightHandedDiv1::countSwaps(string Y, int A, int B, int C, int D, int N)
{
  for( int i = 0 ; i < N ; ++i )
    {
      char c = Y[ A % (int)Y.length() ];
      if( c == 'L' )
	posL.push_back(i);
      A = ( (ll)A * (ll)B + (ll)C ) % D;
    }
  if( posL.size() < 2 || posL.size() >= N - 1 )
    return 0;
  for( int i = 1; i < posL.size(); ++i )
    posL[i] -= posL[0];
  posL[0] = 0;
  // for( int  i = 1, j = 0; i < N; ++i )
  //   {
  //     passed[i] += passed[i - 1];
  //     if( posL[j] == i - 1 )
  // 	{
  // 	  ++passed[i];
  // 	  if( j < posL.size() )
  // 	    ++j;
  // 	}
  //   }
  ll cnt(0);
  int dPos(0);
  for( int i = 0; i < posL.size(); ++i )
    {
      int d1 = dL( 0, i, N);
      int d2 = dR( 0, i, N);
      if( d1 <= d2 )
	{
	  cnt += d1;
	  dPos = i;
	}
      else
	{
	  cnt += d2;
	}
    }
  ll ans = (ll)1e17;
  // int id = 0;
  for( int i = 0 ; ; )
    {
      // if( ans > cnt )
      // 	id = i;
      ans = min( ans, cnt );
      if( i < posL.size() - 1 )
	{
	  int t1;
	  if( dPos >= i )
	    t1 = dPos - i ;
	  else t1 = dPos + posL.size() - i;
	  int t2 = posL.size() - t1;
	  cnt += (ll)( t2 - t1 ) * (ll)( posL[ i + 1 ] - posL[i] - 1 );
	  ++i;
	  if( dPos == i - 1 )
	    dPos = i;
	  for( ; dPos != i; 
	       dPos = ( dPos - 1 + posL.size() ) % posL.size() )
	    {
	      int t1 = dL( i, dPos, N );
	      int t2 = dR( i, dPos, N );
	      if( t1 > t2 )
		cnt += t2 - t1;
	      else break;
	    }
	  for( ; ( dPos + 1 ) % posL.size() != i; 
	       dPos = ( dPos + 1 ) % posL.size() )
	    {
	  // if( i % 10 == 0 && i > 264000)
	  //   // cout << i  << ' ' << posL.size() << endl;
	  //   cout << i << ' ' << dPos << ' ' << posL.size() << endl;
	      int t1 = dL( i, ( dPos + 1 ) % posL.size() , N );
	      int t2 = dR( i, ( dPos + 1 ) % posL.size() , N );
	      if( t1 < t2 )
		cnt += t1 - t2;
	      else break;
	    }
	}
      else break;
    }
  // ll vAns = 0;
  // cout << id << endl;
  // for( int i = 0 ; i < posL.size(); ++i )
  //   vAns += min( dL( id, i, N ), dR( id, i , N ) );
  // cout << "!" << vAns << endl;
  return ans;
}
int main()
{
  class LeftAndRightHandedDiv1 a;
  // a.countSwaps(string Y, int A, int B, int C, int D, int N);
  // cout << a.countSwaps("LR", 1, 0, 1, 2, 1);
  // cout << a.countSwaps("LRLR", 1, 1, 2, 3, 4);
  // cout << a.countSwaps("LRRLLR", 2, 3, 4, 5, 6);
  // cout << a.countSwaps("LRRLRLLRLRLRLLRLR", 12, 15, 3, 22, 10);
  // cout << a.countSwaps("LLLLLLLLL", 0, 1, 2, 3, 1000000);
  // cout << a.countSwaps("RLRRRLLLRLRLLRLRLLRLRLLLLLRRLRLRLRLRLLRRRLRRLLLLLRRRLRRLRLRRLLLLRLRRLRLRRLRRLRLLRRLRLRRRLRLLRLLLLRLLLLRLLRRLLRRRRLLRLLRLRLRRLL",
  // 		       48658960,
  // 		       221863772,
  // 		       385355602,
  // 		       393787970,
  // 		       980265);
  return 0;
}
