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
class RadioRange
{
public:
  double RadiusProbability(vector <int> X, vector <int> Y, vector <int> R, int Z);
};
double RadioRange::RadiusProbability(vector <int> x, 
				     vector <int> y, 
				     vector <int> r, int z)
{
  vector<ld> dis;
  int n = x.size();
  for( int i = 0; i < n; ++i )
    dis.push_back( sqrtl( (ll)x[i] * x[i] + (ll)y[i] * y[i] ) );
  vector< pair<ld, int> > rng;
  for( int i = 0; i < n; ++i )
    {
      ld d0 = max( (ld)0, dis[i] - (ld)r[i] );
      if( d0 <= z )
	{
	  rng.push_back( make_pair( d0, 0 ) );
	  ld d1 = min( (ld)z, dis[i] + (ld)r[i] );
	  rng.push_back( make_pair( d1, 1 ) );
	}
    }
  sort( rng.begin(), rng.end() );
  ld gRng(0);
  ld lastE(0);
  for( int i = 0, j = 0; i < rng.size(); ++i )
    {
      if( rng[i].second == 0 )
	{
	  if( j == 0 )
	    {
	      gRng += rng[i].first - lastE;
	    }
	  ++j;
	}
      else
	{
	  lastE = rng[i].first;
	  --j;
	}
    }
  if( lastE < z )
    gRng += (ld)z - lastE;
  return gRng / (ld)z;
}
int main()
{
  return 0;
}
