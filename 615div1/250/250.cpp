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
class AmebaDiv1
{
public:
  int count(vector <int> X);
};
int AmebaDiv1::count(vector <int> X)
{
  set<int> inX;
  int maxX(0);
  for( auto i : X )
    {
      inX.insert( i );
      maxX = max( maxX, i);
    }
  int ans = inX.size();
  set<int> addEd;
  for( auto i : inX )
    {
      ll t = i;
      for( auto j : X )
	if( t > maxX )
	  break;
	else if( t == j )
	  t <<= 1;
      if( inX.find( t ) != inX.end() && addEd.find(t) == addEd.end() )
	{
	  --ans;
	  addEd.insert(t);
	//cout << t << ' ' << i << endl;}
	}
    }
  return ans;
}
