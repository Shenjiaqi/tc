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
class SixteenBricks
{
public:
  int maximumSurface(vector <int> height);
};
int SixteenBricks::maximumSurface(vector <int> height)
{
  sort( height.begin(), height.end() );
  int ans(16);
  for( int i = 0 ; i < height.size(); ++i )
    {
      if( i < 2 )
	ans -= height[i] * 4;
      else if( i < 6 )
	ans -= 2 * height[i];
      else if( i < 8 )
	;
      else
	ans += height[i] * 4;
    }
  return ans;
}

int main()
{
  // int a[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  // int a[] = {77, 78, 58, 34, 30, 20, 8, 71, 37, 74, 21, 45, 39, 16, 4, 59};
  int a[] ={1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2};
  vector<int> aa;
  for( int i = 0; i < sizeof(a) / sizeof(a[0]); ++i )
    aa.push_back( a[i] );
  SixteenBricks aaa;
  cout << aaa.maximumSurface(aa) << endl;
  return 0;
}
