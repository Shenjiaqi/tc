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
class CycleColoring
{
public:
  int countColorings(vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int K);
};
const int C = 1e6 + 7;
const ll mod = 1e9 + 7;
int mulM( ll a, ll b)
{
  return ( a * b ) % mod;
}
int addM( ll a, ll b )
{
  return ( a + b ) % mod;
}
int subM( ll a, ll b )
{
  return ( ( a % mod ) - ( b % mod ) + mod ) % mod;
}
void mulMat( int t[2][2], int f[2][2] )
{
  int t1[2][2], t2[2][2];
  memcpy( t1, t, sizeof( t1 ) );
  memcpy( t2, f, sizeof( t2 ) );
  for( int i = 0; i < 2; ++i )
    for( int j = 0; j < 2; ++j )
      t[i][j] = addM( mulM( t1[i][0], t2[0][j]),
		      mulM( t1[i][1], t2[1][j] ) );
}
void cal( int &t0, int &t1, int f0, int f1, int k, int num )
{
  int matrix[2][2];
  matrix[0][0] = k - 2, matrix[0][1] = k - 1;
  matrix[1][0] = 1, matrix[1][1] = 0;
  int r[2][2] = { { 1, 0}, { 0, 1 } };
  for( ; num; num >>= 1, mulMat( matrix, matrix) )
    if( num & 1 )
      mulMat( r, matrix);
  t0 = addM( mulM( r[0][0], f0 ), mulM( r[0][1], f1 ) );
  t1 = addM( mulM( r[1][0], f0 ), mulM( r[1][1], f1 ) );
}
void calP( int &a, int &b, int c1, int c2, int k )
{
  int tmp, tmp2, tmp3;
  cal( b, tmp, 0, 1, k, c1 + c2 - 1 );
  cal( tmp, tmp2, 0, 1, k, c1 );
  cal( tmp, tmp3, 0, 1, k, c2 );
  a = mulM( tmp2, tmp3);
}
int rev( int v )
{
  int r = 1;
  for( ll c = mod - 2; c; c >>= 1, v = mulM( v, v ) )
    if( c & 1 )
      r = mulM( r, v );
  return r;
}
int CycleColoring::countColorings(vector <int> vertexCount, 
				  vector <int> fromVertex, 
				  vector <int> toVertex, int K)
{
  int pre0 = 0, pre1 = K;
  int n = vertexCount.size();
  for( int i = 0; i < n ; ++i )
    {
      int tmp0, tmp1;
      int m = vertexCount[i];
      int c1 = ( toVertex[(i - 1 + n) % n] - fromVertex[i] + m ) % m;
      int c2 = m - c1;
      int p, q;
      calP( p, q, c1, c2, K);
      int v0, v1;
      cal( v0, tmp0, 0, pre0, K, m - 1 );
      cal( v1, tmp0, 0, pre1, K, m - 1 );
      tmp1 = addM( mulM( v1, mulM( p, rev( q ) ) ),
		   mulM( mulM( v0, mulM( subM( q, p ), rev( q ) ) ), 
			 rev( K - 1 ) ) );
      tmp0 = subM( addM( v0, v1 ), tmp1 );
      pre0 = tmp0, pre1 = tmp1;
      // int tmp0, tmp1;
      // int m = vertexCount[i];
      // int c = ( toVertex[(i - 1 + n) % n] - fromVertex[i] + m ) % m;
      // cal( tmp0, tmp1, pre[0], pre[1], K, c );
      // c = m - c - 1;
      // int tt;
      // cal( pre[0], tt, tmp0, 0, K, c );
      // cal( pre[1], tt, 0, tmp1, K, c );
    }
  return pre1;
}
int calDp( int num, int K )
{
  int dp[1000][2];
  dp[0][1] = 8, dp[0][0] = 0;
  for( int i = 1; i <= num; ++i )
    {
      dp[i][0] = addM( mulM( K - 1, dp[ i - 1 ][1] ),
		       mulM( K - 2, dp[ i - 1 ][0] ) );
      dp[i][1] = dp[ i - 1 ][0];
    }
  return dp[num][1];
}
int main()
{
  vector<int> vC, fV, tV;
  // int a[] = {3, 3};
  // int b[] = {0, 0};
  // int c[] = {0, 0};

  // int a[] = {6};
  // int b[] = {4};
  // int c[] = {1};

  // int a[] = {3, 3};
  // int b[] = {0, 1};
  // int c[] = {1, 2};

  // int a[] = {4, 4};
  // int b[] = {2, 2};
  // int c[] = {0, 0};

  // int a[] = {9, 5};
  // int b[] = {8, 3};
  // int c[] = {0, 2};

  // int a[] = {14, 15, 16, 17};
  // int b[] = {5, 10, 4, 6};
  // int c[] = {10, 3, 14, 10};
  int a[] = {482373, 283712, 883, 12834, 5, 5, 482734, 99912, 35881, 277590};
  int b[] = {59283, 49782, 0, 0, 3, 2, 84791, 40017, 2263, 461};
  int c[] = {150173, 709, 11108, 0, 4, 7, 5902, 712, 190232, 390331};
  for( int i = 0; i < sizeof(a) / sizeof( a[0] ); ++i )
    vC.push_back( a[i] ), fV.push_back( b[i] ), tV.push_back( c[i] );
  CycleColoring t;
  cout << t.countColorings( vC, fV, tV, 479360784) << endl;
  // cout << mulM( 8, mulM( calDp( 6, 8 ), calDp( 3, 8 ) ) ) << endl;
  return 0;
}
